#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  gui.setup();
  
  // GUI parameters.
  gui.add(branchAngle.setup("Branch angle", 30, 0, 180));
  gui.add(branchLength.setup("Branch length", 5, 0, 100));
  gui.add(startAngle.setup("Start Angle", 145, 0, 180));

  // Default values.
  generation = 1;
  currentRule = Edge;
  currentRuleString = "Edge";
  
  // Initialize turtle engine.
  // (Forward, Left, Right).
  turtle = Turtle("F", "+", "-");
  
  // We don't want to update this in every update loop because it's non-deterministic.
  resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
}

//--------------------------------------------------------------
void ofApp::update(){
  // Update turtle engine with the GUI parameters.
  turtle.setAngle(branchAngle);
  turtle.setLength(branchLength);
  
  // Third parameter is the Axiom (or starting condition) for the generation of the tree.
  resultEdgeRewriting = ofxLSystemGrammar::buildSentences(edgeRewriting, generation, "F");
  resultNodeRewriting = ofxLSystemGrammar::buildSentences(nodeRewriting, generation, "X");
  resultParametric = ofxLSystemGrammar::buildSentences(parametric, generation, "B(2),A(4,4)");
  
  map<string, float> constants;
  constants.insert(make_pair("R", 1.456));
  resultParametricWithConstant = ofxLSystemGrammar::buildSentences(parametricWithConstant, generation, "A(1)", constants);
}

void ofApp::draw(){
  // GUI
  gui.draw();
  
  ofDrawBitmapStringHighlight(currentRuleString, 50, 50);
  
  // Tree
  ofPushStyle();
    ofSetColor(ofColor::white);
    switch (currentRule) {
      case Edge: {
        turtle.draw(resultEdgeRewriting[resultEdgeRewriting.size()-1], ofGetWidth(), ofGetHeight(), -startAngle);
        break;
      }
      
      case Node: {
        turtle.draw(resultNodeRewriting[resultNodeRewriting.size()-1], ofGetWidth(), ofGetHeight(), -startAngle);
        break;
      }
      
      case Parametric: {
        turtle.draw(resultParametric[resultParametric.size()-1], ofGetWidth(), ofGetHeight(), -startAngle);
        break;
      }
      
      case Stochastic: {
        turtle.draw(resultStochastic[resultStochastic.size()-1], ofGetWidth(), ofGetHeight(), -startAngle);
        break;
      }
      
      case ParametricConstant: {
        turtle.draw(resultParametricWithConstant[resultParametricWithConstant.size()-1], ofGetWidth(), ofGetHeight(), -startAngle);
        break;
      }
      
      default: {
        break;
      }
    }
  ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key) {
    case OF_KEY_UP: {
      generation += 1;
      resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
      break;
    }
    
    case OF_KEY_DOWN: {
      generation -= 1;
      resultStochastic = ofxLSystemGrammar::buildSentences(stochastic, generation, "F");
      break;
    }
    
    // Productions rules.
    case '1': {
      currentRule = Edge;
      currentRuleString = "Edge";
      break;
    }
    
    case '2': {
      currentRule = Node;
      currentRuleString = "Node";
      break;
    }
    
    case '3': {
      currentRule = Stochastic;
      currentRuleString = "Stochastic";
      break;
    }
    
    case '4': {
      currentRule = Parametric;
      currentRuleString = "Parametric";
      break;
    }
    
    case '5': {
      currentRule = ParametricConstant;
      currentRuleString = "Parametric with constant";
      break;
    }
    
    default: {
      break;
    }
  }
}
