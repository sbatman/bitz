#pragma once
#include "../../Common.h"

namespace Bitz
{
	class Core;

	namespace GFX
	{
		class RenderEngine;
		namespace Shaders
		{
			class Shader;
			typedef std::shared_ptr<Shader> Shader_Ptr;

			class ShaderService
			{
				friend Shader;
				friend RenderEngine;
				friend Core;
			public:
				template <typename T>
				static std::shared_ptr<T> CreateShader()
				{
					auto shader = std::make_shared<T>();
					RegisterShader(shader);
					return shader;
				}

			private:
				static	std::vector<Shader_Ptr> _KnownShaders;
				static Shader_Ptr _StandardShader;
				static void RegisterShader(Shader_Ptr shaderInstance);
				static void UnRegisterShader(Shader_Ptr shaderInstance);
				static std::vector<Shader_Ptr> GetCurrentShaders();
				static Shader_Ptr GetStandardShader();
			};	
		}
	}
}