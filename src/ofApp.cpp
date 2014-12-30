#include "ofApp.h"

long  NUM_BILLBOARDS = 0;
void ofApp::setupShader(){
    
    img.loadImage("IMG_1229.JPG");
    int totalSizeImg =  (img.getHeight()-1) * img.getWidth();
    int imgWidth = img.getWidth()-1;
    int imgHeight = img.getHeight()-1;

    cout << totalSizeImg << " totalSizeImg " << endl;
    
    for(int x=0;x<totalSizeImg;x++){
        
        
        billboardVels.push_back(ofVec3f());
        billboardSizeTarget.push_back(0);
    }
    
    ofBackground(0, 0, 0);
	
	cameraRotation.set(0);
	zoom = -500;
	zoomTarget = 200;
	NUM_BILLBOARDS = totalSizeImg;
	billboards.getVertices().resize(NUM_BILLBOARDS);
	billboards.getColors().resize(NUM_BILLBOARDS);
	billboards.getNormals().resize(NUM_BILLBOARDS,ofVec3f(0));
    

    int totalNu = 0;
	for(int x =1;x<=imgWidth;x++){
        for(int y = 1;y<=imgHeight;y++){
            float xx = ofMap(x, 0, imgWidth, -70, 70);
            float yy = ofMap(y, 0, imgHeight, -35, 35);
            billboards.getVertices()[totalNu].set(xx,yy,totalNu); // i the id of billboard
            //cout << x << " " << y << endl;
            billboards.getColors()[totalNu].set(img.getColor(x, y));
            billboardSizeTarget[totalNu] = 1;
            //billboards.setNormal(totalNu,ofVec3f(9,0,0));
                      totalNu ++;
 

        }

    }
	for (int i=0; i<NUM_BILLBOARDS; i++) {
        
      

	}


	
	 
    billboards.setUsage( GL_DYNAMIC_DRAW );
	 
    billboards.setMode(OF_PRIMITIVE_POINTS);
	// load the billboard shader
	// this is used to change the
	// size of the particle

		billboardShader.load("shadersGL2/Billboard");
        cout << "Billboard"<< endl;

	
	// we need to disable ARB textures in order to use normalized texcoords
	//ofDisableArbTex();
	texture.loadImage("dot.png");
	ofEnableAlphaBlending();
}


void ofApp::updateShader(){
    

    
    
}


void ofApp::drawShader(){
    
    
    
    ofBackground(0);
    
   // fbo.begin();
   
   	ofBackgroundGradient(ofColor(255), ofColor(230, 240, 255));
	
	string info = ofToString(ofGetFrameRate(), 2)+"\n";
	info += "Particle Count: "+ofToString(NUM_BILLBOARDS);
	ofDrawBitmapStringHighlight(info, 30, 30);
	
	ofSetColor(255);

    
	billboardShader.begin();

    billboardShader.setUniform1f("scaleBen", 132);
    billboardShader.setUniform1f("numPoints", ofGetMouseX());
	ofEnablePointSprites(); // not needed for GL3/4
  
	texture.getTextureReference().bind();
        cam.begin();
	billboards.draw();
         cam.end();
	texture.getTextureReference().unbind();
    
	ofDisablePointSprites(); // not needed for GL3/4
	
	billboardShader.end();
	
  
   // fbo.end();
    //    }
    
    
    
    
    
    
    
   // fbo.draw(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()/2);
    
    
    
}




//--------------------------------------------------------------
void ofApp::setup(){
    setupShader();
}

//--------------------------------------------------------------
void ofApp::update(){
    
//updateShader();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofSetRectMode(OF_RECTMODE_CORNER);

    drawShader();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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