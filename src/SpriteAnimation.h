#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SpriteAnimation : public ofx::piMapper::FboSource{
	public:
		void setup();
		void update();
		void draw();
	
		void setName(string newName);
};
