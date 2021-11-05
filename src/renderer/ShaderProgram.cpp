#include "ShaderProgram.h"
#include "VertexArray.h"

#include <glm/ext.hpp>

namespace renderer
{
	ShaderProgram::ShaderProgram()
	{
		const GLchar* vertShaderSrc =
			"attribute vec3 in_Position;               " \
			"                                          " \
			"void main()                               " \
			"{                                         " \
			"   gl_Position = vec4(in_Position, 1.0);  " \
			"}                                         ";

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