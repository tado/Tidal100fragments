#pragma once

#include "ofMain.h"
#include "ofxTidalCycles.h"
#include "ofxOsc.h"
#include "RandomShader.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxTidalCycles *tidal;
	static const int NUM = 5;
	RandomShader randomShader[NUM];
	int brightness[NUM];
};
