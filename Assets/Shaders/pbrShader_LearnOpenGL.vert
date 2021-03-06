#version 410

// Using Learn OpenGL's tutorial on PBR (Physically Based rendering)

attribute vec3 in_Position;
attribute vec3 in_Normal;
attribute vec2 in_Texcoord;

uniform mat4 u_Projection;
uniform mat4 u_Model;
uniform mat4 u_View;

out vec2 v_Texcoord;
out vec3 v_FragPos;
out vec3 v_Normal;

void main()
{
	// Works out the value for the frag positions
	v_FragPos = vec3(u_Model * vec4(in_Position, 1.0));

	// Sets the gl_Position
	gl_Position = u_Projection * u_View * u_Model * vec4(in_Position, 1.0);

	// Sets the texture coordinates
	v_Texcoord = in_Texcoord;

	// Works out the Normals for the object
	v_Normal = vec3(u_Model * vec4(in_Normal, 0));
}