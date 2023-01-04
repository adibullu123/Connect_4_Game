# Connect_4_Game
This is a C++ program that implements a game called "Connect 4", in which players take turns placing markers on a game board until either player gets four of their markers in a row horizontally, vertically, or diagonally, or until the game board is full.


-->Working of the code
1--> The main function begins by initializing a 2D array called mark with empty spaces, and asking the player to choose their marker. The computer's marker is then set  to the other marker. The game board is displayed using the printtable function.

2--> A loop is then entered that will iterate for a maximum of 21 rounds (the maximum number of rounds that can be played before the game board is full). In each        iteration of the loop, the player is asked to enter the coordinates of the space they want to place their marker on. The input is checked to make sure it is valid, and the marker is placed on the game board. The game board is then displayed using the printtable function, and the wincheck function is called to check if the player has won. If the player has won, the game ends and a message is displayed announcing the player as the winner.

3--> If the player has not won, it is the computer's turn. The compchoice function is called to choose a space for the computer's marker. The chosen space is marked with the computer's marker, and the game board is displayed using the printtable function. The wincheck function is then called to check if the computer has won. If the computer has won, the game ends and a message is displayed announcing the computer as the winner.

4--> The loop continues until either a player has won, or the game board is full and no player has won. If the game board is full and no player has won, the game ends in a draw.

5--> The compchoice function chooses a space for the computer's marker by generating random coordinates until it finds an empty space on the game board. The printtable function displays the current state of the game board by printing the characters in the mark array. The wincheck function checks if either player has won by scanning the game board for four consecutive markers belonging to the same player. If it finds four consecutive markers, it returns true, indicating that the player has won. Otherwise, it returns false.
