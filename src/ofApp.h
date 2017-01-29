#pragma once

#include "ofMain.h"
#include "TestPattern.h"
#include "SpriteAnimation.h"
#include "ofxPiMapper.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
		void keyReleased(int key);
	
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseDragged(int x, int y, int button);
	
		TestPattern tpA;
		TestPattern tpB;
		SpriteAnimation sa;

		ofxPiMapper mapper;
	
		ofxOscReceiver oscReceiver;
		ofxOscSender oscSender;
	
		ofRectangle r1;
		ofRectangle r2;
};
