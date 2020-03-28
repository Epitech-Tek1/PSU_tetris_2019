/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** display_tetriminos
*/

#include <ncurses.h>
#include "../../include/define.h"
#include "../../include/minos.h"
#include "../../include/library/_string/include/string.h"
#include "../../include/my.h"

void
print_game_elements(char *filepath, vector2_t position)
{
    char *lineptr = NULL;
    size_t nread = 500;
    FILE *stream = fopen(filepath, "r");
    char *posx = NULL;
    char *posy = NULL;

    getline(&posy, &nread, stream);
    getline(&posx, &nread, stream);
    for (int i = 0; -1 != getline(&lineptr, &nread, stream); i++)
        for (int n = 0; lineptr[n]; n++)
            mvaddch(i + _atoi(posy), n + _atoi(posx), lineptr[n]);
}

void
print_next(char **next, int map_width)
{
    for (int i = 0; next[i]; ++i)
        for (int j = 0; next[i][j]; ++j)
            mvaddch(i, MAP_WIDTH, next[i][j]);
}

static void
print_char(minos_t *minos, int i, int n)
{
    if (minos->minos[i][n] != ' ');
        mvaddch(minos->pos.y + i + 1, minos->pos.x + 37 + n, minos->minos[i][n]);
}

void
display_tetriminos(game_t *game, options_t *option, minos_t *minos)
{
    for (int i = 0; minos->minos[i]; i++)
        for (int n = 0; minos->minos[i][n]; n++)
            print_char(minos, i, n);
}

void
display_map(game_t *game, options_t *option)
{
    for (int i = 0; MAP[i]; i++)
        for (int n = 0; MAP[i][n]; n++)
            mvaddch(i, n + 36, MAP[i][n]);
}