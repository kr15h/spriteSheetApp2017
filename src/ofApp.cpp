#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
	
	oscReceiver.setup(54321);
	oscSender.setup("127.0.0.1", 54321);
	
	tpA.setName("Test Pattern A");
	tpA.setDrawColor(ofColor::magenta);
	
	tpB.setName("Test Pattern B");
	tpB.setDrawColor(ofColor::yellow);
	
	sa.setName("Sprite Animation");
	
	mapper.registerFboSource(tpA);
	mapper.registerFboSource(tpB);
	mapper.registerFboSource(sa);
	mapper.setup();
}

void ofApp::update(){
	while(oscReceiver.hasWaitingMessages()){
		ofxOscMessage message;
		oscReceiver.getNextMessage(message);
		cout << message.getAddress() << endl;
		if(message.getAddress() == "/spriteSheetApp/tpA/color"){
			ofColor color;
			int red = message.getArgAsInt(0);
			int green = message.getArgAsInt(1);
			int blue = message.getArgAsInt(2);
			color.r = red;
			color.g = green;
			color.b = blue;
			tpA.setDrawColor(color);
		}else if(message.getAddress() == "/spriteSheetApp/tpB/color"){
			ofColor color = ofColor(
				message.getArgAsInt(0),
				message.getArgAsInt(1),
				message.getArgAsInt(2));
			tpB.setDrawColor(color);
		}else if(message.getAddress() == "/spriteSheetApp/sa/frameNumber"){
			sa.setFrame(message.getArgAsInt(0));
		}
	}

	mapper.update();
}

void ofApp::draw(){
	mapper.draw();
}

void ofApp::keyPressed(int key){
	if(key == '5'){
		ofxOscMessage message;
		message.setAddress("/spriteSheetApp/tpA/color");
		message.addIntArg((int)ofRandom(255));
		message.addIntArg(ofColor::magenta.g);
		message.addIntArg(ofColor::magenta.b);
		oscSender.sendMessage(message);
		
	}else if(key == '6'){
		ofxOscMessage message;
		message.setAddress("/spriteSheetApp/tpB/color");
		message.addIntArg((int)ofRandom(255));
		message.addIntArg((int)ofRandom(255));
		message.addIntArg((int)ofRandom(255));
		oscSender.sendMessage(message);
	}else if(key == '7'){
		sa.play();
	}else if(key == '8'){
		sa.stop();
	}

	mapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	mapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	mapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	mapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	mapper.mouseDragged(x, y, button);
}
