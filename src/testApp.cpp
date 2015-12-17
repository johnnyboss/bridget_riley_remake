/*
 *  JoyOfLight
 *
 *  Copyright 2010 Patricio Gonzalez Vivo http://www.patriciogonzalezvivo.com
 *	All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***********************************************************************/
#include "testApp.h"
#define NUM_COLORS 5
//--------------------------------------------------------------
void testApp::setup()
{
    ofEnableAlphaBlending();
    gui.setup();

    for(int i = 0; i < 7; i++)
    {
        ofxColorSlider aux;
        colors.push_back(aux);
    }
    
    colors[0].setup("color0", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[1].setup("color1", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[2].setup("color2", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[3].setup("color3", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[4].setup("color4", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[5].setup("color5", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));
    colors[6].setup("color6", ofColor(100,100,140), ofColor(0,0),ofColor(255,255));

    
    gui.add(&colors[0]);
    gui.add(&colors[1]);
    gui.add(&colors[2]);
    gui.add(&colors[3]);
    gui.add(&colors[4]);
    gui.add(&colors[5]);
    gui.add(&colors[6]);
    gui.loadFromFile("settings.xml");

    ofColor auxColor = colors[ofRandom(0,7)];

    for(int i = 0; i < 7; i ++)
    {
        horizontal_stripe aux;
        aux.create(20, -190 + i*7*30, auxColor);
        stripe1.push_back(aux);
    }
    auxColor = colors[ofRandom(0,7)];

    for(int i = 0; i < 7; i ++)
    {
        horizontal_stripe aux;
        ofColor auxColor = colors[i];
        aux.create(80, -190 - 30*.8 + i*7*30, auxColor);
        stripe2.push_back(aux);
    }
    auxColor = colors[ofRandom(0,7)];

    for(int i = 0; i < 7; i ++)
    {
        horizontal_stripe aux;
        ofColor auxColor = colors[i];
        aux.create(80 + 60, -190 -60*.8 + i*7*30, auxColor);
        stripe3.push_back(aux);
    }
    auxColor = colors[ofRandom(0,7)];

    for(int i = 0; i < 7; i ++)
    {
        horizontal_stripe aux;
        ofColor auxColor = colors[i];
        aux.create(80 + 120, -190 -90*.8 + i*7*30, auxColor);
        stripe4.push_back(aux);
    }
}

//--------------------------------------------------------------
void testApp::update()
{
	ofBackground(0, 0, 0);
    for(int i = 0; i < stripe1.size(); i ++)
    {
        stripe1[i].update();
        if(stripe1[i].cells[0].origin.y > ofGetHeight() + stripe1[i].cells[0].size.y * .8)
        {
            stripe1[i].moveUp(stripe1[i].cells[0].origin.y - 6*7*30);
            stripe1[i].color = colors[ofRandom(0,7)];
        }
    }
    for(int i = 0; i < stripe2.size(); i ++)
    {
        stripe2[i].update();
        if(stripe2[i].cells[0].origin.y > ofGetHeight() + stripe2[i].cells[0].size.y * .8)
        {
            stripe2[i].moveUp(stripe2[i].cells[0].origin.y - 6*7*30);
            stripe2[i].color = colors[ofRandom(0,7)];

        }
    }
    for(int i = 0; i < stripe3.size(); i ++)
    {
        stripe3[i].update();
        if(stripe3[i].cells[0].origin.y > ofGetHeight() + stripe3[i].cells[0].size.y * .8)
        {
            stripe3[i].moveUp(stripe3[i].cells[0].origin.y - 6*7*30);
            stripe3[i].color = colors[ofRandom(0,7)];

        }
    }
    for(int i = 0; i < stripe4.size(); i ++)
    {
        stripe4[i].update();
        if(stripe4[i].cells[0].origin.y > ofGetHeight() + stripe4[i].cells[0].size.y * .8)
        {
            stripe4[i].moveUp(stripe4[i].cells[0].origin.y - 6*7*30);
            stripe4[i].color = colors[ofRandom(0,7)];

        }
    }

}

//--------------------------------------------------------------
void testApp::draw()
{
    gui.draw();
    for(int i = 0; i < stripe1.size(); i++)
    {
        stripe1[i].draw();
    }
    for(int i = 0; i < stripe2.size(); i++)
    {
        stripe2[i].draw();
    }
    for(int i = 0; i < stripe3.size(); i++)
    {
        stripe3[i].draw();
    }
    for(int i = 0; i < stripe4.size(); i++)
    {
        stripe4[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    for(int i = 0; i < stripe1.size(); i++)
    {
        stripe1[i].update();
    }
	switch (key){
		case 'f':
			break;
		case 'i':
			break;
		case '+':
			break;
		case '-':
			break;
		case 'v':
			break;
		case 'h':
			break;
		case ' ':
			break;
		case OF_KEY_RETURN:
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

