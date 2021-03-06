attribute vec2 a_Position;
attribute vec4 a_Color;
attribute vec2 a_TexCoords;

uniform vec3 u_Tint;

varying vec4 v_Color;
varying vec2 v_TexCoords;

void main()
{
	gl_Position = vec4(a_Position ,0.0f ,1.0 );

	v_Color = a_Color;
	v_TexCoords = vec2(a_TexCoords);

}