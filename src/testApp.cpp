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

    
    for(int j = 0; j < 18; j++)
    {
        ofColor auxColor = colors[ofRandom(0,7)];
        
        stripe1.clear();
        for(int i = 0; i < 7; i ++)
        {
            vertical_stripe *aux;
            aux = new vertical_stripe();
            aux->create(j * 60, -j*30+ i*7*30, auxColor);
            stripe1.push_back(aux);
        }
    
        stripes.push_back(stripe1);
    }
    
    int nFloating = ofRandom(400,500);
    cell aux;

    for(int i = 0; i < nFloating; i++)
    {
        int x = ofRandom(17);
        int y = ofRandom(4);
        int num_cell = ofRandom(7);
        aux.create(stripes[x][y]->cells[num_cell]->origin.x + 1*17*60,  stripes[x][y]->cells[num_cell]->origin.y-30*30,"diagonal", colors[ofRandom(7)]);
        floating_cells.push_back(aux);
    }
    
}

//--------------------------------------------------------------
void testApp::update()
{
	ofBackground(0, 0, 0);
    for(int j = 0; j < stripes.size(); j++)
    {
        for(int i = 0; i < stripes[j].size(); i ++)
        {
            stripes[j][i]->update();
            if(stripes[j][i]->cells[0]->origin.y > ofGetHeight() + stripes[j][i]->cells[0]->size.y * .8)
            {
                stripes[j][i]->moveUp(stripes[j][i]->cells[0]->origin.y - 6*7*30);
                stripes[j][i]->color = colors[ofRandom(0,7)];
            }
        }
    }
    
    for(int i = 0; i < floating_cells.size(); i++)
    {
        floating_cells[i].update();
        if(floating_cells[i].origin.y > ofGetHeight() + floating_cells[i].size.y || floating_cells[i].origin.x < -60)
        {
            int x = ofRandom(20);
            int y = ofRandom(15);
            int num_cell = ofRandom(7);
            floating_cells[i].origin += ofPoint((18 + x)*60, -(6 + y)*7*30);
            floating_cells[i].color = colors[ofRandom(0,7)];

        }
    }
    /*for(int i = 0; i < stripe2.size(); i ++)
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
    }*/

}

//--------------------------------------------------------------
void testApp::draw()
{
    //ofScale(0.2,0.2);
    //ofTranslate(0, 500);
    for(int j = 0; j < stripes.size(); j++)
    {
        for(int i = 0; i < stripes[j].size(); i++)
        {
            stripes[j][i]->draw();
        }
    }
    
    for(int i = 0; i < floating_cells.size(); i++)
    {
        floating_cells[i].draw();
    }
    //gui.draw();
   /* for(int i = 0; i < stripe2.size(); i++)
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
    }*/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    
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

