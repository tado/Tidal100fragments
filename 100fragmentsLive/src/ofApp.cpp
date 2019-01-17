#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	tidal = new ofxTidalCycles(3333, 4);
	for (int i = 0; i < NUM; i++) {
		brightness[i] = 0;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	tidal->update();
	for (int i = 0; i < NUM; i++) {
		randomShader[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	int noteNum = 0;
	int monitorOrder[5] = { 2,1,3,0,4 };
	for (int i = 0; i < tidal->notes.size(); i++) {
		if (ofGetElapsedTimef() - tidal->notes[i].timeStamp < 32) {
			//float diff = ofGetElapsedTimef() - tidal->notes[i].timeStamp - tidal->notes[i].latency;
			float diff = ofGetElapsedTimef() - tidal->notes[i].timeStamp;
			if (diff > 0 && abs(diff) < 1.0 / ofGetFrameRate() && tidal->notes[i].s != "midi") {
				int instNum = tidal->notes[i].instNum % 5;
				brightness[monitorOrder[instNum]] += 255;
				if (brightness[monitorOrder[instNum]] > 255) {
					brightness[monitorOrder[instNum]] = 255;
					
				}
				randomShader[monitorOrder[instNum]].num = int(ofRandom(1, randomShader[monitorOrder[instNum]].shaders.size()) - 1);
			}
		}
	}
	for (int i = 0; i < NUM; i++) {
		ofSetColor(brightness[i]);
		//randomShader[i].fbo.draw(ofGetWidth() / NUM * i, ofGetHeight() / 2 - ofGetHeight() / NUM / 2, ofGetWidth() / NUM, ofGetHeight() / NUM);
		randomShader[i].fbo.draw(0, ofGetHeight() / NUM * i, ofGetWidth(), ofGetHeight() / NUM);
		brightness[i] -= 32;
		if (brightness[i] < 0) {
			brightness[i] = 0;
		}
	}
}

void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
