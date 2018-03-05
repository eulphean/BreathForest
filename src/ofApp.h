#pragma once

#include "ofMain.h"
#include "ofxLSystemGrammar.h"
#include "Turtle.h"
#include "ofxGui.h"

enum Rule {
  Edge,
  Node,
  Stochastic,
  Parametric,
  ParametricConstant
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
		void keyPressed(int key);
  
    // Generation for recursion. 
    int generation;
  
    // Tree production rules.
    vector<string> edgeRewriting{"F->F[+F]F[-F][F]"};
    vector<string> nodeRewriting{"X->F[+X][-X]FX", "F->FF"};
    vector<string> stochastic {
      "0.33 -> F -> F[+F]F[‚-F]F",
      "0.33 -> F -> F[+F]F",
      "0.34 -> F -> F[‚-F]F",
    };
    vector<string> parametric {
        "A(x,y): y<=3 -> A(x*2,x+y)",
        "A(x,y): y>3 -> B(x)A(x/y,0)",
        "B(x) : x<1 -> C",
        "B(x) : x>=1 -> B(x-1)"
    };
    vector<string> parametricWithConstant { "A(s) -> F (s)[+A(s/R)][-A(s/R)]" };
  
    // Production rule results after passing through L-system engine.
    vector<string> resultEdgeRewriting, resultNodeRewriting, resultStochastic, resultParametric, resultParametricWithConstant;
    
    // Define turtle engine. 
    Turtle turtle;
  
    // Gui. 
    ofxPanel gui;
    ofxFloatSlider branchAngle;
    ofxFloatSlider branchLength;
    ofxFloatSlider startAngle;
  
    // Rule indicates which production rule to use to draw the tree.
    Rule currentRule;
  
    string currentRuleString;
};
