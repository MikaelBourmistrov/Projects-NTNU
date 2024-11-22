#include "TetrisWindow.h"
#include <map>
#include <iostream>

const std::map<TetrominoType, TDT4102::Color> TetrominoTypeToColor {    { TetrominoType::J, TDT4102::Color::dark_blue },
                                                                        { TetrominoType::L, TDT4102::Color::orange },
                                                                        { TetrominoType::T, TDT4102::Color::purple },
                                                                        { TetrominoType::S, TDT4102::Color::green },
                                                                        { TetrominoType::Z, TDT4102::Color::red },
                                                                        { TetrominoType::O, TDT4102::Color::yellow },
                                                                        { TetrominoType::I, TDT4102::Color::cyan },
                                                                        { TetrominoType::NONE, TDT4102::Color::transparent }
};

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            currentTetromino.moveDown();
        }
        handleInput();
        
        drawCurrentTetromino();

        next_frame();
    }
}


void TetrisWindow::handleInput() {
    TDT4102::Point tetrominoPosition = currentTetromino.getPosition();

    static bool lastUpKeyState = false;
    static bool lastDownKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;

    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);

    
    if(currentDownKeyState && !lastDownKeyState) {
        //Implementert en enkel form for wall bouncing
        currentTetromino.rotateCounterClockwise();
        if(hasCrashed()) {
            //Skjekker om den kan gå en til venstre
            if(!tetrominoCrashesAt({tetrominoPosition.x - 1, tetrominoPosition.y})) {
                currentTetromino.moveLeft();
            } 
            //Skjekker om den kan gå en til høyre
            else if(!tetrominoCrashesAt({tetrominoPosition.x + 1, tetrominoPosition.y})){
                currentTetromino.moveRight();
            } 
            //Hvis ikke, opphev bevegelse
            else {
                currentTetromino.rotateClockwise(); 
            }

            //Hindre bevegelse uten wall bouncing:
            //currentTetromino.rotateCounterClockwise();
            //if(hasCrashed()) currentTetromino.rotateClockwise();
        }
    }

    if(currentUpKeyState && !lastUpKeyState) {
        currentTetromino.rotateClockwise();
        if(hasCrashed()) {
            if(!tetrominoCrashesAt({tetrominoPosition.x - 1, tetrominoPosition.y})) {
                currentTetromino.moveLeft();
            }
            else if(!tetrominoCrashesAt({tetrominoPosition.x + 1, tetrominoPosition.y})){
                currentTetromino.moveRight();
            }
            else {
                currentTetromino.rotateCounterClockwise();
            }
        }
    }

    if(currentLeftKeyState && !lastLeftKeyState) {
        std::cout<<"it here";
        if(!tetrominoCrashesAt({tetrominoPosition.x - 1, tetrominoPosition.y})) {
            currentTetromino.moveLeft();
        }
    }

    if(currentRightKeyState && !lastRightKeyState) {
        if(!tetrominoCrashesAt({tetrominoPosition.x + 1, tetrominoPosition.y})) {
            currentTetromino.moveRight();
        }
    }

    lastDownKeyState = currentDownKeyState;
    lastUpKeyState = currentUpKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
}

TetrisWindow::TetrisWindow(): AnimationWindow(200, 200, blockSize * tetrisGridWidth, blockSize * tetrisGridHeight, "Tetris"),
                              currentTetromino{},  
                              gridMatrix(tetrisGridHeight, std::vector<TetrominoType>(tetrisGridWidth, TetrominoType::NONE)) 
{
    generateRandomTetromino();
}

void TetrisWindow::generateRandomTetromino() {
    currentTetromino = Tetromino{tetrominoSpawnPoint, static_cast<TetrominoType>(rand() % 7)};
}

void TetrisWindow::drawCurrentTetromino() {
    TDT4102::Point topLeftCorner = currentTetromino.getPosition();
    int size = currentTetromino.getMatrixSize();

    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            TetrominoType field = currentTetromino.getBlock(row, col);
            if(field != TetrominoType::NONE) {
                draw_rectangle(TDT4102::Point{(topLeftCorner.x + col) * blockSize, (topLeftCorner.y + row) * blockSize}, blockSize, blockSize, TetrominoTypeToColor.at(field), TDT4102::Color::black);
            }
        }
    }
}

bool TetrisWindow::tetrominoCrashesAt(TDT4102::Point point) {
    int tetrominoMatrixSize = currentTetromino.getMatrixSize();
    for(int row = 0; row < tetrominoMatrixSize; ++row) {
        for(int column = 0; column < tetrominoMatrixSize; ++column) {
            if(currentTetromino.blockExist(row,column)) {
                if(point.x + column >= tetrisGridWidth 
                    || point.x + column < 0
                    || point.y + row >= tetrisGridHeight
                    || gridMatrix[point.y + row][point.x + column] != TetrominoType::NONE) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TetrisWindow::hasCrashed() {
    TDT4102::Point tetrominoPosition = currentTetromino.getPosition();
    return tetrominoCrashesAt(tetrominoPosition);
}