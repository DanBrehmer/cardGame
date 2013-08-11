#include <ncurses.h>
#include<string.h>
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
int main(int argc, char *argv[])
{
  int height = 10;
  int width = 80;

    WINDOW* win1 = newwin(height, width, (LINES - height) / 2 - 20,
                            (COLS - width) / 2);
    WINDOW* win2 = newwin(height, width, (LINES - height) / 2 + 20,
                            (COLS - width) / 2);
  
  initscr();			/* Start curses mode 		*/
  if(has_colors() == FALSE)
  {	endwin();
    printf("Your terminal does not support color\n");
    return 1;
  }
  start_color();			/* Start color 			*/
  init_pair(1, COLOR_RED, COLOR_BLACK);

  attron(COLOR_PAIR(1));
  print_in_middle(win1, LINES / 2, 0, 0, "Viola !!! In color ...");
  print_in_middle(win2, LINES / 2, 0, 0, "Viola !!! In color ...");
  attroff(COLOR_PAIR(1));
  getch();
  endwin();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
  float temp;

  // if(win == NULL)
  //   win = stdscr;
  // getyx(win, y, x);
  // if(startx != 0)
  //   x = startx;
  // if(starty != 0)
  //   y = starty;
  getyx(win, y, x);
  if(width == 0)
    width = 80;

  length = strlen(string);
  temp = (width - length)/ 2;
  x = startx + (int)temp;
  mvwprintw(win, y, x, "%s", string);
  wrefresh(win);
//  refresh();
}