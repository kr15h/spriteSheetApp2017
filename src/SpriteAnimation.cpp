#include "SpriteAnimation.h"

void SpriteAnimation::setup(){
	allocate(800, 800);
	
	sheet.load("sonic.png");
	frameWidth = 75;
	frameHeight = 75;
	frameNumber = 0;
	
	frameRate = 5.0f;
	lastFrameTime = 0.0f;
	
	playing = false;
}

void SpriteAnimation::update(){
	if(playing == false){
		return;
	}

	float frameDuration = 1.0f / frameRate;
	float now = ofGetElapsedTimef();
	
	if(now - lastFrameTime > frameDuration){
		frameNumber = frameNumber + 1;
		int maxNumberFrames = (int)(sheet.getWidth() / frameWidth);
		if(frameNumber >= maxNumberFrames){
			frameNumber = 0;
		}
		lastFrameTime = now;
	}
}

void SpriteAnimation::draw(){
	ofClear(0, 0, 0, 0);

	int sourceX = frameNumber * frameWidth;
	
	sheet.drawSubsection(
		0, 0, getWidth(), getHeight(),
		sourceX, 0, frameWidth, frameHeight);
}

void SpriteAnimation::setName(string newName){
	name = newName;
}

void SpriteAnimation::play(){
	playing = true;
}

void SpriteAnimation::stop(){
	playing = false;
}

void SpriteAnimation::setFrame(int number){
	frameNumber = number;
}
