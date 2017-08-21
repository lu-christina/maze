/* 
 * mazepointers.c - custom module containing all pertinent info
 * for each avatar
 *
 * see mazepointers.h for more info
 *
 * Bill Tang, July 2017
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "memory.h"
#include <string.h>

typedef struct maze_data_pointer_struct {
  const char* hostname;
  const int maze_port;
  const char* filename;
  const int avatar_id;
  const maze_t* maze;
  const lastmove_t* lastmove;
  const counters_t* follow_list;
} maze_pointers_t;

/*
 * Makes deep copies of everything except maze, for obvious reasons. The free function
 * deals with everything but maze, which should be freed elsewhere.
 */
maze_pointers_t* maze_pointers_new(const char* hostname, 
                         const int maze_port,
                         const char* filename,
                         const int avatar_id,
                         const maze_t* maze,
                         const lastmove_t* lastmove,
                         const counters_t* follow_list){
  pointers_t* tmp = allocate(sizeof(pointers_t));
  tmp.hostname = strdup(hostname);
  tmp.maze_port = maze_port;
  tmp.filename = strdup(filename);
  tmp.avatar_id = avatar_id;
  tmp.maze = maze;
  tmp.lastmove = lastmove;
  tmp.follow_list = follow_list);
  return tmp;
}

/*
 * Getter Funcs
 */

const char* get_hostname(maze_pointers_t *ptr){
  return ptr.hostname;
} 

const int get_maze_port(maze_pointers_t *ptr){
  return ptr.maze_port;
}

const char* get_filename(maze_pointers_t *ptr){
  return ptr.filename;
}

const int get_avatar_id(maze_pointers_t *ptr){
  return ptr.avatar_id;
}

const maze_t* get_maze(maze_pointers_t *ptr){
  return ptr.maze;
}

const lastmove_t* get_lastmove(maze_pointers_t *ptr){
  return ptr.lastmove;
}

const counters_t* get_follow_list(maze_pointers_t *ptr){
  return ptr.follow_list;
}

/*
 * Setter Methods
 */
void set_hostname(maze_pointers_t *ptr, const char* hostname){
  ptr.hostname = strdup(hostname);
} 

void set_maze_port(maze_pointers_t *ptr, const int maze_port){
  ptr.maze_port = maze_port;
}

void set_filename(maze_pointers_t *ptr, const char* filename){
  ptr.filename = strdup(filename);
}

void set_avatar_id(maze_pointers_t *ptr, const int avatar_id){
  ptr.avatar_id = avatar_id;
}

void set_maze(maze_pointers_t *ptr, const maze_t* maze){
  ptr.maze = maze;
}

void set_lastmove(maze_pointers_t *ptr, lastmove_t* lastmove){
  ptr.lastmove = lastmove;
}

void set_follow_list(maze_pointers_t *ptr, counters_t* follow_list){
  ptr.follow_list = follow_list;
}

/*
 * Free func for pointers_t. Nota bene: this all deep copies, but not maze, which should
 * itself be freed elsewhere.
 */
void pointers_delete(maze_pointers_t *ptr){
  free(ptr.hostname);
  free(ptr.filename);
  free(ptr);
}

/*
 * Duplicates a string, returns a pointer. Useful helper func.
 */
char *strdup(const char *c){
    char *dup = malloc(strlen(c) + 1);

    if (dup != NULL)
       strcpy(dup, c);

    return dup;
}