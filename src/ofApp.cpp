#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  
  // Default generation is 1.
  generation = 1;
  
  // Initialize turtle engine.
  // (Forward, Left, Right).
  // [TODO] Fix +, - switched in Turtle engine.
  turtle = Turtle("F", "+", "-");
  turtle.setLength(10);
  turtle.setAngle(30);
}

//--------------------------------------------------------------
void ofApp::update(){
  // "F" is the axiom. generation is number of occurrences.
  treeRewrite = ofxLSystemGrammar::buildSentences(tree, generation, "F");
}

void ofApp::draw(){
  // Draw the tree using Turtle graphics.
  
  string pattern;
  for (int i = 0; i < treeRewrite.size(); i++) {
    pattern += ofToString(i) + ": " + treeRewrite[i] + "\n";
  }
  
  ofDrawBitmapStringHighlight(pattern, 10, 10);
  
  ofSetColor(ofColor::white);
  
  // Draw the tree.
  // (Result, start_x, start_y, start_angle)
  // [TODO] Fix starting angle.
  turtle.draw(treeRewrite[treeRewrite.size()-1], ofGetWidth()/2, ofGetHeight(), -90);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case OF_KEY_UP: {
      generation += 1;
      break;
    }
    
    case OF_KEY_DOWN: {
      generation -= 1;
      break;
    }
    
    default: {
      break;
    }
  }
}
