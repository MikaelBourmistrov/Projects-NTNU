#include "Tetromino.h"
#include <map>
#include <string>
    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {

    {
    { TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }},
    { TetrominoType::L,
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }},
    { TetrominoType::T,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }},
    { TetrominoType::S,
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }},
    { TetrominoType::Z,
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }},
    { TetrominoType::O,
        {
        {1, 1},
        {1, 1}
        }},
    { TetrominoType::I,
        {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
        }},
    {TetrominoType::NONE,
        {

        }}
    }
};

Tetromino::Tetromino(): topLeftCorner({0,0}), matrixSize(0) { }

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}, matrixSize{static_cast<int>(initialMatrixMap.at(tetType).size())}, 
blockMatrix(matrixSize, std::vector<TetrominoType>(matrixSize, TetrominoType::NONE))
{
    for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
            if (initialMatrixMap.at(tetType)[row][col]) { blockMatrix[row][col] = tetType; }
        }
    }
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveDown() {
    topLeftCorner.y++;
}

void Tetromino::moveRight() {
    topLeftCorner.x++;
}

void Tetromino::moveLeft() {
    topLeftCorner.x--;
}

bool Tetromino::blockExist(int row, int column) {
    if ((0 < row || row > matrixSize) || (0 < column || column > matrixSize)) { throw std::string("Values out of defined bounds for this Tetromino"); }
    else { return blockMatrix[row][column] != TetrominoType::NONE; }
}

TetrominoType Tetromino::getBlock(int row, int column) {
    return blockMatrix[row][column];
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

TDT4102::Point Tetromino::getPosition() {
    return topLeftCorner;
}