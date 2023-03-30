#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/piece.h"

// Implementation for 'piece.h' cchess_piece_init()
cchess_e_result_t cchess_piece_init(cchess_piece_t* piece, cchess_e_piece_type_t type, cchess_e_piece_color_t color, const char** error)
{
    // Check the piece is valid
    if (piece == NULL) 
    {
        // Set the error message
        *error = "Piece is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Initialize the piece
    piece->type     = type;
    piece->color    = color;
    piece->row      = -1;
    piece->col      = '\0';

    // Return OK
    return CCHESS_RES_OK;
}

// Implementation for 'piece.h' cchess_piece_move()
cchess_e_result_t cchess_piece_move(cchess_piece_t* piece, char col, int row, const char** error)
{
    // Check the piece is valid
    if (piece == NULL) 
    {
        // Set the error message
        *error = "Piece is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // TODO: Check the move is valid

    // Move the piece
    piece->col = col;
    piece->row = row;

    // Return OK
    return CCHESS_RES_OK;
}

// Implementation for 'piece.h' cchess_piece_capture()
cchess_e_result_t cchess_piece_capture(cchess_piece_t* piece, const char** error)
{
    // Check the piece is valid
    if (piece == NULL) 
    {
        // Set the error message
        *error = "Piece is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Capture the piece
    piece->col      = '\0';
    piece->row      = -1;
    piece->type     = CCH_PIECE_TYPE_NONE;
    piece->color    = CCH_PIECE_COLOR_NONE;

    // Return OK
    return CCHESS_RES_OK;
}

// Implementation for 'piece.h' cchess_piece_promote()
cchess_e_result_t cchess_piece_promote(cchess_piece_t* piece, cchess_e_piece_type_t type, const char** error)
{
    // Check the piece is valid
    if (piece == NULL) 
    {
        // Set the error message
        *error = "Piece is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Check the piece is a pawn
    if (piece->type != CCH_PIECE_TYPE_PAWN) 
    {
        // Set the error message
        *error = "Cannot promote a non-pawn piece";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Check the row is valid
    if ((piece->color == CCH_PIECE_COLOR_WHITE && piece->row != 7) || (piece->color == CCH_PIECE_COLOR_BLACK && piece->row != 0))
    {
        // Set the error message
        *error = "Pawn promotion attempted on the wrong row.";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Promote the piece
    piece->type = type;

    // Return OK
    return CCHESS_RES_OK;
}

// Implementation for 'piece.h' cchess_piece_print()
cchess_e_result_t cchess_piece_print(cchess_piece_t* piece, const char** error)
{
    // Get the piece type as a string
    const char* piece_type = piece_type_map[piece->type];

    // Check the piece is valid
    if (piece == NULL) 
    {
        // Set the error message
        *error = "Piece is NULL";

        // Return the error code.   
        return CCHESS_RES_ERR;
    }

    // Check the piece type is valid
    if (piece_type == NULL) 
    {
        // Set the error message
        *error = "Piece type is invalid";

        // Return the error code.
        return CCHESS_RES_ERR;
    }

    // Get the piece colour as a string
    const char* piece_color = piece_color_map[piece->color];

    // Check the piece colour is valid
    if (piece_color == NULL) 
    {
        // Set the error message
        *error = "Piece color is invalid";

        // Return the error code.
        return CCHESS_RES_ERR;
        
    }

    // Print the piece location, type and colour
    printf("Square: %c%d, Piece Type: %s, Piece Color: %s\n", piece->col, piece->row, piece_type, piece_color);

    // Return OK
    return CCHESS_RES_OK;
}