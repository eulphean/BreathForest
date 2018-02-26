#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  
  // Default generation is 1.
  generation = 1;
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
