#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

void draw_borders(WINDOW *screen)
{
    int x;
    int y;
    int i;

    getmaxyx(screen, y, x);

    // les 4 coins
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, y - 1, 0, "+");
    mvwprintw(screen, 0, x - 1, "+");
    mvwprintw(screen, y - 1, x - 1, "+");

    // les cotes
    i = 1;
    while (i < (y - 1))
    {
      mvwprintw(screen, i, 0, "|");
      mvwprintw(screen, i, x - 1, "|");
      mvwprintw(screen, i, x/4, "|");
      mvwprintw(screen, i, (x/4)*2, "|");
      mvwprintw(screen, i, (x/4)*3, "|");
      i++;
    }

    // top && bot
    i = 1;
    while (i < (x - 1))
    {
      mvwprintw(screen, 0, i, "-");
      mvwprintw(screen, y - 1, i, "-");
      mvwprintw(screen, y/4, i, "-");
      mvwprintw(screen, (y/4)*2, i, "-");
      mvwprintw(screen, (y/4)*3, i, "-");
      i++;
    }
}

int main(int argc, char *argv[])
{
  int parent_x;
  int parent_y;
  int new_x;
  int new_y;

  initscr();

  // recup donnee max de la fenetre
  getmaxyx(stdscr, parent_y, parent_x);

  // fenetre initiale
  WINDOW *field = newwin(parent_y, parent_x, 0, 0);

  // draw our borders
  draw_borders(field);

   while(1)
   {
    getmaxyx(stdscr, new_y, new_x);

    if (new_y != parent_y || new_x != parent_x)
    {
      parent_x = new_x;
      parent_y = new_y;
      wresize(field, new_y, new_x);

      wclear(stdscr);
      wclear(field);

      draw_borders(field);
    }
    // refresh each window
    wrefresh(field);
  }

  // clean up
  delwin(field);

  endwin();
  return (0);
}
