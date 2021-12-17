#version 410

// Using Learn OpeGL's tutorial on PBR (Physically Based rendering)
// https://learnopengl.com/PBR/Theory
// https://learnopengl.com/PBR/Lighting

uniform mat4 u_View;
uniform sampler2D u_Texture;

uniform vec3 albedo = {1,1,1};
uniform float metallic = 0.0f;
uniform float roughness = 0.1f;
uniform float ao = 1.0f;

uniform vec3 camPos;

uniform vec3 lightPositions[4];
uniform vec3 lightColors[4];

in vec2 v_Texcoord;
in vec3 v_FragPos;
in vec3 v_Normal;

out vec4 FragColor;

const float PI = 3.14159265359;

// Works out the distribution of the lights
float DistributionGGX(vec3 N, vec3 H, float a)
{
	// Calculates the value of a squared
	float a2 = a * a;

	// Calculates the dot product of N & H using
	// the dot product function and max function provided by GLSL
	float NdotH = max(dot(N,H), 0.0);

	// Calculates the value of NdotH squared
	float NdotH2 = NdotH * NdotH;

	// Sets numerator value to a2
	float nom = a2;

	// Calculates the value for the denominator
	float denom = (NdotH2 * (a2 - 1.0) + 1.0);
	denom = PI * denom * denom;

	// Returns the value of the numerator / denominator 
	return nom / denom;
}

// Works out the reflectance of the object
float GeometrySchlickGGX(float NdotV, float roughness)
{
	// Uses the roughness value and sets it to the float value r
	float r = (roughness + 1.0);

	// Uses the float value r and times the value by itself
	// It will then divide the value by 8
	float k = (r * r) / 8.0;

	// Sets the dot product of N & V equal to the numerator
	float nom = NdotV;

	// Calculates the value of the denominator
	float denom = NdotV * (1.0 - k) + k;

	// Returns the value of the numerator / denominator
	return nom / denom;
}

float GeometrySmith(vec3 N, vec3 V, vec3 L, float k)
{
	// Calculates the dot product of N & V using
	// the dot product function and max function provided by GLSL
	float NdotV = max(dot(N, V), 0.0);

	// Calculates the dot product of N & L using
	// the dot product function and max function provided by GLSL
	float NdotL = max(dot(N, L), 0.0);

	// Calculates the values for ggx1 & ggx2
	float ggx1 = GeometrySchlickGGX(NdotV, k);
	float ggx2 = GeometrySchlickGGX(NdotL, k);

	// Returns the value for ggx1 * ggx2
	return ggx1 * ggx2;
}

// Calculates the fresnel effect
vec3 frenselSchlick(float cosTheta, vec3 F0)
{
	return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}

void main()
{
	// Normalizes the Normals position and frag positions
	vec3 N = normalize(v_Normal);
	vec3 V = normalize(camPos - v_FragPos);

	// F0 will be used alongside cosT to calculate 
	// the Fresnel effect
	vec3 F0 = vec3(0.04);
	F0 = mix(F0, albedo, metallic);

	// Initalizes the Lo value which will be used to 
	// calculate the value for pbr
	vec3 Lo = vec3(0.0);

	// Goes through each of the light positions and colors
	// to work out how the model should look
	for(int i = 0; i < 4; i++)
	{
		// Normalizes the L value using the lightPositions values
		// and frag position value
		vec3 L = normalize(lightPositions[i] - v_FragPos);

		// Normalizes the H value using the value for V and L
		vec3 H = normalize(V + L);

		// Calculates the distance between the lightPositions and frag positon
		float distance = length(lightPositions[i] - v_FragPos);

		// Used to work out the radiance value
		float attenuation = 1.0;

		// Uses lightColors and attenuation to calculate
		// the radiance value
		vec3 radiance = lightColors[i] * attenuation;

		// Calculates the values for the light distribution,
		// partial geometry and fresnel effect
		float NDF = DistributionGGX(N, H, roughness);
		float G = GeometrySmith(N, V, L, roughness);
		vec3 F = frenselSchlick(max(dot(H, V), 0.0), F0);

		// Sets kS to the value given by the fresnel effect function
		vec3 kS = F;

		// Uses the kS value and metallic to calculate
		// the value for kD
		vec3 kD = vec3(1.0) - kS;
		kD *= 1.0 - metallic;

		// Calculates the numerator and denominator using
		// values which were calculated earlier on in the function
		vec3 numerator = NDF * G * F;
		float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001;

		// Uses the numerator and denominator values to calculate the value for specular
		vec3 specular = numerator / denominator;

		// Calculates the value for NdotL using the max and dot product
		// functions provided by GLSL
		float NdotL = max(dot(N, L), 0.0);

		// Calculates the value for Lo 
		Lo += (kD * albedo / PI + specular) * radiance * NdotL;
	}

	// Works out the ambient value & color value
	vec3 ambient = vec3(0.03) * albedo * ao;
	vec3 color = ambient + Lo;

	color = color / (color + vec3(1.0));
	color = pow(color, vec3(1.0/1.2));

	// Sets the model color
	FragColor = vec4(color, 1.0);
}