#pragma once

#include "ofMain.h"
#include "ofxLSystemGrammar.h"
#include "Turtle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
		void keyPressed(int key);
  
    // Generation for recursion. 
    int generation;
  
    // Tree production rule.
    vector<string> tree{"F->F[+F]F[-F][F]"};
  
    // Result after running the tree production rule for # of iterations.
    vector<string> treeRewrite;
  
    // Define turtle engine. 
    Turtle turtle;
};
