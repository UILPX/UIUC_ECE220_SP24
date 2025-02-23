#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../game.h"


game * _make_game(int rows, int cols);
void _destroy_game(game * cur_game);

cell * _get_cell(game * cur_game, int row, int col);

int _move_w(game * cur_game);
int _move_s(game * cur_game);
int _move_a(game * cur_game);
int _move_d(game * cur_game);

int _legal_move_check(game * cur_game);
void _remake_game(game ** _cur_game,int new_rows,int new_cols);
