#include <ncurses.h>
#include <iostream>
#include <string>

void init() {
	initscr();
	cbreak();
	// raw();
	noecho();
	curs_set(0);
	// if(!has_colors()) {
	// 	printw("no colors?");
	// 	getch();
	// 	exit(-1);
	// }
	// start_color();
}

int main() {
	init();
	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);

	WINDOW * menu_win = newwin(6, x_max - 12, y_max - 8, 5);
	box(menu_win, 0, 0);
	refresh();
	wrefresh(menu_win);
	keypad(menu_win, true);

	std::string variants[4] = {"option A", "option B", "put in", "option D"};
	int choise, highlith = 0;

	while(1) {
		for(int i = 0; i < 4; i++) {
			if(i == highlith) {
				wattron(menu_win, A_REVERSE);
			}
			mvwprintw(menu_win, i + 1, 1, "%s", variants[i].c_str());
			wattroff(menu_win, A_REVERSE);
		}
		choise = wgetch(menu_win);
		int delta = choise == KEY_UP ? 3 : choise == KEY_DOWN ? 1 : 0;
		highlith = (highlith + delta) % 4;
		wrefresh(menu_win);
		if(choise == 10) break;
	}
	mvprintw(1, 1, "your choise was: %s", variants[highlith].c_str());
	refresh();
	wgetch(menu_win);

	// WINDOW * input_win = newwin(3, x_max-12, y_max-5, 5);
	// box(input_win, 0, 0);
	// refresh();
	// wrefresh(input_win);

	// keypad(input_win, true);

	// int c = wgetch(input_win);
	// if(c == KEY_F | KEY_SLEFT) {
	// 	mvwprintw(input_win, 1, 1, "it was shift+f, i guess?");
	// 	wrefresh(input_win);
	// }

	// int x, y, y_beg, x_beg, y_max, x_max;

	// getyx(stdscr, y, x);
	// getbegyx(stdscr, y_beg, x_beg);
	// getmaxyx(stdscr, y_max, x_max);

	// printw("%d %d %d %d %d %d", y, x, y_beg, x_beg, y_max, x_max);
	// mvprintw(y_max / 2, x_max / 2 - 7, "centered text!");


	// attron(A_REVERSE);
	// mvprintw(0, 0, "This is some text");
	// getch();
	// attroff(A_REVERSE);
	// mvprintw(0, 0, "This is some text");

	// int height = 15, width = 30, start_y = 5, start_x = 5;
	// WINDOW * win = newwin(height, width, start_y, start_x);
	// refresh();

	// box(win, '|', '|', '-', '-', '+', '+', '+', '+');
	// mvwprintw(win, 7, 6, "hello from ncurses!");
	// wrefresh(win);

	// refresh();

	// getch();

	endwin();
	return 0;
}