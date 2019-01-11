#include "RandomShader.h"

RandomShader::RandomShader(){
    ofDirectory dir("100fragments");
    for (int i = 0; i < dir.getFiles().size(); i++){
		ostringstream digit;
		digit << setfill('0') << right << setw(2) << i;
		ofShader sh;
		sh.load("", "100fragments/" + digit.str() + ".frag");
		shaders.push_back(sh);
	}
	num = 0;
	fbo.allocate(1920/2, 1080/5);
}

void RandomShader::update() {
	/*
	if (ofGetFrameNum() % int(ofRandom(1, 6)) == 0) {
		num = int(ofRandom(shaders.size()));
	}
	*/

	fbo.begin();
	shaders[num].begin();
	shaders[num].setUniform1f("time", ofGetElapsedTimef());
	shaders[num].setUniform2f("resolution", 1920/2, 1080/5);
	ofDrawRectangle(0, 0, 1920, 1080);
	shaders[num].end();
	fbo.end();
}

void RandomShader::draw(int left, int top, int width, int height) {

}

RandomShader::~RandomShader(){
}

