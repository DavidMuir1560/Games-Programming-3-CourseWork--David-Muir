#pragma once

#include "GameConstants.h"
#include "TransformManager.h"
#include "CameraManager.h"
#include "LightManager.h"

class ShaderManager
{
private:
	static const int NUM_SHADER = 2; //The Number of Shaders in the Game
						
	enum                  //Enum Flags for setting Uniform Values
	{
		TRANSFORM_U,
		LPOS_U,
		SPOTDIR_U,
		NUM_UNIFORMS
	};


	GLuint ShaderProgram;                   //The Shader Program
	GLuint Shaders[NUM_SHADER];       //The Array for Holding Shaders
	GLuint Uniforms[NUM_UNIFORMS];    //The Array for Holding Uniforms

	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);    //Checks for any errors while loading the Shader
	static string LoadShader(const string& fileName);                                                        //Loads the Shader from File
	static GLuint CreateShader(const string& text, GLenum shaderType);                                       //Creates the Shader Program

	//methods for setting uniforms and binding attributes to the array
	void SetUniforms();       //Sets the Uniforms
	void AttachAttribs();     //Binds the Attributes to an Array

public:
	ShaderManager();	                    //Class Constructor
	ShaderManager(const string& fileName);  //Class Constructor
	~ShaderManager();                       //Class Destructor 


	void BindShader();	                                                                                //Binds the Game Shader
	void Update(const TransformManager& transform, const CameraManager& camera);                        //Updates the Shader based on the Transform and the Camera
	void Update(const TransformManager& transform, const CameraManager&, const LightManager& light);    //Updates the Shader based on the Transform, Camera and Light


};