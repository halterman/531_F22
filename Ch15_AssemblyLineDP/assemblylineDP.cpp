// Assembly line example from Chapter 15 (Third edition)

#include <iostream>
#include <iomanip>
#include <array>

const int NUM_STATIONS = 6;
const int NUM_LINES = 2;

using Table = std::array<std::array<int, NUM_STATIONS>, NUM_LINES>;
using Array = std::array<int, NUM_LINES>;
	
void fastest_way(Table& a, Table& t, 
                 const Array& e, const Array& x, 
                 Table& f, Table& l, 
                 int& f_star, int& l_star) {
    int n = NUM_STATIONS;
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];
	for (int j = 1; j < n; j++) {
		if (f[0][j - 1] + a[0][j] <= f[1][j - 1] + +t[1][j - 1] + a[0][j]) {
			f[0][j] = f[0][j - 1] + a[0][j];
			l[0][j] = 0;
		} else {
			f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
			l[0][j] = 1;
		}
		
		if (f[1][j - 1] + a[1][j] <= f[0][j - 1] + +t[0][j - 1] + a[1][j]) {
			f[1][j] = f[1][j - 1] + a[1][j];
			l[1][j] = 1;
		} else {
			f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
			l[1][j] = 0;
		}
	}
	if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1]) {
		f_star = f[0][n - 1] + x[0];
		l_star = 0;
	} else {
		f_star = f[1][n - 1] + x[1];
		l_star = 1;
	}
}

void printStations(int l_star, const Table& l) {
	int i = l_star;
	int n = l[0].size();
    std::cout << "line " << i << ", station " << n - 1 << '\n';
	for (int j = n - 1; j > 0; j--) {
		i = l[i][j];
        std::cout << "line " << i << ", station " << j - 1 << '\n';
	}
}

void printTables(const Table& fastest, int f_star, const Table& lines, int l_star) {
    std::cout << "===== fastest table ======\n";
    std::cout << ' ';
	for (size_t i = 0; i < fastest[0].size(); i++) {
        std::cout << std::setw(3) << i;
	}
    std::cout << '\n' << '+';
	for (size_t i = 0; i < fastest[0].size(); i++) {
        std::cout << "---";
	}
    std::cout << "-+\n";
	for (auto row : fastest) {
        std::cout << '|';
		for (size_t elem : row) {
            std::cout << std::setw(3) << elem;
		}
        std::cout << " |\n";
	}
    std::cout << '+';
	for (size_t i = 0; i < fastest[0].size(); i++) {
        std::cout << "---";
	}
    std::cout << "-+\n";
    std::cout << "f* = " << f_star << '\n';
    std::cout << '\n';
    std::cout << "===== line table ======\n";
    std::cout << ' ';
	for (size_t i = 1; i < lines[0].size(); i++) {
        std::cout << std::setw(2) << i;
	}
    std::cout << "\n+";
	for (size_t i = 1; i < lines[0].size(); i++) {
        std::cout << "--";
	}
    std::cout << "-+\n";
	for (auto row : lines) {
        std::cout << '|';
		for (size_t i = 1; i < row.size(); i++) {
            std::cout << std::setw(2) << row[i];
		}
        std::cout << " |\n";
	}
    std::cout << "+";
	for (size_t i = 1; i < lines[0].size(); i++) {
        std::cout << "--";
	}
    std::cout << "-+\n";
    std::cout << "l* = " << l_star << '\n';
}

int main() {
	Table activity{std::array<int, NUM_STATIONS>{7, 9, 3, 4, 8, 4}, 
		           std::array<int, NUM_STATIONS>{8, 5, 6, 4, 5, 7}};
	Table transfer{std::array<int, NUM_STATIONS>{2, 3, 1, 3, 4}, 
		           std::array<int, NUM_STATIONS>{2, 1, 2, 2, 1}};
	Array entry{2, 4};
	Array exit{3, 2};
	
	Table fastest{std::array<int, NUM_STATIONS>{0, 0, 0, 0, 0, 0},
	              std::array<int, NUM_STATIONS>{0, 0, 0, 0, 0, 0}};
	
	Table lines = {std::array<int, NUM_STATIONS>{0, 0, 0, 0, 0, 0},
			       std::array<int, NUM_STATIONS>{0, 0, 0, 0, 0, 0}};
	
    int f_star;
    int l_star;
	fastest_way(activity, transfer, entry, exit, fastest, lines, f_star, l_star);
	
	printTables(fastest, f_star, lines, l_star);
    std::cout << '\n';
	printStations(l_star, lines);
}
