#ifndef _CCHESS_BOARD_H_
#define _CCHESS_BOARD_H_

/**
 * Represents the current turn.
*/
typedef enum _cchess_e_turn_t
{
    CCH_TURN_WHITE,     // White's turn
    CCH_TURN_BLACK,     // Black's turn
} cchess_e_turn_t;


/**
 * Represents a chess board.
 */
typedef struct _cchess_board_t
{
    cchess_piece_t squares[8][8];   // A 2D array of pieces, this represents the board.
    cchess_e_turn_t turn;           // The current turn, white or black.
    bool white_king_castle;         // White can castle kingside.
    bool white_queen_castle;        // White can castle queenside.
    bool black_king_castle;         // Black can castle kingside.
    bool black_queen_castle;        // Black can castle queenside.
    int halfmove_clock;             // The number of halfmoves since the last capture or pawn advance.
    int fullmove_number;            // The number of the full move. It starts at 1, and is incremented after Black's move.
} cchess_board_t;

/**
 * Represents the layout of a chess board at the start of a game.
 * This is used to initialize a board without having to write a huge switch statement.
 */
static const cchess_e_piece_type_t board_initial_layout[8][8] = {
    { CCH_PIECE_TYPE_ROOK, CCH_PIECE_TYPE_KNIGHT,   CCH_PIECE_TYPE_BISHOP,  CCH_PIECE_TYPE_QUEEN,   CCH_PIECE_TYPE_KING, CCH_PIECE_TYPE_BISHOP, CCH_PIECE_TYPE_KNIGHT,  CCH_PIECE_TYPE_ROOK },
    { CCH_PIECE_TYPE_PAWN, CCH_PIECE_TYPE_PAWN,     CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN, CCH_PIECE_TYPE_PAWN,   CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN },
    { CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,     CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,   CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE },
    { CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,     CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,   CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE },
    { CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,     CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,   CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE },
    { CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,     CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE, CCH_PIECE_TYPE_NONE,   CCH_PIECE_TYPE_NONE,    CCH_PIECE_TYPE_NONE },
    { CCH_PIECE_TYPE_PAWN, CCH_PIECE_TYPE_PAWN,     CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN, CCH_PIECE_TYPE_PAWN,   CCH_PIECE_TYPE_PAWN,    CCH_PIECE_TYPE_PAWN },
    { CCH_PIECE_TYPE_ROOK, CCH_PIECE_TYPE_KNIGHT,   CCH_PIECE_TYPE_BISHOP,  CCH_PIECE_TYPE_QUEEN,   CCH_PIECE_TYPE_KING, CCH_PIECE_TYPE_BISHOP, CCH_PIECE_TYPE_KNIGHT,  CCH_PIECE_TYPE_ROOK },
};

/**
 * Used to initialize the chess board.
 * 
 * @param board The board to initialize.
 * 
 * @return CCHESS_RES_OK if the board was initialized successfully.
*/
cchess_e_result_t cchess_board_init(cchess_board_t *board, const char** error);

/**
 * Used to print the board to the console.
 * 
 * @param board The board to print.
 * 
 * @return CCHESS_RES_OK if the board was printed successfully.
*/
cchess_e_result_t cchess_board_print(cchess_board_t *board, const char** error);



#endif // _CCHESS_BOARD_H_