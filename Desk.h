#ifndef DESK_H
#define DESK_H

#include "glut.h"

class DESK {
public:
    // Phương thức vẽ bàn học
    void drawDesk(float x, float y, float z, float width, float height, float length);
    void drawLeg(float x, float y, float z, float width, float height, float length);
    // Phương thức vẽ ghế gaming có tựa lưng
    void drawGamingChair(float x, float y, float z, float width, float height, float length, float rotationAngle);
    // Phương thức vẽ desktop
    void drawDesktop(float x, float y, float z, float width, float height, float length);


    void drawComputerCase(float x, float y, float z, float width, float height, float length);
};

void DESK::drawDesk(float x, float y, float z, float width, float height, float length) {
    // Đặt màu cho bàn
    glColor3f(0.5f, 0.35f, 0.05f);

    // Vẽ mặt bàn
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, length);
    glBegin(GL_QUADS);
    // Mặt trên
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    // Mặt dưới
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Mặt trước
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Mặt sau
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    // Mặt trái
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Mặt phải
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}

void DESK::drawLeg(float x, float y, float z, float width, float height, float length) {
    // Đặt màu cho chân bàn
    glColor3f(0.5f, 0.35f, 0.05f);

    // Vẽ chân bàn
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, length);
    glBegin(GL_QUADS);
    // Mặt trên
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    // Mặt dưới
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Mặt trước
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Mặt sau
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    // Mặt trái
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Mặt phải
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}


void DESK::drawGamingChair(float x, float y, float z, float width, float height, float length, float rotationAngle) {
    // Đặt màu cho ghế
    glColor3f(0.7f, 0.7f, 0.7f); // Màu xám cho ghế

    // Vẽ phần chân ghế
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của ghế
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Xoay ghế theo chiều ngang
    glBegin(GL_QUADS);
    // Mặt sau của chân ghế
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 1.7f, 0.0f);
    glVertex3f(0.0f, 1.7f, 0.0f);

    // Mặt trước của chân ghế
    glVertex3f(0.0f, 0.0f, 0.8f);
    glVertex3f(0.1f, 0.0f, 0.8f);
    glVertex3f(0.1f, 1.7f, 0.8f);
    glVertex3f(0.0f, 1.7f, 0.8f);

    // Các cạnh của chân ghế
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.8f);
    glVertex3f(0.0f, 1.7f, 0.8f);
    glVertex3f(0.0f, 1.7f, 0.0f);

    glVertex3f(0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.0f, 0.8f);
    glVertex3f(0.1f, 1.7f, 0.8f);
    glVertex3f(0.1f, 1.7f, 0.0f);
    glEnd();
    glPopMatrix();

    // Vẽ phần tựa lưng của ghế
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của ghế
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Xoay ghế theo chiều ngang
    glBegin(GL_QUADS);
    // Mặt trên của tựa lưng
    glVertex3f(0.0f, 1.7f, 0.0f);
    glVertex3f(0.1f, 1.7f, 0.0f);
    glVertex3f(0.1f, 1.7f, 0.8f);
    glVertex3f(0.0f, 1.7f, 0.8f);

    // Các cạnh của tựa lưng
    glVertex3f(0.0f, 1.7f, 0.0f);
    glVertex3f(0.0f, 1.2f, 0.0f);
    glVertex3f(0.0f, 1.2f, 0.8f);
    glVertex3f(0.0f, 1.7f, 0.8f);

    glVertex3f(0.1f, 1.7f, 0.0f);
    glVertex3f(0.1f, 1.2f, 0.0f);
    glVertex3f(0.1f, 1.2f, 0.8f);
    glVertex3f(0.1f, 1.7f, 0.8f);

    glVertex3f(0.0f, 1.7f, 0.8f);
    glVertex3f(0.0f, 1.2f, 0.8f);
    glVertex3f(0.1f, 1.2f, 0.8f);
    glVertex3f(0.1f, 1.7f, 0.8f);
    glEnd();
    glPopMatrix();

    // Vẽ phần đệm của ghế
    glColor3f(0.5f, 0.5f, 0.5f); // Màu xám nhạt cho đệm
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của ghế
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Xoay ghế theo chiều ngang
    glBegin(GL_QUADS);
    // Mặt trên của đệm
    glVertex3f(0.0f, 0.7f, 0.0f);
    glVertex3f(0.8f, 0.7f, 0.0f);
    glVertex3f(0.8f, 0.7f, 0.8f);
    glVertex3f(0.0f, 0.7f, 0.8f);

    // Các cạnh của đệm
    glVertex3f(0.0f, 0.7f, 0.0f);
    glVertex3f(0.0f, 0.6f, 0.0f);
    glVertex3f(0.8f, 0.6f, 0.0f);
    glVertex3f(0.8f, 0.7f, 0.0f);

    glVertex3f(0.0f, 0.7f, 0.8f);
    glVertex3f(0.0f, 0.6f, 0.8f);
    glVertex3f(0.8f, 0.6f, 0.8f);
    glVertex3f(0.8f, 0.7f, 0.8f);
    glEnd();
    glPopMatrix();
}



void DESK::drawDesktop(float x, float y, float z, float width, float height, float length) {
    // Đặt màu cho bộ desktop
    glColor3f(0.0f, 0.0f, 0.0f); // Màu đen

    // Vẽ mặt trên của bộ desktop
    glPushMatrix();
    glTranslatef(x, y + height, z);
    glScalef(width, height / 10, length);
    glBegin(GL_QUADS);
    // Mặt trên
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
    glPopMatrix();

    // Vẽ mặt dưới của bộ desktop
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height / 10, length);
    glBegin(GL_QUADS);
    // Mặt dưới
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();
    glPopMatrix();

    // Vẽ các mặt bên của bộ desktop
    glPushMatrix();
    glTranslatef(x, y + height / 2, z);
    glScalef(width, height / 2, length / 10);
    glBegin(GL_QUADS);
    // Mặt trước
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Mặt sau
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    // Mặt trái
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Mặt phải
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}

void DESK::drawComputerCase(float x, float y, float z, float width, float height, float length) {
    // Set color for the computer case
    glColor3f(0.5f, 0.5f, 0.5f); // Gray color for the case

    // Draw the computer case
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, length);
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Back face
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Top face
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    // Bottom face
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // Right face
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    // Left face
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}

#endif // DESK_H
