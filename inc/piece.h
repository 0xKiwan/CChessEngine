#ifndef _CCHESS_PIECE_H_
#define _CCHESS_PIECE_H_

/**
 * Represents the type of piece.
*/
typedef enum _cchess_e_piece_type_t
{
    CCH_PIECE_TYPE_PAWN,        // Pawn
    CCH_PIECE_TYPE_KNIGHT,      // Knight
    CCH_PIECE_TYPE_BISHOP,      // Bishop
    CCH_PIECE_TYPE_ROOK,        // Rook
    CCH_PIECE_TYPE_QUEEN,       // Queen
    CCH_PIECE_TYPE_KING,        // King
    CCH_PIECE_TYPE_NONE,        // None, used for empty squares
} cchess_e_piece_type_t;

/**
 * Represents the color of piece.
 */
typedef enum _cchess_e_piece_color_t
{
    CCH_PIECE_COLOR_WHITE,      // White
    CCH_PIECE_COLOR_BLACK,      // Black
    CCH_PIECE_COLOR_NONE,       // None, used for empty squares
} cchess_e_piece_color_t;

/**
 * Represents a piece on the board.
*/
typedef struct _cchess_piece_t
{
    cchess_e_piece_type_t   type;       // Type of piece
    cchess_e_piece_color_t  color;      // Color of piece
    int     row;                        // Row of piece, (0-7) this combines with col to mark a position like a4, d5, e3, etc.
    char    col;                        // Col of piece, (A-H) this combines with row to mark a position like a4, d5, e3, etc.
} cchess_piece_t;

/**
 * String representation for each piece type. We can use enum value for cchess_e_piece_type_t as index
*/
static const char* piece_type_map[] = { "Pawn", "Knight", "Bishop", "Rook", "Queen", "King", "None" };

/**
 * String representation for each piece color. We can use enum value for cchess_e_piece_color_t as index
*/
static const char* piece_color_map[] = { "White", "Black", "None" };

/**
 * Initializes a piece.
 * 
 * @param piece The piece to initialize.
 * @param type The type of the piece.
 * @param color The color of the piece.
 * 
 * @return CCHESS_RES_OK if the piece was initialized successfully, CCHESS_RES_ERR otherwise.
 */
cchess_e_result_t cchess_piece_init(cchess_piece_t* piece, cchess_e_piece_type_t type, cchess_e_piece_color_t color, const char** error);

/**
 * Moves a piece to a new position.
 * 
 * @param piece The piece to move.
 * @param col The new column of the piece.
 * @param row The new row of the piece.
 * 
 * @return CCHESS_RES_OK if the piece was moved successfully, CCHESS_RES_ERR otherwise.
*/
cchess_e_result_t cchess_piece_move(cchess_piece_t* piece, char col, int row, const char** error);

/**
 * Captures a piece by removing it from the board.
 * 
 * @param piece The piece to capture.
 * 
 * @return CCHESS_RES_OK if the piece was captured successfully, CCHESS_RES_ERR otherwise.
*/
cchess_e_result_t cchess_piece_capture(cchess_piece_t* piece, const char** error);

/**
 * Promotes a pawn to a new piece.
 * 
 * @param piece The pawn to promote.
 * @param type The type of the new piece.
 * 
 * @return CCHESS_RES_OK if the pawn was promoted successfully, CCHESS_RES_ERR otherwise.
*/
cchess_e_result_t cchess_piece_promote(cchess_piece_t* piece, cchess_e_piece_type_t type, const char** error);

/**
 * Debug print a piece.
 * 
 * @param piece The piece to print.
 * 
 * @return CCHESS_RES_OK if the piece was printed successfully, CCHESS_RES_ERR otherwise.
*/
cchess_e_result_t cchess_piece_print(cchess_piece_t* piece, const char** error);


#endif // _CCHESS_PIECE_H_