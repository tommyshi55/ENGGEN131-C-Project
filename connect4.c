/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
 * Author: Tommy Shi
 * ID: 864140862
*/

/*
 * Task One: Runner up - SecondPlacePrize()
 * This function return the second highest price from the given three input price
 * that is, return the second biggest number among the three input
*/
int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	// Variable initlization
	int prize;

	// Check prize2 and prize3 if prize1 is the greatest
	if (prize1 >= prize2 && prize1 >= prize3) {
		if (prize2 >= prize3) {
			prize = prize2;
		} else {
			prize = prize3;
		}

	// Check prize1 and prize3 if prize2 is the greatest
	} else if (prize2 >= prize3 && prize2 >= prize1) {
		if (prize1 >= prize3) {
			prize = prize1;
		} else {
			prize = prize3;
		}

	// Check prize1 and prize2 if prize3 is the greatest
	} else {
		if (prize1 >= prize2) {
			prize = prize1;
		} else {
			prize = prize2;
		}
	}
	return prize;
}

/*
 * Task Two: Four in a row - FourInARow()
 * This function takes two inputs: an array of integers and the length of the array
 * It returns the index position of the first element in the array that begins a 
 * four-in-a-row sequence of any value
 * If the array does not contain four-in-a-row sequence it returns -1
*/
int FourInARow(int values[], int length)
{
	// Variable initlialisation
	int i;

	// Iterate through the array to find the position of the start of a four-in-a-row
	for (i = 0; i < length - 3; i++) {
		if (values[i] == values[i+1] && values[i] == values[i+2] && values[i] == values[i+3]) {
			return i;
		}
	}

	// If there is no four-in-a-row, return -1
	return -1;
}

/*
 * Task Three: Binary registration - BinaryToDecimal()
 * This function takes an integer input containing only of the digits 0 and 1 representing
 * a binary value, and returns an equvalent decimal value
*/
int BinaryToDecimal(int binary)
{
	// Variable initialisation
	int currentPower = 1;
	int digitLeft = binary;
	int decimal = 0;
	int currentDigit = 0;

	// Iterate through the binary number and get the least significant bit each time
	// and convert it to its decimal value
	while (digitLeft != 0) {
		currentDigit = digitLeft % 10;
		decimal += (currentDigit * currentPower);
		currentPower *= 2;
		digitLeft = digitLeft / 10;
	}

	return decimal;
}

/*
 * Helper function - Sort()
 * This function takes two inputs: an array of type double and the length of the array
 * It uses the bubble sort algorithm to sort the array into ascending order
*/
void Sort(double values[], int length)
{	
	// Variable initialisation
	int i, j;
	double temp;

	// Perform a bubble sort
	for (i = 0; i < length; i++) {
		for (j = 0; j < length - 1 - i; j++) {
			if (values[j] > values[j + 1]) {
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

/*
 * Task Four: Middle player - MedianAbility()
 * This function takes two inputs: an array of type double storing the abilities attribute of the players
 * and the length of the array
 * It returns the median value of the array
*/
double MedianAbility(double abilities[], int length)
{
	// Initialise the variable median
	double median;

	// Sort the array into ascending order using the helper function Sort()
	Sort(abilities, length);

	// Calculate the median according to the length of array
	if (length % 2 == 0) {
		median = (abilities[length / 2] + abilities[length / 2 - 1]) / 2;
	} else {
		median = abilities[length / 2];
	}

	return median;
}

/*
 * Helper Function - RemoveCharacter()
 * This function takes two inputs: an pointer to a character array and an index position
 * It removes the character at the index position in the character array
*/
void RemoveCharacter(char *name, int index)
{
	// Variable intialisation
	unsigned int i;

	// Iterate through the string, remove the character
	// at the index position and shift all the right element
	// to left by 1
	for (i = index; i < strlen(name); i++) {
		name[i] = name[i + 1];
	}
}

/*
 * Task Five: Cheaper sign - RemoveSpaces()
 * This function takes an input of a pointer to a character array, which is a string
 * It removes all the unnecessary space in the string
 * For example: if there are more than one space together, it reduces to only one space
*/
void RemoveSpaces(char *name)
{	
	// Variable initialisation
	int i;

	// Iterate through the string from the back of the string
	// If there is more than one space together, remove the extra spaces
	// until it is left with one space
	for (i = strlen(name) - 1; i > 0; i--) {
		if (name[i] == ' ' && name[i - 1] == ' ') {
			RemoveCharacter(name, i);
		}
	}
}

/*
 * Task Six: A connect four board - InitialiseBoard()
 * This function initialise a connect four board for a given size
 * Set each element in the board as 0 indicating an empty space
 * and set the middle element of the array as 3 indicating a fixed
 * piece for an odd size board, and set the middle 4 elements as 3 
 * indicating fixed pieces
*/
void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	// Variable initialisation
	int middle = size / 2;
	int i, j;

	// Create the board with given size and fill with empty spaces(0)
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}

	// Set the middle fixed pieces according to the size
	if (size % 2 == 0) {
		board[middle][middle] = 3;
		board[middle - 1][middle] = 3;
		board[middle][middle - 1] = 3;
		board[middle - 1][middle - 1] = 3;
	} else {
		board[middle][middle] = 3;
	}
}

/*
 * Task Seven: Place token - AddMoveToBoard()
 * This function takes 7 inputs: a 2d array representing the connect 4 board, an integer stores the size of the board,
 * a character representing the side of the input move, an integer of the input move, an integer indicates which player has
 * the current move, and two pointers to integers which point to the variables that store the final row and column position
 * of the token after making the move. 
 * It places the current player's token according to the move into the connect 4 board and stores the final row and column
 * positions of the token where the token is placed in the board. If the player makes an invalid move, the board would not
 * change and the row and column positions of the placed token would both be -1
*/
void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{	
	// Variable initialisation
	int stopped = 0;
	int currentIndex;

	// Add the move according to the side
	if (side == 'N') {
		// First check for invalid move
		if (board[0][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;

		// If the move is valid, determine where the token will end up to
		} else {
			currentIndex = 0;
			while (!stopped && currentIndex < size - 1) {
				if (board[currentIndex + 1][move] != 0) {	
					stopped = 1;
				} else {
					currentIndex++;
				}
			}
			board[currentIndex][move] = player;
			*lastRow = currentIndex;
			*lastCol = move;
		}
	} else if (side == 'S') {
		// Check for invalid move
		if (board[size - 1][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;

		// If the move is valid, determine where the token will end up to
		} else {
			currentIndex = size - 1;
			while (!stopped && currentIndex > 0) {
				if (board[currentIndex - 1][move] != 0) {
					stopped = 1;
				} else {
					currentIndex--;
				}
			}
			board[currentIndex][move] = player;
			*lastRow = currentIndex;
			*lastCol = move;
		}
	} else if (side == 'W') {
		// Check for invalid move
		if (board[move][0] != 0) {
			*lastRow = -1;
			*lastCol = -1;

		// If the move is valid, determine where the token will end up to
		} else {
			currentIndex = 0;
			while (!stopped && currentIndex < size - 1) {
				if (board[move][currentIndex + 1] != 0) {
					stopped = 1;
				} else {
					currentIndex++;
				}
			}
			board[move][currentIndex] = player;
			*lastRow = move;
			*lastCol = currentIndex;
		}
	} else if (side == 'E') {
		// Check for invalid move
		if (board[move][size - 1] != 0) {
			*lastRow = -1;
			*lastCol = -1;

		// If the move is valid, determine where the token will end up to
		} else {
			currentIndex = size - 1;
			while (!stopped && currentIndex > 0) {
				if (board[move][currentIndex - 1] != 0) {
					stopped = 1;
				} else {
					currentIndex--;
				}
			}
			board[move][currentIndex] = player;
			*lastRow = move;
			*lastCol = currentIndex;
		}
	}
}

/*
 * Task Eight: Game over, man! - CheckGameOver()
 * This function takes a 2d array representing the board, the size of the board, the last player placed the token
 * and row and column position of the last placed token as the inputs. It checks whether the last player's move
 * makes it win the connect four game
 * If the last placed token makes a four-in-a-row in either the horizontal, vertical or diagonal direction, or the
 * token makes the board full, the last player wins the game and this function returns the number representing the
 * last player
 * If the last player do not win the game, it returns 0
*/
int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{	
	// Variable initialisation
	int isFull = 1;
	int i, j;

	// Iterate through the board and check if the board is full
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				isFull = 0;
			}
		}
	}

	// Check whether there is four-in-a-row in vertical and horizontal direction for last player
	// If so, return the last player as winner
	for (i = 0; i < size - 3; i++) {
		if (board[i][col] == player && board[i][col] == board[i + 1][col] && board[i][col] == board[i + 2][col] && board[i][col] == board[i + 3][col]) {
			return player;
		} else if (board[row][i] == player && board[row][i] == board[row][i + 1] && board[row][i] == board[row][i + 2] && board[row][i] == board[row][i + 3]) {
			return player;
		}
	}

	// Determine the starting point of the top left to bottom right diagonal that is going to be checked
	i = row;
	j = col;
	while (i != 0 && j != 0) {
		i--;
		j--;
	}

	// Check whether there is a four-in-a-row at the top left to bottom right diagonal for the last player
	// If so, return the last player as winner
	while (i < size - 3 && j < size - 3) {
		if (board[i][j] == player && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
			return player;
		} else {
			i++;
			j++;
		}
	}

	// Determine the starting point of the bottom left to top right diagonal that is going to be checked
	i = row;
	j = col;
	while (i != size - 1 && j != 0) {
		i++;
		j--;
	}

	// Check whether there is a four-in-a-row at the bottom left to top right diagonal for the last player
	// If so, return the last player as winner
	while (i > 2 && j < size - 3) {
		if (board[i][j] == player && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
			return player;
		} else {
			i--;
			j++;
		}
	}

	// If there is no four-in-a-row, and the board is full, the winner is the last player
	// Otherwise there is no winner yet
	if (isFull) {
		return player;
	} else {
		return 0;
	}
}

/*
 * Task Nine: Pretty board - GetDisplayBoardString()
 * This function takes the current board and size as inputs, as well as a string buffer
 * It generates a special formatted string representation of the board and stores it
 * into the string buffer, where an empty space(0) is represented as '.', the token of 
 * player 1 is represented as 'X', and the token of player 2 is represented as 'O', as
 * well as '#' represents the fixed piece in the middle
*/
void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{	
	// Variable initialisation
	int i, j, element;
	char strToAdd[100] = "";

	// Store the first top row of the board representing the N side
	boardString[0] = '-';
	boardString[1] = '-';
	boardString[2] = '\0';
	for (i = 0; i < size; i++) {
		strcat(boardString, "N");
	}
	strcat(boardString, "--\n");

	// Store the second row representing the move
	strcat(boardString, "--");
	for (i = 0; i < size; i++) {
		sprintf(strToAdd, "%d", i);
		strcat(boardString, strToAdd);
	}
	strcat(boardString, "--\n");

	// store the main component of the board - the empty spaces, tokens, fixed place(s)
	// and annotation representing the move of W side and E side
	for (i = 0; i < size; i++) {
		sprintf(strToAdd, "W%d", i);
		strcat(boardString, strToAdd);
		for (j = 0; j < size; j++) {
			element = board[i][j];
			if (element == 0) {
				strcat(boardString, ".");
			} else if (element == 1) {
				strcat(boardString, "X");
			} else if (element == 2) {
				strcat(boardString, "O");
			} else if (element == 3) {
				strcat(boardString, "#");
			}
		}
		sprintf(strToAdd, "%dE\n", i);
		strcat(boardString, strToAdd);
	}

	// Store the second last row representing the move of S side
	strcat(boardString, "--");
	for (i = 0; i < size; i++) {
		sprintf(strToAdd, "%d", i);
		strcat(boardString, strToAdd);
	}
	strcat(boardString, "--\n");

	// Store the last row representing the S side
	strcat(boardString, "--");
	for (i = 0; i < size; i++) {
		strcat(boardString, "S");
	}
	strcat(boardString, "--\n");
}

/*
 * Task Ten: Bots!
 * The following two functions: GetMoveBot1() and GetMoveBot2() both take a board and size, 
 * the player that it represents as well as the pointer to the side and move of its chosen
 * move. They generates a side and move according to the current board and store them back to
 * the variable where the two pointers pointing to
 * The bots can use any strategies but have to at least be able to make a valid move every time,
 * and make a winning move for themselves if there is one
*/

/*
 * GetMoveBot1()
 * This bot first search through the board and find every valid moves that it can make
 * It then check whether those moves are winning move. If so, make the move. 
 * If there is no winning move, it will try to find a move that can stop its opponent 
 * from winning
 * Otherwise, the bot makes a purely random valid move
*/
void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// Variable initialisation
	// randSide and randMove stores the randomly generated side and move
	// the array validNMove, validSMove, validWMove and validEMove stores the valid move of each side
	// numNMove, numSMove, numWMove and numEMove stores the number of valid move of each side
	// array validSide stores the valid side
	// numSide stores the number of valid side
	int i, j, randSide, randMove;
	int validNMove[MAX_SIZE] = {0};
	int validSMove[MAX_SIZE] = {0};
	int validWMove[MAX_SIZE] = {0};
	int validEMove[MAX_SIZE] = {0};
	char validSide[4];
	int numNMove = 0;
	int numSMove = 0;
	int numWMove = 0;
	int numEMove = 0;
	int numSide = 0;
	int row = 0;
	int col = 0;
	int boardCopy[MAX_SIZE][MAX_SIZE];
	
	// Set the seed of the random number generator to the current time
	srand((unsigned int)time(NULL));

	// Make a copy of the board
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			boardCopy[i][j] = board[i][j];
		}
	}

	// Check for each side, store and count the valid moves of each side and valid sides
	for (i = 0; i < size; i++) {
		// Check N side
		if (board[0][i] == 0) {
			validNMove[numNMove] = i;
			numNMove++;
			if (numNMove == 1) {
				validSide[numSide] = 'N';
				numSide++;
			}
		}

		// Check S side
		if (board[size - 1][i] == 0) {
			validSMove[numSMove] = i;
			numSMove++;
			if (numSMove == 1) {
				validSide[numSide] = 'S';
				numSide++;
			}
		}

		// Check W side
		if (board[i][0] == 0) {
			validWMove[numWMove] = i;
			numWMove++;
			if (numWMove == 1) {
				validSide[numSide] = 'W';
				numSide++;
			}
		}

		// Check E side
		if (board[i][size - 1] == 0) {
			validEMove[numEMove] = i;
			numEMove++;
			if (numEMove == 1) {
				validSide[numSide] = 'E';
				numSide++;
			}
		}
	}

	// Iterate through the valid N move and make winning move if there is one
	// otherwise, find and make valid move to block opponent from winning
	for (i = 0; i < numNMove; i++) {
		// Find winning move
		AddMoveToBoard(boardCopy, size, 'N', validNMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'N';
			*move = validNMove[i];
			return;
		}
		boardCopy[row][col] = 0;

		// Find move to block opponent's winning move
		AddMoveToBoard(boardCopy, size, 'N', validNMove[i], 3 - player, &row, &col);
		if (CheckGameOver(boardCopy, size, 3 - player, row, col)) {
			*side = 'N';
			*move = validNMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid S move and make winning move if there is one
	// otherwise, find and make valid move to block opponent from winning
	for (i = 0; i < numSMove; i++) {
		// Find winning move
		AddMoveToBoard(boardCopy, size, 'S', validSMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'S';
			*move = validSMove[i];
			return;
		}
		boardCopy[row][col] = 0;

		// Find move to block opponent's winning move
		AddMoveToBoard(boardCopy, size, 'S', validSMove[i], 3 - player, &row, &col);
		if (CheckGameOver(boardCopy, size, 3 - player, row, col)) {
			*side = 'S';
			*move = validSMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid W move and make winning move if there is one
	// otherwise, find and make valid move to block opponent from winning
	for (i = 0; i < numWMove; i++) {
		// Find winning move
		AddMoveToBoard(boardCopy, size, 'W', validWMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'W';
			*move = validWMove[i];
			return;
		}
		boardCopy[row][col] = 0;

		// Find move to block opponent's winning move
		AddMoveToBoard(boardCopy, size, 'W', validWMove[i], 3 - player, &row, &col);
		if (CheckGameOver(boardCopy, size, 3 - player, row, col)) {
			*side = 'W';
			*move = validWMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid E move and make winning move if there is one
	// otherwise, find and make valid move to block opponent from winning
	for (i = 0; i < numEMove; i++) {
		// Find winning move
		AddMoveToBoard(boardCopy, size, 'E', validEMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'E';
			*move = validEMove[i];
			return;
		}
		boardCopy[row][col] = 0;

		// Find move to block opponent's winning move
		AddMoveToBoard(boardCopy, size, 'E', validEMove[i], 3 - player, &row, &col);
		if (CheckGameOver(boardCopy, size, 3 - player, row, col)) {
			*side = 'E';
			*move = validEMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// If there is no winning move and move to block opponent, make a random move
	randSide = rand() % numSide;
	if (validSide[randSide] == 'N') {
		randMove = rand() % numNMove;
		*side = 'N';
		*move = validNMove[randMove];
	} else if (validSide[randSide] == 'S') {
		randMove = rand() % numSMove;
		*side = 'S';
		*move = validSMove[randMove];
	} else if (validSide[randSide] == 'W') {
		randMove = rand() % numWMove;
		*side = 'W';
		*move = validWMove[randMove];
	} else {
		randMove = rand() % numEMove;
		*side = 'E';
		*move = validEMove[randMove];
	}
}

/*
 * GetMoveBot2()
 * This bot search through the entire board to find every possible valid move
 * It then check whether there is winning move, if so, make the move. 
 * Unlike the previous bot, it does not check for its opponent's winning moves therefore
 * it does not stop its opponent from winning
 * Otherwise, the bot chooses a purely random valid move
*/
void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// Variable initialisation
	// randSide and randMove stores the randomly generated side and move
	// the array validNMove, validSMove, validWMove and validEMove stores the valid move of each side
	// numNMove, numSMove, numWMove and numEMove stores the number of valid move of each side
	// array validSide stores the valid side
	// numSide stores the number of valid side
	int i, j, randSide, randMove;
	int validNMove[MAX_SIZE] = {0};
	int validSMove[MAX_SIZE] = {0};
	int validWMove[MAX_SIZE] = {0};
	int validEMove[MAX_SIZE] = {0};
	char validSide[4];
	int numNMove = 0;
	int numSMove = 0;
	int numWMove = 0;
	int numEMove = 0;
	int numSide = 0;
	int row = 0;
	int col = 0;
	int boardCopy[MAX_SIZE][MAX_SIZE];
	
	// Set the seed of the random number generator to the current time
	srand((unsigned int)time(NULL));

	// Make a copy of the board
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			boardCopy[i][j] = board[i][j];
		}
	}

	// Check for each side, store and count the valid moves of each side and valid sides
	for (i = 0; i < size; i++) {
		// Check N side
		if (board[0][i] == 0) {
			validNMove[numNMove] = i;
			numNMove++;
			if (numNMove == 1) {
				validSide[numSide] = 'N';
				numSide++;
			}
		}

		// Check S side
		if (board[size - 1][i] == 0) {
			validSMove[numSMove] = i;
			numSMove++;
			if (numSMove == 1) {
				validSide[numSide] = 'S';
				numSide++;
			}
		}

		// Check W side
		if (board[i][0] == 0) {
			validWMove[numWMove] = i;
			numWMove++;
			if (numWMove == 1) {
				validSide[numSide] = 'W';
				numSide++;
			}
		}

		// Check E side
		if (board[i][size - 1] == 0) {
			validEMove[numEMove] = i;
			numEMove++;
			if (numEMove == 1) {
				validSide[numSide] = 'E';
				numSide++;
			}
		}
	}

	// Iterate through the valid N move and make winning move if there is one
	for (i = 0; i < numNMove; i++) {
		AddMoveToBoard(boardCopy, size, 'N', validNMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'N';
			*move = validNMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid S move and make winning move if there is one
	for (i = 0; i < numSMove; i++) {
		AddMoveToBoard(boardCopy, size, 'S', validSMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'S';
			*move = validSMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid W move and make winning move if there is one
	for (i = 0; i < numWMove; i++) {
		AddMoveToBoard(boardCopy, size, 'W', validWMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'W';
			*move = validWMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// Iterate through the valid E move and make winning move if there is one
	for (i = 0; i < numEMove; i++) {
		AddMoveToBoard(boardCopy, size, 'E', validEMove[i], player, &row, &col);
		if (CheckGameOver(boardCopy, size, player, row, col)) {
			*side = 'E';
			*move = validEMove[i];
			return;
		}
		boardCopy[row][col] = 0;
	}

	// If there is no winning move and move to block opponent, make a random move
	randSide = rand() % numSide;
	if (validSide[randSide] == 'N') {
		randMove = rand() % numNMove;
		*side = 'N';
		*move = validNMove[randMove];
	} else if (validSide[randSide] == 'S') {
		randMove = rand() % numSMove;
		*side = 'S';
		*move = validSMove[randMove];
	} else if (validSide[randSide] == 'W') {
		randMove = rand() % numWMove;
		*side = 'W';
		*move = validWMove[randMove];
	} else {
		randMove = rand() % numEMove;
		*side = 'E';
		*move = validEMove[randMove];
	}
}