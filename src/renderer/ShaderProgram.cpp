#include "ShaderProgram.h"
#include "VertexArray.h"

#include <glm/ext.hpp>

namespace renderer
{
	ShaderProgram::ShaderProgram(std::string vert, std::string frag)
	{
		std::ifstream vertFile(vert);
		std::string vShaderText;

		if (vertFile.is_open())
		{
			std::string temp;

			while (std::getline(vertFile, temp))
			{
				vShaderText += temp;
				vShaderText.push_back('\n');
			}

			vertFile.close();
		}

		std::ifstream fragFile(frag);
		std::string fShaderText;

		if (fragFile.is_open())
		{
			std::string temp;

			while (std::getline(fragFile, temp))
			{
				fShaderText += temp;
				fShaderText.push_back('\n');
			}

			fragFile.close();
		}

		//const GLchar* vertShaderSrc = vShaderText.c_str();
		const GLchar* vertShaderSrc =
			"attribute vec3 in_Position;               " \
			"                                          " \
			"uniform mat4 u_Projection;                " \
			"uniform mat4 u_Model;                     " \
			"                                          " \
			"void main()                               " \
			"{                                         " \
			"   gl_Position = u_Projection * u_Model * vec4(in_Position, 1.0);  " \
			"}                                         ";

		//const GLchar* fragShaderSrc = fShaderText.c_str();
		const GLchar* fragShaderSrc = 
			"void main()                               " \
			"{                                         " \
			"   gl_FragColor = vec4(0, 0, 1, 1);        " \
			"}                                         ";

		GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderId, 1, &vertShaderSrc, NULL);
		glCompileShader(vertexShaderId);
		GLint success = 0;
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		GLuint fragShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShaderId, 1, &fragShaderSrc, NULL);
		glCompileShader(fragShaderId);
		glGetShaderiv(fragShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragShaderId, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(fragShaderId, maxLength, &maxLength, &errorLog.at(0));
			std::cout << &errorLog.at(0) << std::endl;
			throw std::exception();
		}

		id = glCreateProgram();
		glAttachShader(id, vertexShaderId);
		glAttachShader(id, fragShaderId);

		glBindAttribLocation(id, 0, "in_Position");

		glLinkProgram(id);
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success)
		{
			throw std::exception();
		}

		//GLint modelLoc = glGetUniformLocation(id, "u_Model");
		//GLint projectionLoc = glGetUniformLocation(id, "u_Projection");

		glDetachShader(id, vertexShaderId);
		glDeleteShader(vertexShaderId);
		glDetachShader(id, fragShaderId);
		glDeleteShader(fragShaderId);

		GLuint modelLoc = glGetUniformLocation(id, "u_Model");
		GLuint projectionLoc = glGetUniformLocation(id, "u_Projection");

		if (modelLoc == -1)
		{
			throw std::exception();
		}

		if (projectionLoc == -1)
		{
			throw std::exception();
		}
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(id);
	}

	void ShaderProgram::draw(std::shared_ptr<VertexArray> vertexArray)
	{
		glUseProgram(id);
		glBindVertexArray(vertexArray->getId());

		glDrawArrays(GL_TRIANGLES, 0, vertexArray->getVertCount());

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void ShaderProgram::setUniform(std::string name, glm::mat4 uniform)
	{
		glUseProgram(id);
		GLint loc = glGetUniformLocation(id, name.c_str());
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(uniform));
		glUseProgram(0);
	}

	void ShaderProgram::setUniform(float uniform)
	{
		glUseProgram(id);
		glUseProgram(0);
	}

	GLuint ShaderProgram::getId()
	{
		return id;
	}
}