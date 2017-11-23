#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() { 

	this->fbo.begin();
	ofClear(0);

	for (int x = 0; x < ofGetWidth(); x += 20) {
		int y = ofNoise(x * 0.005 + ofGetFrameNum() * 0.015) * ofGetHeight();

		ofDrawCircle(x, y, 8);
		ofDrawLine(ofVec2f(x, y), ofVec2f(x, ofGetHeight() / 2));
	}

	this->fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->fbo.draw(0, 0);
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}