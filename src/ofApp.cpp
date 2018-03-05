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
  turtle.setLength(5);
  turtle.setAngle(30);
  resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
}

//--------------------------------------------------------------
void ofApp::update(){
  // "F" is the axiom. generation is number of occurrences.
  treeRewrite = ofxLSystemGrammar::buildSentences(tree, generation, "F");
  treeNodeRewrite = ofxLSystemGrammar::buildSentences(treeNode, generation, "X");
}

void ofApp::draw(){
  // Draw the tree using Turtle graphics.
  
  string pattern;
  for (int i = 0; i < resultStochastic.size(); i++) {
    pattern += ofToString(i) + ": " + resultStochastic[i] + "\n";
  }
  
  cout << pattern << endl;
  
  ofSetColor(ofColor::white);
  
  turtle.draw(resultStochastic[resultStochastic.size()-1], ofGetWidth(), ofGetHeight(), -145);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case OF_KEY_UP: {
      generation += 1;
      resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
      //turtle.setLength(ofRandom(3, 5));
      //turtle.setAngle(ofRandom(45, 90));
      break;
    }
    
    case OF_KEY_DOWN: {
      generation -= 1;
      resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
      break;
    }
    
    default: {
      break;
    }
  }
}
