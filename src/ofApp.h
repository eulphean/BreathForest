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
    vector<string> treeNode{"X->F[+X][-X]FX", "F->FF"};
    vector<string> stochastic {
      "0.33 -> F -> F[+F]F[-F]F",
      "0.33 -> F -> F[+F]F",
      "0.34 -> F -> F[-F]F",
    };
  
    // Result after running the tree production rule for # of iterations.
    vector<string> treeRewrite;
    vector<string> treeNodeRewrite;
    vector<string> resultStochastic;
    
    // Define turtle engine. 
    Turtle turtle;
};

/*
  Standard tree rules.
 
  Rule - F->F[+F]F[-F][F]
  delta - 20-25 degrees.
  Axiom - 5
*/

