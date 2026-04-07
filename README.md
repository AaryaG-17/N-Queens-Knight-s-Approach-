# N-Queens-Knight's-Approach-
An attempt to find another way to solve the N queens problem

The N-Queen's problem:
Place 'N' queens on a 'NxN' chessboard so that no queens are in a position to attack any other queen.
That is, any queen on the chessboard should NOT be in the same row, same column, or same diagonal as of any other queens on the chessboard

Following is the algorithm of **this** approach:

1.	Consider an N × N chessboard. Let the board positions be represented by coordinates (row, column). 
2.	Place the first queen on the first square of the chessboard. 
3.	From the position of the last placed queen, determine all eight possible knight moves. [IMPORTANT: The chessboard is assumed to be torodial, **BUT** only for rows and columns. From any given square, there always are 8 squares to which a knight can move, as we assume here, that the rows and columns wrap around. That is, going right from square (3,8) will end up on square (3,1) and vice-versa. Going up from square (1,4) will end up on square (8,4) and vice-versa.
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

This attempt does **NOT** output all the solutions. Because in any valid combnation, if a queen is placed at a distance farther than a knight's move from a previously placed queen, the algorithm will not be able to traverse to that square and hence will not get that solution.

The added code file is in C++ language which computes the combinations using this method, of placing 8 queens on a '8x8' chessboard in a valid way.
For an 8x8 chesboard, there are 12 FUNDAMETAL solutions. Each fundamental solution can be rotated by a certain angle or reflected on any if its sides to get more solutions. Counting all of those increases the solution count to 92.  
This approach, is able to compute 4, out of the 12 FUNDAMENTAL SOLUTIONS.
