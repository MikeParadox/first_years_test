#ifndef DAY2_H
#define DAY2_H

#include <iostream>
#include <string>
#include <utility>

enum class move
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum class enc_move
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum class game_result_points
{
    lose = 0,
    draw = 3,
    win = 6
};


// calculates and return game score
int calculate_game_score(move m, enc_move e_m);

int calculate_game_score_right(move m, enc_move e_m);

// converts a char to a move
move letter_to_move(char letter);

// converts a char to a encrypted move
enc_move letter_to_enc_move(char letter);

// processes given .txt file line by line (game by game) and accumulate
//   the result
int calculate_score(const std::string& filename,
                    int (*calculation_func)(move, enc_move));

#endif // DAY2_H
