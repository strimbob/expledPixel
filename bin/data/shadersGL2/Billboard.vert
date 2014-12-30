#version 120

uniform float  _startTween;
attribute float _startTweenOne;
uniform float scaleBen;
uniform float numPoints;
void main() {

    
    float red = 0.299*gl_Color.r;
    float blue = 0.587*gl_Color.b;
    float green = 0.114*gl_Color.g;
    vec4 eyeCoord = gl_ModelViewMatrix * gl_Vertex;

	gl_TexCoord[0] = gl_MultiTexCoord0;

    
    float xx = gl_Vertex.x;
    float yy = gl_Vertex.y;
    float zz = (red + blue + green)*numPoints;
    
    vec4 aaa = gl_ModelViewMatrix * vec4(xx,yy,zz,1.0);
	gl_Position = gl_ProjectionMatrix * aaa;
    gl_PointSize = 1;
	gl_FrontColor = gl_Color;
}










