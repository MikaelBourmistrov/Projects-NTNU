#include "AnimationWindow.h"
#include "Emoji.h"
#include "std_lib_facilities.h"
#include "Animal.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	testAnimal();

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	//////////////////// Her tegner jeg alle Emojis ////////////////////
	vector<unique_ptr<Emoji>> emojis;   //fikk ikke til med smart pointer (eneste forskjell er at når man alokerer en smrtptr i heap vil det slettes når den går ut ifra scope? noe som er viktig sia minnelekasje er viktig (og er nok det som er vanlig feil med pointers))
		emojis.emplace_back(new EmptyFace(Point{ 100, 100 }, emojiRadius));
		emojis.emplace_back(new SmilingFace(Point{ 210, 100 }, emojiRadius));
		emojis.emplace_back(new SadFace(Point{ 320, 100 }, emojiRadius));
		emojis.emplace_back(new GrimaceFace(Point{ 100, 210 }, emojiRadius));
		emojis.emplace_back(new FrozenFace(Point{ 210, 210 }, emojiRadius));
		emojis.emplace_back(new NauseaFace(Point{ 320, 210 }, emojiRadius));

	drawEmojies(emojis, win);    // grunnen vi vil lage funksjon sånn at det går ut av scope tidligere og destruerer minnet? Men siden jeg har new her, så betyr det at jeg må delete det alokerte minnet siden det blir lagt i heap, gjøres dette gjennom destruktoren automatisk når jeg går ut av scopet til funskjonen? (hva gjør en destruktor)

	win.wait_for_close();

	return 0;
}