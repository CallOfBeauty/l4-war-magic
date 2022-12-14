/** L4: Game of War
Name: Dimitrios Ntentia
username:  ntentiad
Purpose: To work with stacks and queues in C++ sucesfully creating a functional card game 

Acknowledgements:
Modified from original stub code written by Dr. Jan Pearce
*/

#include <iostream> 
#include <algorithm>    // has shuffle
#include <vector> 
#include <random>
#include <chrono>
#include <stack>
#include <deque>
#include <queue>


//Include descriptive docstrings for each function, class, and method.Even better, each functionand method should have appropriate pre - and post - conditions.


using namespace std;


class GetRandom {
	/** Uses <random> from C++11 to return a random integer in range [1..size] */
public:
	GetRandom(int size) {
		random_device rd; // declares a random_device object that need to generate a random number.
		mt19937 gen(rd()); //mt19937 is an efficient pseudo-random number generator using the Mersenne twister algorithm.
		uniform_int_distribution<int> intdist(1, size); //create a uniform distribution object to turn the pseudorandom result into a random digit between 1 and size.
		self_rand_int_ = intdist(gen); //generates the random number.
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
}; // end of GetRandom






class War {
	/**
	FIXME
	*/
public:
	War() {
		//FIXME

		// This code makes the 5 decks of cards that are in order
		newdecks.reserve(125);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				newdecks.push_back(j);
			}
		}
		// This code gets a time-based seed for randomness
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		//The following code shuffles
		shuffle(newdecks.begin(), newdecks.end(), std::default_random_engine(seed));
	}

	void createdealing() { //this function adds all items from the shuffled vector to the dealing pile, one by one. The dealing pile is a stack, so we can pull items from the top
		int loc;
		for (int i = 0; i < 50; i++) {
			loc = newdecks[i];
			dealing.push(loc);
		}
	}

	void deal() {  //This function deals the shuffled cards to the 2 players, in alternating turns
		for (int i = 0; i < 50; i++) {
			if (i / 2 == 0) {
			playing1.push(newdecks[i]);
			}
			else {
			playing2.push(newdecks[i]);
			}
		}
	}

	void war() {
		lootPile.push(display1);
		lootPile.push(display2);
		lootPile.push(remove1());
		lootPile.push(remove2());
		make_move();
	
	}


	void make_move() {
		bool flag = false;
		cout << "gay";
		if (playing1.size() + storage1.size() == 50) {
			flag = true;
			cout << "The winner is player 2" << endl;
		}
		if (playing2.size() + storage2.size() == 50) {
			flag = true;
			cout << "The winner is player 1" << endl;
		}

		while (flag == 0) {
			if (playing1.empty() == 1) {
				move_my_storage();
			}
			else {
				move_other_storage();
			}
			display1 = remove1();
			display_card(display1);
			display2 = remove2();
			display_card(display2);
			if (compare_cards() == 0) {
				storage1.push(display1);
				storage1.push(display2);
				move_my_loot();
				cout << "loop1";

			}
			if (compare_cards() == 1) {
				storage2.push(display1);
				storage2.push(display2);
				move_other_loot();
				cout << "loop2";
			}
			else {
				war();
			}
		}

	}
		

		// initiates a round of play and communicates play-by-play during the round
		// returns true when the game is still in play
		// returns false when the game is over
		// Communicates an appropriate message about whether the user beat the computer






	int remove1(){
		// Precondition: playing1 is not empty 
		// If it is not empty, the function removes a card from PlayingPile1,
		// returning the stored value
		int val;
		if (playing1.empty() == 0) {
			val = playing1.top();
			playing1.pop();
			return val;
		}
	}

	int remove2()
	{
		// Precondition: playing2 is not empty 
		// If it is not empty, the function removes a card from otherPlayingPile,
		// returning the stored value
		int val;
		if (playing2.empty() == 0)
		{
			val = playing2.top();
			playing2.pop();
			return val;
		}
	}

	int display_card(int val)
	{    // displays a card on the screen and returns the value
		cout << val << endl;
		return val;
	}

	bool compare_cards()
	{    // compares displayed card one and displayed card 2 and returns the value according to the result    

		if (display1 > display2)
		{
			return 0;
		}
		else
		{return 1;
		}
	}

	void move_my_loot()
	{    // moves everything from lootPile to storage1  
		int temp;
		while (lootPile.empty() == 0) {
			temp = lootPile.front();
			lootPile.pop();
			storage1.push(temp);
		}
	}

	void move_other_loot()
	{           // moves everything from lootPile to storage2
		int temp;
		while (lootPile.empty() == 0) {
			temp = lootPile.front();
			lootPile.pop();
			storage2.push(temp);
		}

	}

	void move_my_storage()
	{    // moves everything from storage1 to playing1
		int temp;
		while (storage1.empty() == 0) {
			temp = storage1.front();
			playing1.push(temp);
		}
	}

	void move_other_storage()
	{        // moves everything from storage2 to playing2
		int temp;
		while (storage2.empty() == 0) {
			temp = storage2.front();
			playing2.push(temp);
		}
	}












private:
	stack<int> dealing; //This will be the dealing stack pile
	vector<int> newdecks; //This is the ONLY vector you are allowed to use. This single vector may be used for your dealing pile or you can choose to use a stack, 	queue or deque for the dealing pile
	
	stack<int> playing1; //playing pile of first player
	stack<int> playing2; //playing pile of second player

	int display1; //the first currently displayed card
	int display2; //the second currently displayed card

	queue<int> storage1; //storage deck for player1
	queue<int> storage2; //storage deck for player2



	bool currentState;		// keeps track of the state of play
	
	queue<int> lootPile;			// queue, stack, or deque

	


}; 










int main(){
	char stopme;

	War game;
	game.createdealing();
	game.deal();
	game.make_move();

	cin >> stopme; //holds open the window in some cases
	return 0;
}



