#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <iostream>

class TetrisWindow : public TDT4102::AnimationWindow {

public:
    TetrisWindow();
    void run();

private:
    Tetromino currentTetromino;
    std::vector<std::vector<TetrominoType>> gridMatrix;

    static constexpr int tetrisGridHeight {18};
    static constexpr int tetrisGridWidth {10};
    static constexpr int startRow {1};
    static constexpr int startColumn {tetrisGridWidth/2-1};

    static constexpr int blockSize {Tetromino::blockSize};
    static constexpr TDT4102::Point tetrominoSpawnPoint {startColumn, startRow};
    // static constexpr int sideBarLength = 180;
    // static constexpr int sideBarHeight = 50;
    // static constexpr int outBoxOffset = 70;

    void handleInput();

    void generateRandomTetromino();

    void drawCurrentTetromino();

    bool tetrominoCrashesAt(TDT4102::Point point);
    bool hasCrashed();

};