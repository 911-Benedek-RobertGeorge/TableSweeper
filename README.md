# TableSweepers!
It is a collaborative implementation of the classical [Minesweeper game](https://www.google.com/search?q=play+minesweeper)! 
1. The program reads the size of the playing field, number of mines and player information from an input file. The included `input.txt` file specifies a playing field of `8 x 8` (the playing area is always square in shape), a number of `10` mines and four players, named `Alice`, `Bob`, `Carol` and `Darryl`. The input file is presumed correct. The mines are laid out randomly within the playing field.
2. The program creates a new window for each player, having the player's name in its title. Each window includes the following elements:
* A  QTableWidget with a custom model where the minefield is represented. The table will include a header that allows identifying each row/column, like in the photo below. Table cells have a square shape. When starting the game, all cells are unrevealed and have a light green background.
* A component that allows the user to enter a new coordinate (e.g. such as a [QLineEdit](https://doc.qt.io/qt-5/qlineedit.html))
* Two buttons, one labelled `Reveal` and the other `Mark Mine`.
3.  On their turn, each player enters a coordinate into their window's input field (e.g. `B4`) and presses one of the buttons. 
* Pressing `Mark Mine` marks the corresponding table cell as a mine by placing an `*` into the corresponding cell and changing its background to orange if its a mine, otherwise the player will get a message and will be eliminated  and changing its background to red  .
* Pressing `Reveal` on a cell that contains a mine defeats the player; they receive a defeat message through a [QMessageBox](https://doc.qt.io/qt-5/qmessagebox.html) and are eliminated from the game (either close their window or disable all controls). The game continues for the remaining players.
* Pressing `Reveal` on a cell that does not contain a mine reveals it by changing its background to light blue and showing the number of mines adjacent to it (on row, column or diagonal).  
* Pressing a button while an invalid coordinate is filled in (outside of playing area, already revealed cell, or marking a revealed cell as a mine) results in an error message.
4.  Cells marked or revealed by one player are immediately updated across all player windows. 
5.  Players take turns one at a time, in the order given in the input file. This is implemented by disabling the buttons within the windows of the players who are out of turn. 
6.  The game ends when all players have been defeated or when all mines were correctly marked, the winner is the one who discovered corectly the most bombs.

 

 
<img width="488" alt="mines" src="https://github.com/911-Benedek-RobertGeorge/TableSweeper/blob/02946914132d7b840616b915a237c7558b79a44b/Screenshot_2.png">
