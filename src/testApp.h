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
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxGui.h"

struct cell
{
    void create(int _x, int _y, string _direction, ofColor _color)
    {
        origin.set(_x, _y);
        size.set(60,30);
        direction = _direction;
        color = _color;
    }
    
    void draw()
    {
        ofFill();
        ofSetColor(color.r, color.g, color.b, color.a);
        ofBeginShape();
        ofPoint aux;
        aux.x = origin.x + size.x;
        aux.y = origin.y - size.y * .8;
        ofVertex(origin);
        ofVertex(aux);
        aux += ofPoint(0,size.y);
        ofVertex(aux);
        aux += ofPoint(-size.x, 0.8* size.y);
        ofVertex(aux);
        aux -= ofPoint(0,size.y);
        ofVertex(aux);
        ofEndShape();
    }
    
    void update()
    {
        if(direction == "down")
        {
            origin.y += 5;
        }
    }
    
    ofPoint origin;
    ofPoint size;
    string direction;
    ofColor color;
    
};

struct horizontal_stripe
{
    void create(int _x, int _y, ofColor _color)
    {
        for(int i = 0; i < 7; i++)
        {
            cell aux;
            color = _color;
            aux.create(_x, _y + i*30, "down", color);
            cells.push_back(aux);
        }
    }
    
    void moveUp(int _y)
    {
        cells[0].origin.y = _y;
        for (int i = 0; i < cells.size(); i++)
        {
            cells[i].origin.y = cells[0].origin.y + i*30;
        }
    }
    
    void update()
    {
        for(int i = 0; i < cells.size(); i++)
        {
            cells[i].color = color;
            cells[i].update();
        }
    }
    
    void draw()
    {
        for(int i = 0; i < cells.size(); i++)
        {
            cells[i].draw();
        }
    }
    
    vector<cell> cells;
    ofColor color;
};


class testApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
private:
    ofxPanel gui;
    vector <ofxColorSlider> colors;
    
    vector<horizontal_stripe> stripe1, stripe2, stripe3, stripe4;
};

#endif
