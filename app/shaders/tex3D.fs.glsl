#version 320 es

#ifdef GL_ES
	precision mediump float;
	precision mediump int;
#endif

in vec2 vTexCoords;
in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
	fFragColor = texture(uTexture,vTexCoords).rgb;
//	fFragColor = vNormal.rgb;
};
