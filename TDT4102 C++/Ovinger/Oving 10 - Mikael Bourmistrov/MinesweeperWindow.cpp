#include "MinesweeperWindow.h"
#include <iostream>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines},
	remainingTiles(width * height - mines),
	gameIsLostMsg({0, (height) * cellSize}, static_cast<unsigned int>(width * cellSize), static_cast<unsigned int>(cellSize), ""), 
	gameIsWonMsg({0, (height) * cellSize}, static_cast<unsigned int>(width * cellSize), static_cast<unsigned int>(cellSize), "")
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}

	int i = 0;
	while (i < mines) {
		int pos = rand() % tiles.size();	// rand() med % er slik funksjonen er definert. Om man tar rand % 10 vil den generere ett tilfeldig tall mellom 0 og 9.
		if (!tiles[pos]->getIsMine()) {
			tiles[pos]->setIsMine(true);
			i++;
		}
	}

	add(gameIsLostMsg);
	add(gameIsWonMsg);
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (gameIsLost || gameIsWon) { return; }
	
	shared_ptr<Tile>& tile = at(xy);

	if ((tile->getState() != Cell::closed)) { return; }
	if (tile->getIsMine()) { loss(); return; }

	tile->open();
	remainingTiles--;

	vector<Point> adjPoints = adjacentPoints(xy);
	int adjMines = countMines(adjPoints);

	if (adjMines > 0) { tile->setAdjMines(adjMines); }
	else { for (Point adjPoint : adjPoints) {openTile(adjPoint);
	std::cout<<"lol\n"; 
	}
	}

	if (remainingTiles == 0 && !gameIsWon) { victory(); return; }
}

void MinesweeperWindow::flagTile(Point xy) {
	if (gameIsLost || gameIsWon) { return; }

	shared_ptr<Tile>& tile = at(xy);

	tile->flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};
	std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int adjMines = 0;

	for (Point point : coords) { at(point)->getIsMine()?adjMines++:adjMines; }

	return adjMines;
}

void MinesweeperWindow::loss() {
	gameIsLost = true;

	int countTile = 0;
	for (auto tile : tiles) {
		if (tile->getIsMine()) { tile->open(); }
	}

	gameIsLostMsg.setText("BOOM!!!   Game over");
}

void MinesweeperWindow::victory() {
	gameIsWon = true;
	
	gameIsWonMsg.setText("YAY!     Game won");
}