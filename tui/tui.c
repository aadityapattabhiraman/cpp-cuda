#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize the ncurses library
void init_curses() {
    initscr();            // Initialize the window
    raw();                // Disable line buffering
    keypad(stdscr, TRUE); // Enable keypad input (for arrow keys)
    noecho();             // Don't show input characters
    curs_set(0);          // Hide cursor
}

// Function to display a centered message
void center_message(int row, const char *message) {
    int col = (COLS - strlen(message)) / 2;   // Center horizontally
    mvprintw(row, col, "%s", message);        // Print the message at the centered position
}

// Function to calculate the middle row for vertical centering
int get_middle_row(int num_lines) {
    return (LINES - num_lines) / 2;  // Return the top row for vertical centering
}

// Main menu function
void main_screen(int highlight) {
    clear();

    // Get the center row for the menu
    int middle_row = get_middle_row(6); // 6 lines for the main menu

    center_message(middle_row, "Welcome to the Terminal Interface");
    center_message(middle_row + 2, "Use Arrow Keys to Navigate, Enter to Select");

    const char *options[] = {
        "Option 1: Sub-options",
        "Option 2: Sub-options",
        "Option 3: Sub-options",
        "Exit"
    };

    // Display the menu options
    for (int i = 0; i < 4; i++) {
        if (i == highlight) {
            attron(A_REVERSE); // Highlight the selected option
        }
        center_message(middle_row + 4 + i, options[i]);  // Adjust row for options
        if (i == highlight) {
            attroff(A_REVERSE); // Remove the highlighting
        }
    }

    refresh();
}

// Option 1 submenu
void option1() {
    clear();
    int middle_row = get_middle_row(7);  // 7 lines for this submenu
    center_message(middle_row, "Option 1 Selected");
    center_message(middle_row + 2, "Sub-option 1: Hello World");
    center_message(middle_row + 3, "Sub-option 2: Hello World");
    center_message(middle_row + 4, "Sub-option 3: Hello World");
    center_message(middle_row + 6, "Press any key to return to main menu.");
    refresh();
    getch();
}

// Option 2 submenu
void option2() {
    clear();
    int middle_row = get_middle_row(7);  // 7 lines for this submenu
    center_message(middle_row, "Option 2 Selected");
    center_message(middle_row + 2, "Sub-option 1: Hello World");
    center_message(middle_row + 3, "Sub-option 2: Hello World");
    center_message(middle_row + 4, "Sub-option 3: Hello World");
    center_message(middle_row + 6, "Press any key to return to main menu.");
    refresh();
    getch();
}

// Option 3 submenu
void option3() {
    clear();
    int middle_row = get_middle_row(7);  // 7 lines for this submenu
    center_message(middle_row, "Option 3 Selected");
    center_message(middle_row + 2, "Sub-option 1: Hello World");
    center_message(middle_row + 3, "Sub-option 2: Hello World");
    center_message(middle_row + 4, "Sub-option 3: Hello World");
    center_message(middle_row + 6, "Press any key to return to main menu.");
    refresh();
    getch();
}

int main() {
    int ch;
    int highlight = 0;

    // Initialize ncurses
    init_curses();

    while (1) {
        main_screen(highlight);

        ch = getch();  // Get user input

        switch (ch) {
            case KEY_UP:
                if (highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < 3) highlight++;
                break;
            case 10: // Enter key
                switch (highlight) {
                    case 0:
                        option1();
                        break;
                    case 1:
                        option2();
                        break;
                    case 2:
                        option3();
                        break;
                    case 3:
                        endwin();  // End ncurses mode and exit
                        exit(0);
                }
                break;
        }
    }

    endwin();  // End ncurses mode
    return 0;
}
