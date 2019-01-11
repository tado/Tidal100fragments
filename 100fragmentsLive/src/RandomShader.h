#pragma once
#include "ofMain.h"

class RandomShader {
public:
	RandomShader();
	void update();
	void draw(int left, int top, int width, int height);
	~RandomShader();

	vector<ofShader> shaders;
	ofFbo fbo;
	int num;
};

