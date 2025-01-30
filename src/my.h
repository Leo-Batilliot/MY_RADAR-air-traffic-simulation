/*
** EPITECH PROJECT, 2024
** myh
** File description:
** task 02
*/
#ifndef TEST_H
    #define TEST_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include <math.h>
    #include <fcntl.h>

typedef struct Tower {
    sfSprite *sprite;
    sfVector2f position;
    sfCircleShape *hitbox;
    float radius;
    struct Tower *next;
} tower_t;

typedef struct plane {
    sfSprite *sprite;
    sfVector2f s_pos;
    sfVector2f c_pos;
    sfVector2f e_pos;
    sfVector2f vector;
    sfRectangleShape *hitbox;
    float speed;
    float time;
    int safe;
    int dead;
    struct plane *next;
    struct plane *next_collide;
} plane_t;

typedef struct sim {
    int sprite_enabled;
    int hitbox_enabled;
    int fps;
    sfFont *font;
    sfText *fps_text;
    sfText *time_string;
    sfText *sprite_text;
    sfText *hitbox_text;
    sfSprite *map_sprite;
    sfTexture *map_texture;
    sfTexture *p_texture;
    sfTexture *t_texture;
    plane_t *p_head;
    tower_t *t_head;
    sfClock *clock;
    sfClock *paused_clock;
    double time;
    double paused_time;
    int paused;
    int dead;
} sim_t;

char *float_to_text(float nb);
void fps_count(sim_t *sim);
char *concat(char *str1, char *str2);
char **my_str_to_word_array(char *str);
int collide_main(sim_t *sim);
void free_sim(sim_t *sim);
sim_t *init_sim(void);
plane_t *reverse_sim(plane_t *);
void free_plane(plane_t *);
int read_file(const char *filename, sim_t *sim);
float my_atof(const char *str);
void move_planes(sim_t *sim);
void dead_planes(sim_t *sim);
void init_plane(char **array, sim_t *sim);
int plane_error(char **array);
void init_tower(char **array, sim_t *sim);
int tower_error(char **array);
int cmp(char *str1, char *str2);
void main_loop(sfRenderWindow *window, sim_t *sim);
int is_cell_empty(plane_t *[1080 / 40][1920 / 40], int, int, sim_t *);
void print_window(sfRenderWindow *window, sim_t *sim);
void in_tower_range(sim_t *sim);

#endif /* TEST_H */
