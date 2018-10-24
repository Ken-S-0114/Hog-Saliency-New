#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    hog.loadMultiSVM(ofToDataPath("face_detector.svm"));
    ofSetVerticalSync(true);
    player.load("sampleMovie.mov");
    player.play();

    //    cam.initGrabber(620,480);
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();
    if (player.isFrameNew()){
        frame = ofxCv::toCv(player).clone();
        cv::pyrDown(frame.clone(), frame);
        hogData = hog.multiUpdate(frame);
        for (auto data : hogData) {
            cv::rectangle(frame, data.rect, cv::Scalar(255, 0, 0), 2, CV_AA);
        }
    }

    //    cam.update();
    //    if (cam.isFrameNew()){
    //        frame = ofxCv::toCv(cam).clone();
    //    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    ofxCv::drawMat(frame,0,0,ofGetWidth(),ofGetHeight());
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
