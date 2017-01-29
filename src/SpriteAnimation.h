#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SpriteAnimation : public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
	
		void setName(string newName);
		void play();
		void stop();
		void setFrame(int number);
	
		ofImage sheet;
	
		int frameWidth;
		int frameHeight;
		int frameNumber;
	
		float frameRate;
		float lastFrameTime;
	
		bool playing;
};
