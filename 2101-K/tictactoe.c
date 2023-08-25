#include <stdio.h>
void draw_board(int piece_mask, int player_mask);
int check_winner(int piece_mask, int player_mask);
int check_pattern_eq(int piece_mask, int player_mask, int bit_pattern);
int get_player_input();
char bit2OX(int bit);

void main()
{
    int board_piece_mask = 0, board_player_mask = 0;
    int player = 0;
    int winner = 0;
    while (!winner)
    {
        draw_board(board_piece_mask, board_player_mask);
        printf("It is %c's turn!\n", bit2OX(player));
        int input = -1;
        while (input == -1)
        {
            input = get_player_input();
            if (input != -1 && (board_piece_mask >> input) & 1)
            {
                printf("area is populated\n");
                input = -1;   
            }
        }
        board_piece_mask |= 0b1 << input;
        if (player)
            board_player_mask |= 0b1 << input;
        
        player = !player;
        winner = check_winner(board_piece_mask, board_player_mask);
        printf("\n\n");
    }
    draw_board(board_piece_mask, board_player_mask);
    printf("%c WINS!!!", bit2OX(winner >> 1));
    
}

void draw_board(int piece_mask, int player_mask)
{
    int y, x;
    printf("    a   b   c\n");
    for (y = 0; y < 7; y++)
    {
        if (y % 2 == 0)
        {
            printf("  ");
            for (x = 0; x < 13; x++)
                printf("-");
        }
        else
        {
            printf("%d ", y/2 + 1);
            for (x = 0; x < 7; x++)
            {
                if (x % 2 == 0)
                    printf("| ");
                else
                {
                    char piece = ' ';
                    int bit_offset = x / 2 + y / 2 * 3;
                    if ((piece_mask >> bit_offset) & 1)
                        piece = bit2OX((player_mask >> bit_offset) & 1);
                    printf("%c ", piece);
                }
            }
        }
        printf("\n");
    }
}

char bit2OX(int bit)
{
    return bit ? 'O' : 'X';
}

int get_player_input()
{
    char in1, in2;
    scanf(" %c%c", &in1, &in2);
    if (in1 >= 'a' && in1 <= 'c' && in2 >= '1' && in2 <= '3')
        return in1 - 'a' + (in2 - '1') * 3;
    else
        return -1;
}

int check_winner(int piece_mask, int player_mask)
{
    int i, result = 0;
    // check horizontals and verticals
    for (i = 0; i <= 6; i += 3)
    {
        result |= check_pattern_eq(piece_mask >> i, player_mask >> i, 0b111);
        result |= check_pattern_eq(piece_mask >> i, player_mask >> i, 0b1001001);   
    }
    // check diagonal 1
    result |= check_pattern_eq(piece_mask, player_mask, 0b100010001);
    // check diagonal 2
    result |= check_pattern_eq(piece_mask, player_mask, 0b001010100);
    return result;
}

int check_pattern_eq(int piece_mask, int player_mask, int bit_pattern)
{
    int player_bits = player_mask & bit_pattern;
    int mask = piece_mask & bit_pattern;
    if (mask == bit_pattern && (player_bits == 0 || player_bits == bit_pattern))
        return 1 | (player_bits != 0) << 1;
    return 0;
}