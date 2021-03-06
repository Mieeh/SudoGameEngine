#pragma once

#include"../definitions.h"

// Forward declerations
namespace sudo {
	namespace math {
		class Matrix4x4;
		struct Vector2;
		struct Vector3;
		struct Vector4;
} }

namespace sudo { namespace graphics {

	class Shader {
	private:
		/* Shader program handle */
		uint m_shaderProgram;

		/* Checks a_shader's compile status */
		bool didCompile(uint a_shader);

		uint getUniformLocation(const char* a_name);

	public:
		/* Loads and compiles a shader program */
		/* Call bind() to install shader as part of the current rendering state*/
		Shader(const char* a_vertexPath, const char* a_fragmentPath);

		// Same as a_vertexPath but takes in the file data directly
		Shader(const char* a_vertexFileData, const char* a_fragmentFileData, int x);

		// Destructor 
		~Shader();

		// Creates shader
		void CreateShader(const char* a_vertexFileData, const char* a_fragmentFileData);

		/* Calls glUseProgram on this shader */
		/* glUseProgram � Installs a program object as part of current rendering state */
		void enable()		const;
		void disable()		const;

		/* glUniform methods */
		void setUniformMatrix4x4 (const GLchar *a_name, math::Matrix4x4& a_matrix);
		void setUniform1f		 (const GLchar *a_name, float value);
		void setUniform1fv		 (const GLchar *a_name, int count, float *value);
		void setUniform1iv		 (const GLchar *a_name, int count, int *value);
		void setUniform2f		 (const GLchar *a_name, const math::Vector2& vec);
		void setUniform3f		 (const GLchar *a_name, const math::Vector3& vec);
	};

} }