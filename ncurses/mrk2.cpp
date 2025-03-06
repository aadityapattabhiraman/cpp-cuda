#include <curses.h>
#include <ncurses.h>


int main()
{

    initscr();

    move(10, 20);

    printw("I am here");

    move(21, 10);

    printw("Now i am here");

    refresh();
    getch();
    endwin();

    return 0;
}
