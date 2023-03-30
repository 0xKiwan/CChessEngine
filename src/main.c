#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/piece.h"
#include "../inc/board.h"

int main(int argc, char* argv[])
{
    // Will store errors from function calls
    const char* error = NULL;

    // Create a board
    cchess_board_t board;

    // Initialize the board
    cchess_e_result_t res = cchess_board_init(&board, &error);

    // Check for an error
    if (res != CCHESS_RES_OK)
    {
        // Print the error
        printf("Board init error: %s\n", error);

        // Exit with error code.
        return 1;
    }

    // Print the board
    cchess_board_print(&board, &error);

    // Return OK
    return 0;
}