#ifdef GRID_SHADER

#if defined(VERTEX) ///////////////////////////////////////////////////

layout(location = 0) in vec3 aPosition;


void main()
{
	vTexCoord = aTexCoord;

	vPosition = vec3( uWorldMatrix * vec4(aPosition, 1.0));
	vNormal = vec3(uWorldMatrix * vec4(aNormal, 0.0));
	vViewDir = uCameraPosition - vPosition;
	
	float clippingScale = 1.0;

	gl_Position = uWorldViewProjectMatrix * vec4(aPosition, clippingScale);
}

#elif defined(FRAGMENT) ///////////////////////////////////////////////


uniform float left;
uniform float right;
uniform float bottom;
uniform float top;
uniform float znear;

uniform float worldmatrix;
uniform float viewmatrix;


void main()
{
	vec4 finalColor = vec4(0.0);

	vec3 eyerdirEyespace;
	eyerdirEyespace.x = left + vTexCoord.x * (right - left);
	eyerdirEyespace.y = bottom + vTexCoord.y * (top - bottom);
	eyerdirEyespace.z = -znear;

	vec3 eyeposEyespace = vec3(0.0);
	vec3 eyeposWorldspace = vec3(worldMatrix * vec4(eyeposEyespace ) );
	
	vec3 planeNormalWorldspace= vec3 (0.0,1.0,0.0);
	vec3 planePointWorldspace= vec3 (0.0);

	float nominator
	float denominator
	float t = numerator/ denominator;

	if(){
		vec3 hitWorldspace = eyeposWorld + eyedirWorldspace * t;
		finalColor = vec4(grid(hitWorldspace, 1.0))
	}
	else{
		gl_FragDepth = 0.0;
		discard;
	}

	oColor = finalColor;
}

#endif
#endif