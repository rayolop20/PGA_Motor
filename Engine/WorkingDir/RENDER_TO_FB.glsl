#ifdef RENDER_TO_FB

#if defined(VERTEX) ///////////////////////////////////////////////////

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;
//layout(location = 3) in vec3 aTangent;
//layout(location = 4) in vec3 aBitangent;




struct Light
{
	uint type;
	vec3 color;
	vec3 direction;
	vec3 position;
};

layout(binding = 0, std140) uniform GlobalParams
{
	vec3 uCameraPosition;
	uint uLightCount;
	Light uLight[16];
};


out vec2 vTexCoord;
out vec3 vPosition;
out vec3 vNormal;  
out vec3 vViewDir;  


layout(binding = 1, std140) uniform LocalParams
{
	mat4 uWorldMatrix;
	mat4 uWorldViewProjectionMatrix;
};

void main()
{
	vTexCoord = aTexCoord;

	vPosition = vec3(uWorldMatrix * vec4(aPosition,1.0));
	vNormal = vec3(uWorldMatrix * vec4(aNormal,0.0));
	vViewDir = uCameraPosition - vPosition;

	float clippingScale = 1.0;

	gl_Position = uWorldViewProjectionMatrix * vec4(aPosition, clippingScale);
}

#elif defined(FRAGMENT) ///////////////////////////////////////////////


struct Light
{
	uint type;
	vec3 color;
	vec3 direction;
	vec3 position;
};

layout(binding = 0, std140) uniform GlobalParams
{
	vec3 uCameraPosition;
	uint uLightCount;
	Light uLight[16];
};


in vec2 vTexCoord;
in vec3 vPosition;
in vec3 vNormal;  
in vec3 vViewDir;  

uniform sampler2D uTexture;

layout(location = 0) out vec4 oAlbedo;
layout(location = 1) out vec4 oNormals;
layout(location = 2) out vec4 oPosition;


void main()
{
	oAlbedo = texture(uTexture, vtextCoord);
	oNormals = vec4 (vNormals, 1.0);
	oPosition = vec4 (vPosition, 1.0);

}

#endif
#endif