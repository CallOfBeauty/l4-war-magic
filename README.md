# L4: Game of War
## Code designed to learn to use stacks, queues, and deques correctly

## *FIXME: Author(s) of primary logic and code: Jan Pearce, Dimitrios Ntentia

## Author of deck and sort: Jan Pearce, Berea College

### Authors: Dimitrios Ntentia


### Starter files have been provided for you in C++

1. **HIGH LEVEL DESIGN**
*Complete the high-level design components in the Google Doc.*

2. **CRC Cards**
*Complete the CRC Card in the linked Google Doc. Turn on sharing and paste link to completed Google Doc here.*

https://docs.google.com/document/d/1MPGQYeM0S5UIHAo4ZZ3QKMOWwibVz-POzBw4IqXPdOM/edit?usp=sharing


3. **Big O Analysis**
*Please analyze the Big O of all of the methods of the War class, including constructors. Hint: Your game uses 5 sets of cards, so for most, but possibly not all, of your methods, the input size (n) is the number of possible cards in the pile, but be sure you understand that this number should not be thought of as a constant! Anyone at anytime could possibly change either the number of decks used or even the number of cards in the deck for a game of War. (This is not far-fetched, the number of cards in a standard deck is 52 if you exclude Jokers or 54 if you include Jokers. A standard Tarot deck of cards has 78 cards. The normal Uno deck of cards has 108 cards. And, there are other decks...)*

void createdealing(): It is a standard The loop executes 51 times, so the sequence of statements also executes 51 times. 
						Since the statements are O(1), the total time for the for loop is 51 * O(1), which is O(1) overall.

void deal(): It is a standard The loop executes 51 times, so the sequence of statements also executes 51 times. 
						Since the statements are O(1), the total time for the for loop is 51 * O(1), which is O(1) overall.

void deal(): It is a standard The loop executes 51 times, so the sequence of statements also executes 51 times. 
						Since the statements are O(1), the total time for the for loop is 51 * O(1), which is O(1) overall.

int remove1(): Since playing1 is a stack, and we are deleting a the top element, the time complexity of removal is O(1)
int remove2(): Since playing2 is a stack, and we are deleting a the top element, the time complexity of removal is O(1)
int display_card(int val): The function just prints and returns the val given, therefore the time complexity is O(1)
bool compare_cards(): This function uses the diplay card function to compare two cards, therefore the complexity is again O(1)
void move_my_loot(): Since the lootpile is a queue, the time complexity for deletion is O(1) the same goes for storage, which is a queue as well
void move_other_loot(): Since the lootpile is a queue, the time complexity for deletion is O(1) the same goes for storage, which is a queue as well
void move_my_storage(): The function deletes an item from a queue and adds to a stack. Bot operations have ammount to a O(1) time complexity
void move_other_storage(): The function deletes an item from a queue and adds to a stack. Bot operations have ammount to a O(1) time complexity

void war(): This function funs other functions. Therefore adding the complexities of the other functions, its complexity is: O(n) because the function calls the makemove() function
void make_move(): We have a while loop that will iterate a number of times. The worst case senario here, is that the loop runs forever, as the game may continue till one player
						is the winner. Threrefore the complexity here is linear and is O(n)




4. **PROCESS SUMMARY**
*Briefly summarize your design and implementation process,
including how much your initial design plan evolved,
the final results you achieved, and the amount of time you spent
as a programmer or programmers in accomplishing these results.
This should be one or at most two paragraphs.*

Many things changed from my initial design process. I started the coding part, thinking that I will use a deque for my storage for example, but then I realized that I did not need to and I could just use a queue. My design process changed, because of the already provided design process. When I was doing the sketches and the graphs, I had not see the provided design. The idea I had was that I would have functions representing rules and combine everything in a big function inside the class. But what I ended up doing is creating small functions for the small moves and then creating the rules and logic in a big function. I spent most of my time, about 6 hours on studying the different sections and rules, and I have to say that I still don’t fully understand the game.




5. **DESIGN CHALLENGES**
*Describe the primary conceptual challenges that you encountered
in trying to complete this lab and what might have made the
lab easier for you.*

I would appreciate having a visualization or even a demonstration in class (class activity( to first understand the game and then start coding it. Because the template we were given was dictating most of our logic and contianing our creativity on the algorithm.

6. **ERRORS**
*List in bulleted form of all known errors
and deficiencies with a very brief explanation.*

- Sometimes the code provided gives and index out of range error that points to the library. I have noticed that if you run it 3 times it will ignore the error and run correctly

8. **OPTIONAL ENHANCMENT**
*If you chose to make an optional enhancement to deal with cycles,
discuss what rule you added, and why you added it. Also, discuss
how well your rule worked.*

I did not do the optional enhancement


9. **LEARNING AND REACTION**
*A paragraph or so of your own comments
on what you learned and your reactions to this lab.*

I am very happy with my progress on this lab and the complexity of the algorithm. I did like the fact that we apply code into a real life sitaution and we create a game that has rules that when followed show the winner of the game. However I did not like the fact that the description was so complex, in terms of the decks and how they are arranged. 

10. **INTEGRITY STATEMENT**
*Please briefly describe ALL help you received and
all help you gave to others in completing this lab.
Also list all other references below.*

I did not receive any help in completing this lab

11. **Pairwork statement**
If you worked in a pair of programmers, you are required to use good pair programming practices, always working together and not using a divide and conquer technique in which only one of you does the work and learns. Also, the two programmers roles should be switched frequently--around every 20 minutes or so. If you worked alone, please say so. If you worked in a pair, please describe how you worked together.

I worked alone

## References:
- This repo contains original deck and sort code by Jan Pearce
- No other works were used to complete this lab
