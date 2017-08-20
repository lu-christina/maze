/*
* mazestructtest.c - test for maze structure module
*
* Basic file to test the behavior of the mazestruct module, especially
* its updating and drawing methods.
*
* Emma Hobday, August 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "mazestruct.h"
#include "../amazing.h"

int main()
{
	//set up maze for simple test
	const int width = 5;
	const int height = 4;
	const int num_avatars = 2;

	printf("Creating maze...\n");

	maze_t *maze = maze_new(width, height, num_avatars);

	XYPos pos_0_0 = {0, 0};
	XYPos pos_0_1 = {0, 1};
	XYPos pos_0_2 = {0, 2};
	XYPos pos_0_3 = {0, 3};
	XYPos pos_1_0 = {1, 0};
	XYPos pos_1_2 = {1, 2};

	//test setting some south walls to 0 and 1
	printf("Set some south walls\n");
	set_south_wall(maze, &pos_0_0, 1);
	set_south_wall(maze, &pos_1_0, 0);

	//test setting some north walls to 0 and 1
	printf("Set some north walls\n");
	set_north_wall(maze, &pos_1_2, 1);
	set_north_wall(maze, &pos_0_2, 0);
	set_north_wall(maze, &pos_0_3, 1);

	//test setting some east walls to 0 and 1
	printf("Set some east walls\n");
	set_east_wall(maze, &pos_1_0, 1);
	set_east_wall(maze, &pos_0_1, 0);
	set_east_wall(maze, &pos_0_3, 1);

	//test setting some west walls to 0 and 1
	printf("Set some west walls\n");
	set_west_wall(maze, &pos_1_0, 0);
	set_west_wall(maze, &pos_1_2, 1);


	printf("Drawing maze...(and implicitly testing getters)\n");

	draw_maze(maze);

	printf("Deleting maze...\n");

	maze_delete(maze);
}





