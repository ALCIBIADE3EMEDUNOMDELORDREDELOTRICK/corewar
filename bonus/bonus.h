/*
** EPITECH PROJECT, 2026
** robot_factory
** File description:
** header
*/


#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef BONUS_H
    #define BONUS_H
sfText *create_text(sfFont *font, sfColor *color);
void draw_cycle(sfRenderWindow *win, sfFont *font, corewar_t *war);
void draw_line(sfRenderWindow *win, float y);
void draw_text(sfRenderWindow *win, sfText *t, char *str, float y);
#endif
