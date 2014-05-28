#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofFileDialogResult result = ofSystemLoadDialog("Select movie file");
    if (result.bSuccess) {
        player.loadMovie(result.filePath);
        player.play();
        player.setLoopState(OF_LOOP_NORMAL);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    if (player.isFrameNew()) {
        
        unsigned long long now = ofGetElapsedTimeMicros();
        int frameTime = now - lastFrameTime;
        actualFrameRate = 1000000. / frameTime;
        lastFrameTime = now;
        
        syphon.publishTexture(&player.getTextureReference());
    }
    player.draw(0, 0);
    ofDrawBitmapString("Frame rate: " + ofToString(actualFrameRate, 2), 20, 20);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
