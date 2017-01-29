#pragma once

#include "ofMain.h"
#include "FboSource.h"

class TestPattern : public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
	
		void setName(string newName);
		void setDrawColor(ofColor color);
	
		float lastClearTime;
		int frameNumber;
		ofPoint movingPoint;
		bool bounce;
		ofColor drawColor;
};
