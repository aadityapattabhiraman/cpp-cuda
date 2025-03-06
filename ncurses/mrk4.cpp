#include <curses.h>
#include <ncurses.h>


int main()
{

    initscr();

    const char* choices[] = {"Monkey", "Donkey", "Stupid", "Goose"};

    int highlight = 0;
    int choice = 0;
    int c;

    while (1)
    {

        clear();

        for(int i=0; i<4; ++i)
        {

            if (i == highlight)
            {

                attron(A_BOLD);
                printw("%s\n", choices[i]);
                attroff(A_BOLD);
                printw("%s\n", choices[i]);

            }

            else
            {

                printw("%s\n", choices[i]);

            }
        }

        c = getch();

        switch(c)
        {

            case KEY_UP:
                highlight = (highlight == 0)? 3 : (highlight - 1);
                break;

            case KEY_DOWN:
                highlight = (highlight + 1) % 4;
                break;

            case 10:
                choice = highlight;
                break;

        }

        if (choice == 3) break;
    }

    endwin();

    return 0;
}
