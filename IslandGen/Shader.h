#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Shader
{
private:
	unsigned int Program;
	std::unordered_map<std::string, int> UniformLocations;

	void CreateShader(std::string VertexShader, std::string FragmentShader);
	std::string ReadShaderFile(std::string FileName);
public:
	Shader(std::string VertexShader, std::string FragmentShader);
	Shader() {}
	~Shader();
	unsigned int GetUniformLocation(const std::string& UniformName);
	template<typename T>
	void Uniform(const std::string& UniformName, const T& Value);
	void UseProgram() const;
};
