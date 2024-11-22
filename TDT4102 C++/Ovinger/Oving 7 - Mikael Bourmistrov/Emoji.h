#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji {
    protected:
        Point centre;
        int radius;

    public:
        virtual void draw(AnimationWindow&) override = 0;
        Face(Point c, int r);
};

class EmptyFace : public Face {
    protected:
	    Point leftEyeC, rightEyeC;
        int leftEyeR, rightEyeR;
        
    public:
        EmptyFace(Point c, int r);
        virtual void draw(AnimationWindow&) override;

};

///////////////////////////////// Ansikter /////////////////////////////////

class SmilingFace : public EmptyFace {
    private:
        Point smileC;
        int smileWidth, smileHeight;
        
    public:
        SmilingFace(Point c, int r);
        void draw(AnimationWindow&) override;
};

////////////////////////////////////////////////////

class SadFace : public EmptyFace {
    private:
        Point sadC;
        int sadWidth, sadHeight;
        
    public:
        SadFace(Point c, int r);
        void draw(AnimationWindow&) override;
};

////////////////////////////////////////////////////

class GrimaceFace : public Face {
    private:
        Point leftEyeC, rightEyeC, leftshockedC, rightshockedC, topTeethPos, bottomTeethPos, mouthPos;
        int leftEyeR, rightEyeR, teethWidth, teethHight, mouthWidth;
        
    public:
        GrimaceFace(Point c, int r);
        void draw(AnimationWindow&) override;
};

////////////////////////////////////////////////////

class FrozenFace : public Face {
    private:
        Point leftEyeC, rightEyeC, leftshockedC, rightshockedC, topTeethPos, bottomTeethPos, mouthPos, leftBrowC, rightBrowC;
        int leftEyeR, rightEyeR, teethWidth, teethHight, mouthWidth, browHeight, browWidth;
        
    public:
        FrozenFace(Point c, int r);
        void draw(AnimationWindow&) override;
};

////////////////////////////////////////////////////

class NauseaFace : public Face {
    private:
        Point leftEyeC, rightEyeC, leftshockedC, rightshockedC, leftBrowC, rightBrowC, mainMouthStrt, mainMouthEnd, leftMouthC, rightMouthC;
        int leftEyeR, rightEyeR, browHeight, browWidth, mouthHeight, mouthWidth;
        
    public:
        NauseaFace(Point c, int r);
        void draw(AnimationWindow&) override;
};

////////////////////////////////////////////////////

void drawEmojies(vector<unique_ptr<Emoji>>& emojis, AnimationWindow& win);