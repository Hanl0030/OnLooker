uniform sampler2D u_Texture1;
uniform sampler2D u_Texture2;
uniform float u_Translucency;

varying vec4 v_Color;
varying vec2 v_TexCoords;

uniform vec3 u_Tint;

void main()
{

	vec4 color1 = texture2D(u_Texture1, v_TexCoords);
	vec4 color2 = texture2D(u_Texture2, v_TexCoords);

	if(color1.a == 1.0)
	{
		gl_FragColor = color1;
	}
	else
	{
		//float translucency1 = float(1) - u_Translucency;
		//color1 *= translucency1;
		//color2 *= u_Translucency;
		gl_FragColor = color1;
	}
	
	
	
	
}