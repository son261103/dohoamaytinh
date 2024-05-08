#include "glut.h"
#include <vector>

// Biến toàn cục để lưu trữ vị trí chuột
int mouseX = 0;
int mouseY = 0;

class VanityDesk {
private:
    std::vector<bool> drawerOpenStatus; // Lưu trữ trạng thái của các ngăn kéo: true nếu mở, false nếu đóng

public:
    VanityDesk() {
        // Khởi tạo trạng thái của các ngăn kéo
        drawerOpenStatus = std::vector<bool>(3, false); // Giả sử có 3 ngăn kéo và ban đầu đều đóng
    }

    // Phương thức vẽ bàn trang điểm với các ngăn kéo
    void draw(float x, float y, float z, float width, float height, float length);

    // Phương thức vẽ ngăn kéo
    void drawDrawer(float x, float y, float z, float width, float height, float length, int drawerIndex);

    // Phương thức vẽ gương trang điểm
    void drawVanityMirror(float x, float y, float z, float width, float height, float thickness);
};

void VanityDesk::draw(float x, float y, float z, float width, float height, float length) {
    // Vẽ bàn trang điểm
    glColor3f(1.0f, 1.0f, 1.0f); // Màu trắng
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, length);
    // Vẽ bàn trang điểm ở đây
    // Ví dụ: vẽ một hộp đơn giản
    glutSolidCube(1.0);
    glPopMatrix();

}
void VanityDesk::drawDrawer(float x, float y, float z, float width, float height, float length, int drawerIndex) {
    // Vẽ ngăn kéo dựa trên trạng thái của nó
    if (drawerOpenStatus[drawerIndex]) {
        // Vẽ ngăn kéo mở
        glColor3f(0.5f, 0.35f, 0.05f); // Màu của ngăn kéo mở
        glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(width, height, length);
        // Vẽ ngăn kéo mở ở đây
        // Ví dụ: vẽ một hộp đơn giản
        glutSolidCube(1.0);
        glPopMatrix();
    }
    else {
        // Vẽ ngăn kéo đóng
        glColor3f(0.3f, 0.3f, 0.3f); // Màu của ngăn kéo đóng
        glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(width, height, length);
        // Vẽ ngăn kéo đóng ở đây
        // Ví dụ: vẽ một hộp đơn giản
        glutSolidCube(1.0);
        glPopMatrix();
    }
}

void VanityDesk::drawVanityMirror(float x, float y, float z, float width, float height, float thickness) {
    // Vẽ khung gương
    glColor3f(0.8f, 0.8f, 0.8f); // Màu của khung gương
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, thickness);
    // Vẽ khung gương ở đây (ví dụ: vẽ một hộp đơn giản)
    glutSolidCube(1.0);
    glPopMatrix();

    // Vẽ phần gương
    glColor3f(0.9f, 0.9f, 0.9f); // Màu của phần gương
    glPushMatrix();
    glTranslatef(x, y, z + thickness / 2); // Đặt phần gương ở phía trước của khung
    glScalef(width * 0.9, height * 0.9, thickness); // Giảm kích thước một chút để phần gương nhỏ hơn khung
    // Vẽ phần gương ở đây (ví dụ: vẽ một hộp đơn giản)
    glutSolidCube(1.0);
    glPopMatrix();
}