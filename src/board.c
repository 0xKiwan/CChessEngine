#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/piece.h"
#include "../inc/board.h"

// Implementation for 'board.h' cchess_board_init()
cchess_e_result_t cchess_board_init(cchess_board_t* board, const char** error)
{
    // Check the board is valid
    if (board == NULL) 
    {
        // Set the error message
        *error = "Board is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Used to track how many pieces have been initialized
    int piece_count = 0;

    // Loop through rows
    for (int row = 0; row < 8; row++)
    {
        // Loop through columns
        for (char col = 'a'; col < 'i'; col++)
        {
            // Will store results of function calls
            cchess_e_result_t res;

            // Get column index from character
            int col_index = (int)(col - 'a');

            // Determine the colour of the piece
            cchess_e_piece_color_t piece_color  = (row < 2) ? CCH_PIECE_COLOR_WHITE : (row > 5) ? CCH_PIECE_COLOR_BLACK : CCH_PIECE_COLOR_NONE;

            // Determine the type of the piece
            cchess_e_piece_type_t piece_type    = board_initial_layout[row][col_index];

            // Initialize the piece
            res = cchess_piece_init(&board->squares[row][col_index], piece_type, piece_color, error);

            // Move the piece to its starting position
            res = cchess_piece_move(&board->squares[row][col_index], col, row, error);

            // Print the piece
            res = cchess_piece_print(&board->squares[row][col_index], error);

            // Increment piece count
            piece_count++;
        }
    }

    // Return OK
    return CCHESS_RES_OK;
}