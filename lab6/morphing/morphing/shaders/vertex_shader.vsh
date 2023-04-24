float getCanabolaCoef(float x)
{
	return (1 + sin(x)) * (1 + 0.9 * cos(8 * x)) + (1 + 0.1 * cos(24 * x));
}

void main()
{
	vec4 position = gl_Vertex;
	
	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * position;
}