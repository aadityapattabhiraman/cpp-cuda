#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function to initialize the ncurses library
void init_curses() {
    initscr();            // Initialize the window
    raw();                // Disable line buffering
    keypad(stdscr, TRUE); // Enable keypad input (for arrow keys)
    noecho();             // Don't show input characters
    curs_set(0);          // Hide cursor
}

// Function to get the terminal dimensions from tmux
void get_tmux_size(int *rows, int *cols) {
    // Run tmux command to get the terminal size
    FILE *fp = popen("tmux display-message -p '#{pane_height}'", "r");
    fscanf(fp, "%d", rows);
    fclose(fp);

    fp = popen("tmux display-message -p '#{pane_width}'", "r");
    fscanf(fp, "%d", cols);
    fclose(fp);
}

// Function to display a centered message
void center_message(int row, const char *message, int cols) {
    int col = (cols - strlen(message)) / 2;   // Center horizontally
    mvprintw(row, col, "%s", message);        // Print the message at the centered position
}

// Function to calculate the middle row for vertical centering
int get_middle_row(int num_lines, int rows) {
    return (rows - num_lines) / 2;  // Return the top row for vertical centering
}

// Main menu function
void main_screen(int highlight, int rows, int cols) {
    clear();

    // Get the center row for the menu
    int middle_row = get_middle_row(6, rows); // 6 lines for the main menu

    center_message(middle_row, "Welcome to the Terminal Interface", cols);
    center_message(middle_row + 2, "Use Arrow Keys to Navigate, Enter to Select", cols);

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
        center_message(middle_row + 4 + i, options[i], cols);  // Adjust row for options
        if (i == highlight) {
            attroff(A_REVERSE); // Remove the highlighting
        }
    }

    refresh();
}

// Option 1 submenu
void option1(int rows, int cols) {
    clear();
    int middle_row = get_middle_row(7, rows);  // 7 lines for this submenu
    center_message(middle_row, "Option 1 Selected", cols);
    center_message(middle_row + 2, "Sub-option 1: Hello World", cols);
    center_message(middle_row + 3, "Sub-option 2: Hello World", cols);
    center_message(middle_row + 4, "Sub-option 3: Hello World", cols);
    center_message(middle_row + 6, "Press any key to return to main menu.", cols);
    refresh();
    getch();
}

// Option 2 submenu
void option2(int rows, int cols) {
    clear();
    int middle_row = get_middle_row(7, rows);  // 7 lines for this submenu
    center_message(middle_row, "Option 2 Selected", cols);
    center_message(middle_row + 2, "Sub-option 1: Hello World", cols);
    center_message(middle_row + 3, "Sub-option 2: Hello World", cols);
    center_message(middle_row + 4, "Sub-option 3: Hello World", cols);
    center_message(middle_row + 6, "Press any key to return to main menu.", cols);
    refresh();
    getch();
}

// Option 3 submenu
void option3(int rows, int cols) {
    clear();
    int middle_row = get_middle_row(7, rows);  // 7 lines for this submenu
    center_message(middle_row, "Option 3 Selected", cols);
    center_message(middle_row + 2, "Sub-option 1: Hello World", cols);
    center_message(middle_row + 3, "Sub-option 2: Hello World", cols);
    center_message(middle_row + 4, "Sub-option 3: Hello World", cols);
    center_message(middle_row + 6, "Press any key to return to main menu.", cols);
    refresh();
    getch();
}

int main() {
    int ch;
    int highlight = 0;
    int rows, cols;

    // Initialize ncurses
    init_curses();

    // Get terminal size from tmux
    get_tmux_size(&rows, &cols);

    while (1) {
        main_screen(highlight, rows, cols);

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
                        option1(rows, cols);
                        break;
                    case 1:
                        option2(rows, cols);
                        break;
                    case 2:
                        option3(rows, cols);
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
