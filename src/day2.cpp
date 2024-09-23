#include "../includes/day2.h"
#include "fstream"
#include <cassert>

int calculate_game_score(move m, enc_move e_m)
{
    int game_score{static_cast<int>(e_m)};

    if (static_cast<int>(m) == static_cast<int>(e_m))
        game_score += static_cast<int>(game_result_points::draw);

    else if (e_m == enc_move::Rock && m == move::Scissors ||
             e_m == enc_move::Scissors && m == move::Paper ||
             e_m == enc_move::Paper && m == move::Rock)
        game_score += static_cast<int>(game_result_points::win);

    return game_score;
}


int calculate_game_score_right(move m, enc_move e_m)
{
    int game_score{0};

    if (e_m == enc_move::Rock)
    {
        switch (m)
        {
        case move::Rock:
            game_score += static_cast<int>(enc_move::Scissors);
            break;

        case move::Paper: game_score += static_cast<int>(enc_move::Rock); break;

        case move::Scissors:
            game_score += static_cast<int>(enc_move::Paper);
            break;
        }
    }

    else if (e_m == enc_move::Paper)
    {
        game_score += static_cast<int>(game_result_points::draw);
        game_score += static_cast<int>(m);
    }

    else
    {
        game_score += static_cast<int>(game_result_points::win);

        switch (m)
        {
        case move::Rock: game_score += static_cast<int>(enc_move::Paper); break;

        case move::Paper:
            game_score += static_cast<int>(enc_move::Scissors);
            break;

        case move::Scissors:
            game_score += static_cast<int>(enc_move::Rock);
            break;
        }
    }

    return game_score;
}


move letter_to_move(char letter)
{
    switch (letter)
    {
    case 'A':
    case 'a': return move::Rock;
    case 'B':
    case 'b': return move::Paper;
    case 'C':
    case 'c': return move::Scissors;
    }
    throw std::logic_error("Unknown move from an opponent\n");
}


enc_move letter_to_enc_move(char letter)
{
    switch (letter)
    {
    case 'X':
    case 'x': return enc_move::Rock;
    case 'Y':
    case 'y': return enc_move::Paper;
    case 'Z':
    case 'z': return enc_move::Scissors;
    }
    throw std::logic_error("Unknown move from the player\n");
}


int calculate_score(const std::string& filename,
                    int (*calculation_func)(move, enc_move))
{
    int result_score{0};
    std::ifstream ist{filename};

    if (!ist)
        throw std::runtime_error("File not found\n");

    char m;
    char e_m;

    while (ist >> m >> e_m)
    {
        auto move{letter_to_move(m)};
        auto enc_move{letter_to_enc_move(e_m)};
        auto res = calculation_func(move, enc_move);
        std::cout << m << ' ' << e_m << ' ' << res << '\n';
        result_score += res;
    }

    return result_score;
}
