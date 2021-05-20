# Warnsdorff's Algorithm for Knight's Tour Problem

The Knights Tour is a path that a knight can take on a chess board in order to hit every single square exactly once. It is an example of a Hamiltonian path on a graph G(V, E) where V is all the squares on a chess board and every vertex has an edge to all the vertices corresponding to the edges that are reachable by a knight.

The KnightsTour class contains two methods with different algorithms to calculate such a tour for varying sized chessboards. The tour can be printed as a nxn board where the values at the different squares represent where the knight moves. So the knight started at the square 1, then went to 2, 3, and so on until it hit every square.

I implemented both Warnsdorff’s algorithm and a more simple backtracking algorithm to solve this problem. Warnsdorff’s algorithm is predicated on the aptly named Warnsdorff’s Rule: a valid tour will be found by always moving to the square with the minimum degree. In this case the degree of a square is the number of positions a knight can move to from that square. The backtracking algorithm simply keeps trying moves until gets a correct path or it gets to a point where a tour is impossible and it must backtrack.


There are two executables: project_perf and project_tests that you can generate by moving into the src directory and typing cmake CMakeList.txt into the command line.

project_perf runs the performance evaluation. It takes a single command line argument which specifies which test to run. The valid options are 1 or 2, so you can type either ./project_perf 1 or ./project_perf 2. The first will evaluate both Warnsdorff’s and the backtracking algorithm over a small number of board sizes. The second will evaluate just Warnsdorff’s algorithm but over much larger boards.

project_tests runs the unit tests for the project. These include a variety of tests to ensure the functionality of both Warnsdorff’s and the backtracking algorithm.


The file Knights_Tour.pdf contains more detailed information regarding the implementation and results of this project.