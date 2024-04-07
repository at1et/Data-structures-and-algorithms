#include <iostream>
#include <vector>

using namespace std;


// Функция для поиска выигрышных ходов
vector<pair<int, int>> find_winning_moves(int M, int N, vector<vector<int>>& rows) {
    vector<pair<int, int>> winning_moves;

    // Проверяем, если оставшаяся часть пирога состоит только из отравленных клеток
    bool all_cells_eaten = true;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rows[i][j] != 0) {
                all_cells_eaten = false;
                break;
            }
        }
        if (!all_cells_eaten)
            break;
    }
    if (all_cells_eaten)
        return winning_moves;

    // Проходим по всем возможным клеткам
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rows[i][j] != 0) { // Проверяем, что клетка не съедена
                // Проверяем, можно ли сделать ход без проигрыша
                bool is_winning_move = true;
                for (int x = i; x < M; ++x) {
                    for (int y = j; y < N; ++y) {
                        if (rows[x][y] < i - x + 1) {
                            is_winning_move = false;
                            break;
                        }
                    }
                    if (!is_winning_move)
                        break;
                }
                if (is_winning_move)
                    winning_moves.push_back(make_pair(i + 1, j + 1)); // Добавляем координаты выигрышного хода
            }
        }
    }

    return winning_moves;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int M, N;

    // Вводим размеры пирога
    cout << "Введите количество строк M и столбцов N: ";
    cin >> M >> N;

    // Вводим количество оставшихся клеток в каждом ряду пирога
    cout << "Введите количество оставшихся клеток в каждом ряду пирога:" << endl;
    vector<vector<int>> rows(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Ряд " << i + 1 << ", клетка " << j + 1 << ": ";
            cin >> rows[i][j];
        }
    }

    // Поиск выигрышных ходов
    vector<pair<int, int>> winning_moves = find_winning_moves(M, N, rows);

    // Вывод результатов
    cout << "Количество выигрышных ходов: " << winning_moves.size() << endl;
    cout << "Выигрышные ходы (координаты клеток):" << endl;
    for (auto move : winning_moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
