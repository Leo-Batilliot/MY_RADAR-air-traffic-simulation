/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myradar-leo.batilliot
** File description:
** main2
*/
#include "my.h"

void print_help(void)
{
    write(1, "-------------AIR TRAFFIC SIMULATION PROGRAM-------------\n", 57);
    write(1, "To start the simulation, you need to provide a file ", 52);
    write(1, "containing the required data as a command-line argument.\n", 57);
    write(1, "Below is a list of useful keys ", 31);
    write(1, "you can press during the simulation:\n", 37);
    write(1, "ESC:\tStop the simulation\n", 25);
    write(1, "S:\tShow/hide the sprites (towers and planes)\n", 45);
    write(1, "L:\tShow/hide the planes' hitboxes and towers' radius\n", 53);
    write(1, "SPACE:\tPause/Resume the simulation\n", 35);
}

void create_node_from_line(char *line, sim_t *sim)
{
    char **array = my_str_to_word_array(line);

    if (array[0][0] == 'A')
        init_plane(array, sim);
    if (array[0][0] == 'T')
        init_tower(array, sim);
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int read_file(const char *filename, sim_t *sim)
{
    char *line = NULL;
    size_t len = 0;
    FILE *fd = fopen(filename, "r");

    if (!fd) {
        write(2, "incorrect filepath to your script\n", 34);
        return 84;
    }
    while (getline(&line, &len, fd) != -1)
        create_node_from_line(line, sim);
    free(line);
    fclose(fd);
    return 0;
}

static int tty(char **en)
{
    for (int i = 0; en[i] != NULL; i++)
        if (cmp(en[i], "TERM=linux") == 0)
            return 84;
    return 0;
}

int error_handling(sim_t *sim, int ac, char **av)
{
    if (ac != 2) {
        write(2, "Incorrect arguments, use -h for help\n", 37);
        return 84;
    }
    if (cmp(av[1], "-h") == 0) {
        print_help();
        return 0;
    }
    if (!sim || sim == NULL) {
        write(2, "malloc failed or missing asset\n", 31);
        return 84;
    }
    if (read_file(av[1], sim) == 84) {
        free_sim(sim);
        return 84;
    }
    return 1;
}

int main(int ac, char **av, char **en)
{
    sfRenderWindow *window;
    sim_t *sim;
    int error = 1;

    if (tty(en) == 84)
        return 84;
    sim = init_sim();
    error = error_handling(sim, ac, av);
    if (error != 1)
        return error;
    window = sfRenderWindow_create((sfVideoMode)
        {1920, 1080, 32}, "MY RADAR", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sim->p_head = reverse_sim(sim->p_head);
    main_loop(window, sim);
    return 0;
}
