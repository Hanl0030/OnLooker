varying vec4 v_Color;
varying vec2 v_TexCoords;

uniform vec3 u_Tint;

void main()
{
	vec4 tint = vec4(u_Tint, 1.0);
	gl_FragColor = v_Color * tint;//vec4 (0.0, 0.0, 1.0, 1.0);
}