#include <iostream>
#include <cmath>

using namespace std;

void clear_screen_and_scrollback() {
    // \033[2J - очищает видимую область экрана
    // \033[3J - очищает scrollback-буфер
    // \033[H  - перемещает курсор в верхний левый угол
    cout << "\033[2J\033[3J\033[H" << flush;
}
void set_cursor(int x, int y){
    cout << "\033[" << y << ";" << x << "H";
}


int main() {

    std::cout << "\033[?25l" << std::flush;
    std::cout.flush();        // Принудительный вывод
    int width = 147;
    int height = 38;
    float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;
    for (int t = 0; t < 10000; t++){
        for (int row_x = 1; row_x <= width; row_x++) {
            for (int row_y = 1; row_y <= height; row_y++) {
                char pixel = ' ';
                float x = (float)row_x / width * 2.0f - 1.0f;
                float y = (float)row_y / height * 2.0f - 1.0f;
                x *= aspect * pixelAspect;
                y += cos(t * 0.001);
                if (x * x + y * y < 0.5) pixel = '@'; 
                set_cursor(row_x, row_y);
                cout << pixel;
            }
        } 
    }

    // Далее, после выполнения программы, можно вызвать очистку:
    // Например, если программа ждёт ввода для завершения:
    std::cin.get();

    clear_screen_and_scrollback();
    return 0;
}

