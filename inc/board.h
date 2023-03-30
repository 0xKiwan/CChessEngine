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
    enum cchess_e_turn_t turn;      // The current turn, white or black.
    bool white_king_castle;         // White can castle kingside.
    bool white_queen_castle;        // White can castle queenside.
    bool black_king_castle;         // Black can castle kingside.
    bool black_queen_castle;        // Black can castle queenside.
    int halfmove_clock;             // The number of halfmoves since the last capture or pawn advance.
    int fullmove_number;            // The number of the full move. It starts at 1, and is incremented after Black's move.
} cchess_board_t;




#endif // _CCHESS_BOARD_H_