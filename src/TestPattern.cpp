#include "TestPattern.h"

void TestPattern::setup(){
	lastClearTime = 0.0f;
	frameNumber = 0;
	movingPoint = ofPoint(0, 0);
	bounce = false;
	allocate(800, 800);
}

void TestPattern::update(){
	float ar = (float)getWidth() / (float)getHeight();

	if(bounce == true){
		movingPoint = movingPoint - ofPoint(3.0f * ar, 3.0f);
	}else{
		movingPoint = movingPoint + ofPoint(6.0f * ar, 6.0f);
	}
	
	if(movingPoint.x > getWidth() && movingPoint.y > getHeight()){
		bounce = true;
	}else if(movingPoint.x < 0 && movingPoint.y < 0){
		bounce = false;
	}
}

void TestPattern::draw(){
	if(ofGetElapsedTimef() - lastClearTime > 1.0f){
		ofSetColor(0);
		ofDrawRectangle(0, 0, getWidth(), getHeight());
		lastClearTime = ofGetElapsedTimef();
	}

	ofSetColor(drawColor);
	ofSetLineWidth(1);
	ofDrawLine(
		ofRandom(getWidth()),
		ofRandom(getHeight()),
		movingPoint.x,
		movingPoint.y);
	
	ofColor background = ofColor(drawColor.getInverted());
	ofColor foreground = ofColor(drawColor);
	ofDrawBitmapStringHighlight(
		ofToString((int)ofGetFrameRate()),
		10, 20,
		background,
		foreground);
	
	ofSetColor(drawColor);
	ofDrawLine(0, movingPoint.y, getWidth(), movingPoint.y);
	ofDrawLine(movingPoint.x, 0, movingPoint.x, getHeight());
}

void TestPattern::setName(string newName){
	name = newName;
}

void TestPattern::setDrawColor(ofColor color){
	drawColor = color;
}
