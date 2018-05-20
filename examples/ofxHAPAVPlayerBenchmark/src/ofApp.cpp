#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(1000);
    ofSetVerticalSync(false);
    ofBackground(0);
    
    vid.load("../../../ofxHAPAVPlayerExample/bin/data/SampleHap.mov");
    vid.play();
    vid.setSpeed(1.0);
          ofLog()<<"vid res "<<vid.getWidth()<<" x "<<vid.getHeight();
    
    dir.allowExt("mov");
    dir.listDir(ofToDataPath("")); //ofToDataPath("/Users/gameover/Desktop/LAF/hap")

    maxPlayers = 20; //220
    videos.resize(maxPlayers);
    
    numLoaded = 0;
    
//    for(int i = 0; i < maxPlayers; i++){
//
//        videos[i].load(dir.getPath((int)ofRandom(dir.size())));
//        videos[i].play();
//        videos[i].setSpeed(3.0);
//        ofSleepMillis(5);
//        
//    }
    
    bRandomize = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vid.update();
    
    for(int i = 0; i < maxPlayers; i++){
        videos[i].update();
    }
    
    if(!bRandomize) return;
    
    if(ofGetElapsedTimeMillis() - lastTime > 4000){ // every 40 millis!
        
        if(numLoaded < maxPlayers){
            videos[numLoaded].load(dir.getPath((int)ofRandom(dir.size())));
            videos[numLoaded].play();
//            videos[numLoaded].setSpeed(3.0);
            numLoaded++;
        }
        
        int i = (int)ofRandom(maxPlayers);
        videos[i].load(dir.getPath(ofRandom(dir.size())));
        videos[i].play();
//        videos[i].setSpeed(3.0);
        i = (int)ofRandom(maxPlayers);
        videos[i].setFrame((int)ofRandom(videos[i].getTotalNumFrames()));
        lastTime = ofGetElapsedTimeMillis();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
        ofEnableAlphaBlending();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);

//    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    vid.draw(0, ofGetHeight() - vid.getHeight());
    
    int xM = 0; int yM = 0;
    int tilesWide = 5;
    for(int i = 0; i < maxPlayers; i++){

        float width = (ofGetWidth() / tilesWide);
        float height = width * (videos[i].getHeight() / videos[i].getWidth());
//         ofLog()<<"videos[i] res "<<videos[i].getWidth()<<" x "<<videos[i].getHeight();
        
        if(xM == tilesWide - 1) yM++;
        xM = i%tilesWide;
        
        videos[i].draw(xM * width, yM * height, width, height);
//        videos[i].draw(0, 0, 1920, 1080);
    }
    
//    ofDisableBlendMode();
    ofDisableAlphaBlending();
    ostringstream os;
    os << "FPS : " << ofGetFrameRate() << endl;
    os << "MOVs: " << maxPlayers << endl;
    os << "Press ' ' (SpaceBar) to toggle loading and seeking frames of movies at random" << endl;
    ofDrawBitmapString(os.str(), 20, ofGetHeight() - 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    
    switch (key) {
        case ' ':
        {
            bRandomize = !bRandomize;
        }
            break;
        case 'a':
        {
            for(int i = 0; i < maxPlayers; i++){
                
                videos[i].load(dir.getPath(ofRandom(dir.size())));
                videos[i].play();
//                videos[i].update();
                ofLog()<<"videos[i] res "<<videos[i].getWidth()<<" x "<<videos[i].getHeight();
            }
        }
            break;
        default:
            break;
    }
    
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
