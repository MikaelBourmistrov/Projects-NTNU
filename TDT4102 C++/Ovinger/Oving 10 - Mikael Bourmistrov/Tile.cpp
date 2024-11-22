#include "Tile.h"
#include <map>
#include <iostream>

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const std::map<int, TDT4102::Color> minesToColor{{1, TDT4102::Color::blue},
												{2, TDT4102::Color::red},
												{3, TDT4102::Color::dark_green},
												{4, TDT4102::Color::dark_magenta},
												{5, TDT4102::Color::dark_blue},
												{6, TDT4102::Color::dark_cyan},
												{7, TDT4102::Color::dark_red},
												{8, TDT4102::Color::gold}};

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{	
	if (state == Cell::closed) { 
		this->setButtonColor(TDT4102::Color::white); 
		state == Cell::open;
		
		if (isMine) { 
			set_label("X");
			set_label_color(TDT4102::Color::red);
		}
	}
}

void Tile::flag()
{
	switch (state) {
	case Cell::closed:
		state = Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(TDT4102::Color::black); break;

	case Cell::flagged:
		state = Cell::closed; 
		set_label(cellToSymbol.at(Cell::closed)); break;

	case Cell::open:;
	}
}

bool Tile::getIsMine() const {
	return isMine;
}

void Tile::setIsMine(bool trueFalse) {
	if (trueFalse == true || trueFalse == false) { isMine = trueFalse; }
}

void Tile::setAdjMines(int n) {
	set_label(std::to_string(n)); 			// er to string nødvendig
	set_label_color(minesToColor.at(n));
}
