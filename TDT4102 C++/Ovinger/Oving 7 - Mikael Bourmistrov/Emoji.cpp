#include "Emoji.h"

Face::Face(Point c, int r): centre(c), radius(r) {}

void Face::draw(AnimationWindow& win) {win.draw_circle(centre, radius, Color::yellow);}

//////////////////////////////////////////////////////////////////////////////////

EmptyFace::EmptyFace(Point c, int r): Face(c, r), 
                                      leftEyeC(Point{c.x - r/2, c.y - r/8}), rightEyeC(Point{c.x + r/2, c.y - r/8}), 
                                      leftEyeR(r/10), rightEyeR(r/10) {}

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(leftEyeC, leftEyeR, Color::black);
    win.draw_circle(rightEyeC, rightEyeR, Color::black);
}

//////////////////////////////////////////////////////////////////////////////////

SmilingFace::SmilingFace(Point c, int r): EmptyFace(c, r),
                                          smileC(Point{c.x, c.y + r/3}),
                                          smileHeight(r/4), smileWidth(r/2)
                                        {}

void SmilingFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(smileC, smileWidth, smileHeight, 180, 360, Color::black);
}

//////////////////////////////////////////////////////////////////////////////////

SadFace::SadFace(Point c, int r): EmptyFace(c, r),
                                          sadC(Point{c.x, c.y + r/2}),
                                          sadHeight(r/4), sadWidth(r/2)
                                        {}

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(sadC, sadWidth, sadHeight, 0, 180, Color::black);
}

//////////////////////////////////////////////////////////////////////////////////

GrimaceFace::GrimaceFace(Point c, int r): Face(c, r),
                                          leftEyeC(Point{c.x - r/2, c.y - r/4}), rightEyeC(Point{c.x + r/2, c.y - r/4}), 
                                          leftshockedC(Point{c.x - int(r/1.7), c.y - r/4}), rightshockedC(Point{c.x + int(r/1.7), c.y - r/4}),
                                          leftEyeR(r/10), rightEyeR(r/10),
                                          topTeethPos(Point{c.x - int(r/2.4), c.y + r/10}), bottomTeethPos(Point{c.x - int(r/2.4), c.y + int(r/2.5)}),
                                          mouthPos(Point{c.x - r/2, c.y + r/10}),
                                          teethHight(r/5), teethWidth(r/1.2), mouthWidth(r)
                                        {}

void GrimaceFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(leftshockedC, leftEyeR*2.5, Color::white);   //sjokerte delen av øyene
    win.draw_circle(rightshockedC, rightEyeR*2.5, Color::white); //
    win.draw_circle(leftEyeC, leftEyeR, Color::black);
    win.draw_circle(rightEyeC, rightEyeR, Color::black);
    win.draw_rectangle(mouthPos, mouthWidth, teethHight*2.5, Color::black);
    win.draw_rectangle(topTeethPos, teethWidth, teethHight, Color::white);
    win.draw_rectangle(bottomTeethPos, teethWidth, teethHight, Color::white);
}

//////////////////////////////////////////////////////////////////////////////////

FrozenFace::FrozenFace(Point c, int r): Face(c, r),
                                        leftEyeC(Point{c.x - r/2, c.y - r/4}), rightEyeC(Point{c.x + r/2, c.y - r/4}), 
                                        leftshockedC(Point{c.x - int(r/1.7), c.y - r/4}), rightshockedC(Point{c.x + int(r/1.7), c.y - r/4}),
                                        leftEyeR(r/10), rightEyeR(r/10),
                                        topTeethPos(Point{c.x - int(r/2.4), c.y + r/10}), bottomTeethPos(Point{c.x - int(r/2.4), c.y + int(r/2.5)}),
                                        mouthPos(Point{c.x - r/2, c.y + r/10}),
                                        teethHight(r/5), teethWidth(r/1.2), mouthWidth(r),
                                        leftBrowC(Point{c.x - int(r/1.2), c.y - int(r/1.2)}), rightBrowC(Point{c.x + int(r/1.2), c.y - int(r/1.2)}),
                                        browHeight(r/4), browWidth(r/2)
                                        {}

void FrozenFace::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius, Color::blue);
    win.draw_circle(leftshockedC, leftEyeR*2.5, Color::white);   //sjokerte delen av øyene
    win.draw_circle(rightshockedC, rightEyeR*2.5, Color::white); //
    win.draw_circle(leftEyeC, leftEyeR, Color::black);
    win.draw_circle(rightEyeC, rightEyeR, Color::black);
    win.draw_rectangle(mouthPos, mouthWidth, teethHight*2.5, Color::black);
    win.draw_rectangle(topTeethPos, teethWidth, teethHight, Color::white);
    win.draw_rectangle(bottomTeethPos, teethWidth, teethHight, Color::white);
    win.draw_arc(leftBrowC, browWidth, browHeight, 270, 360, Color::black);
    win.draw_arc(rightBrowC, browWidth, browHeight, 180, 270, Color::black);
}

//////////////////////////////////////////////////////////////////////////////////

NauseaFace::NauseaFace(Point c, int r): Face(c, r),
                                        leftEyeC(Point{c.x - r/2, c.y - r/4}), rightEyeC(Point{c.x + r/2, c.y - r/4}), 
                                        leftshockedC(Point{c.x - int(r/1.7), c.y - r/4}), rightshockedC(Point{c.x + int(r/1.7), c.y - r/4}),
                                        leftEyeR(r/10), rightEyeR(r/10),
                                        leftBrowC(Point{c.x - int(r/1.2), c.y - int(r/1.2)}), rightBrowC(Point{c.x + int(r/1.2), c.y - int(r/1.2)}),
                                        browHeight(r/4), browWidth(r/2),
                                        mainMouthStrt(Point{c.x - r/5, c.y + r/3}), mainMouthEnd(Point{c.x + r/5, c.y + r/3}),
                                        leftMouthC(Point{c.x - r/3, c.y + r/3}), rightMouthC(Point{c.x + r/3, c.y + r/3}),
                                        mouthHeight(r/4), mouthWidth(r/6)
                                        {}

void NauseaFace::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius, Color::lime_green);
    win.draw_circle(leftshockedC, leftEyeR*2.5, Color::white);   //sjokerte delen av øyene
    win.draw_circle(rightshockedC, rightEyeR*2.5, Color::white); //
    win.draw_circle(leftEyeC, leftEyeR, Color::black);
    win.draw_circle(rightEyeC, rightEyeR, Color::black);
    win.draw_arc(leftBrowC, browWidth, browHeight, 270, 360, Color::black);
    win.draw_arc(rightBrowC, browWidth, browHeight, 180, 270, Color::black);
    win.draw_line(mainMouthStrt, mainMouthEnd, Color::black);
    win.draw_arc(leftMouthC, mouthWidth, mouthHeight, 0, 90, Color::black);     //
    win.draw_arc(leftMouthC, mouthWidth, mouthHeight, 270, 360, Color::black);  // måtte dele opp i to deler lol
    win.draw_arc(rightMouthC, mouthWidth, mouthHeight, 90, 270, Color::black);
}

//////////////////////////////////////////////////////////////////////////////////

void drawEmojies(vector<unique_ptr<Emoji>>& emojis, AnimationWindow& win) { for (unique_ptr<Emoji>& emoji : emojis) emoji-> draw(win); } //& her så det ikke skaper kopier (som ikke destrueres?), men istedet tar for seg de faktiske verdiene og bruker og destruere dem.