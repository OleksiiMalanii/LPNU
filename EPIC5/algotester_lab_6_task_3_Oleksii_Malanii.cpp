#include <iostream>
#include <vector>

void paintMountain(std::vector<std::vector<int>>& map, int x, int y, int height) {
    // Встановлюємо висоту піку гори
    map[x][y] = height;

    // Визначаємо координати суміжних клітинок
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // Рекурсивно встановлюємо висоти суміжних клітинок
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Перевіряємо чи нові координати в межах карти і чи клітинка ще не розфарбована
        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] == -1) {
            paintMountain(map, nx, ny, height - 1);
        }
    }
}

int main() {
    // Зчитуємо розміри карти та координати піку гори
    int N, M, x, y;
    std::cin >> N >> M >> x >> y;

    // Ініціалізуємо карту
    std::vector<std::vector<int>> map(N, std::vector<int>(M, -1));

    // Розмальовуємо гору
    paintMountain(map, x - 1, y - 1, N * M);

    // Виводимо результат
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
