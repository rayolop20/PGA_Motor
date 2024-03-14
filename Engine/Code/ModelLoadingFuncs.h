#ifndef MODEL_LOADING_FUNC
#define MODEL_LOADING_FUNC

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Globals.h"

namespace ModelLoader {

	struct VertexBufferAtribute
	{
		u8 location;
		u8 componentCount;
		u8 offset;
	};
	
	struct VertexBufferLayout
	{
		std::vector<VertexBufferAtribute> attributes;
		u8 stride;
	};

	struct VertexShaderAttribute
	{
		u8 location;
		u8 componentCount;
	};
	
	struct VertexShaderLayout
	{
		std::vector<VertexBufferAtribute> attributes;
	};
	struct VAO
	{
		GLuint handle;
		GLuint programHandle;
	};

}

#endif
