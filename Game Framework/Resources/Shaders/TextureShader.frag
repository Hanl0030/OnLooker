uniform sampler2D u_TexS1;


varying vec4 v_Color;
varying vec2 v_TexCoords;

uniform vec3 u_Tint;

void main()
{

	gl_FragColor = texture2D(u_TexS1, v_TexCoords);
}