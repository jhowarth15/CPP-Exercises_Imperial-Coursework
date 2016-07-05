void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);

bool is_complete(char board[9][9]);

bool check_row(char board[9][9], int row);
bool check_col(char board[9][9], int col);
bool check_box(char board[9][9], int row, int col);

bool make_move(char position[], char digit, char board[9][9]);

bool save_board(const char *filename, char board[9][9]);

bool solve_board(char board[9][9]);

bool solve_board(char board[9][9], int& count);

