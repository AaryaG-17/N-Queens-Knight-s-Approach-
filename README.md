# N-Queens-Knight's-Approach-
An attempt to find another way to solve the N queens problem

The N-Queen's problem:
Place 'N' queens on a 'NxN' chessboard so that no queens are in a position to attack any other queen.
That is, any queen on the chessboard should NOT be in the same row, same column, or same diagonal as of any other queens on the chessboard.

This problem is typically solved using backtracking (also called Depth-First-Search).

Following is the algorithm of this approach:

1.	Consider an N × N chessboard. Let the board positions be represented by coordinates (row, column). 
2.	Place the first queen on the first square of the chessboard. 
3.	From the position of the last placed queen, determine all eight possible knight moves. 
4.	For each of these squares, check whether placing a queen there is valid.
A square is valid if it is not in the same row, column, or diagonal as any previously placed queen. 
5.	Select the first valid square and place the next queen there. 
6.	Repeat steps 3–5 for placing the next queen using the knight-move positions of the most recently placed queen. 
7.	If no valid square exists for the next queen, backtrack to the previous queen and place it in the next valid knight-move position. 
8.	Continue the process of placement and backtracking until either: all N queens are successfully placed, or no more valid knight-move positions remain for earlier queens. 
9.	Whenever N queens are placed successfully, store the configuration in the result set (RS). 
10.	Move the first queen to the next square of the chessboard and repeat the entire procedure. 
11.	Continue this process until the first queen has been placed on every square of the chessboard and all possibilities have been explored. 
12.	Output all configurations stored in the result set (RS) and the total number of valid combinations.
