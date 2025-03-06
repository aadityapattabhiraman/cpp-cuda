#include <curses.h>
#include <ncurses.h>


int main()
{

    initscr();

    int ch;

    while ((ch = getch()) != 'q')
    {
        attron(A_BOLD);
        printw("You pressed: %c\n", ch);
        attroff(A_BOLD);
        refresh();
    }

    endwin();

    return 0;
}
