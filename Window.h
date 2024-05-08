#include "glut.h"
#include <vector>

class Window {
public:
    void draw(float x, float y, float z, float width, float height, float thickness);
    void toggleOpenStatus(int mouseX, int mouseY, float windowX, float windowY, float windowZ, float windowWidth, float windowHeight);
};

void Window::draw(float x, float y, float z, float width, float height, float thickness) {
    // Vẽ khung cửa sổ
    glColor3f(0.3f, 0.3f, 0.3f); // Màu của khung cửa sổ
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, thickness);
    // Vẽ khung cửa sổ ở đây (ví dụ: vẽ một hộp đơn giản)
    glutSolidCube(1.0);
    glPopMatrix();

    // Vẽ phần cửa sổ
    glColor3f(0.7f, 0.9f, 1.0f); // Màu của phần cửa sổ
    glPushMatrix();
    glTranslatef(x, y, z + thickness / 2); // Đặt phần cửa sổ ở phía trước của khung
    glScalef(width * 0.9, height * 0.9, thickness); // Giảm kích thước một chút để phần cửa sổ nhỏ hơn khung
    // Vẽ phần cửa sổ ở đây (ví dụ: vẽ một hộp đơn giản)
    glutSolidCube(1.0);
    glPopMatrix();
}

void Window::toggleOpenStatus(int mouseX, int mouseY, float windowX, float windowY, float windowZ, float windowWidth, float windowHeight) {
    // Kiểm tra xem chuột có nằm trong phạm vi của cửa sổ không
    if (mouseX >= windowX && mouseX <= windowX + windowWidth &&
        mouseY >= windowY && mouseY <= windowY + windowHeight) {
        // Nếu chuột nằm trong phạm vi cửa sổ, thực hiện hành động tương ứng (ví dụ: thay đổi màu sắc)
        // Trong trường hợp này, tôi sẽ đổi màu của phần cửa sổ
        // Bạn có thể thay đổi hoặc thêm các hoạt động phù hợp với ứng dụng của bạn
        glColor3f(0.0f, 0.0f, 0.0f); // Màu đen
    }
}
