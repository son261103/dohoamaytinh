#ifndef BED_H
#define BED_H

#include <string>
#include "glut.h"

class BED {
public:
    // Phương thức vẽ giường
    void drawBed(float x, float y, float z, float width, float height, float depth);

    // Phương thức vẽ gối
    void drawPillow(float x, float y, float z, float size);

    // Phương thức vẽ chăn
    void drawBlanket(float x, float y, float z, float width, float height, float depth);
};

// Triển khai các phương thức trong cùng một file .h
void BED::drawBed(float x, float y, float z, float width, float height, float depth) {
    // Vẽ mặt trên giường
    glColor3f(0.5, 0.35, 0.05); // Màu nâu cho giường
    glBegin(GL_QUADS);
    glVertex3f(x, y + height, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x, y + height, z + depth);
    glEnd();

    // Vẽ các mặt của giường
    glColor3f(0.5, 0.35, 0.05); // Màu nâu cho giường
    glBegin(GL_QUADS);
    // Mặt dưới giường
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y, z + depth);
    glVertex3f(x, y, z + depth);
    // Mặt bên giường
    glVertex3f(x, y, z);
    glVertex3f(x, y + height, z);
    glVertex3f(x, y + height, z + depth);
    glVertex3f(x, y, z + depth);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x + width, y, z + depth);
    // Mặt sau giường
    glVertex3f(x, y, z);
    glVertex3f(x, y + height, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y, z);
    // Mặt trước giường
    glVertex3f(x, y, z + depth);
    glVertex3f(x, y + height, z + depth);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x + width, y, z + depth);
    glEnd();
}

void BED::drawPillow(float x, float y, float z, float size) {
    glColor3f(1.0, 1.0, 1.0); // Màu trắng

    // Vẽ mặt trên của gối
    glBegin(GL_QUADS);
    glVertex3f(x - size / 2, y + size / 2, z + size / 2);
    glVertex3f(x + size / 2, y + size / 2, z + size / 2);
    glVertex3f(x + size / 2, y + size / 2, z - size / 2);
    glVertex3f(x - size / 2, y + size / 2, z - size / 2);
    glEnd();

    // Vẽ mặt dưới của gối
    glBegin(GL_QUADS);
    glVertex3f(x - size / 2, y - size / 2, z - size / 2);
    glVertex3f(x + size / 2, y - size / 2, z - size / 2);
    glVertex3f(x + size / 2, y - size / 2, z + size / 2);
    glVertex3f(x - size / 2, y - size / 2, z + size / 2);
    glEnd();

    // Vẽ mặt trước của gối
    glBegin(GL_QUADS);
    glVertex3f(x - size / 2, y + size / 2, z + size / 2);
    glVertex3f(x + size / 2, y + size / 2, z + size / 2);
    glVertex3f(x + size / 2, y - size / 2, z + size / 2);
    glVertex3f(x - size / 2, y - size / 2, z + size / 2);
    glEnd();

    // Vẽ mặt sau của gối
    glBegin(GL_QUADS);
    glVertex3f(x - size / 2, y - size / 2, z - size / 2);
    glVertex3f(x + size / 2, y - size / 2, z - size / 2);
    glVertex3f(x + size / 2, y + size / 2, z - size / 2);
    glVertex3f(x - size / 2, y + size / 2, z - size / 2);
    glEnd();

    // Vẽ mặt bên trái của gối
    glBegin(GL_QUADS);
    glVertex3f(x - size / 2, y + size / 2, z - size / 2);
    glVertex3f(x - size / 2, y + size / 2, z + size / 2);
    glVertex3f(x - size / 2, y - size / 2, z + size / 2);
    glVertex3f(x - size / 2, y - size / 2, z - size / 2);
    glEnd();

    // Vẽ mặt bên phải của gối
    glBegin(GL_QUADS);
    glVertex3f(x + size / 2, y + size / 2, z + size / 2);
    glVertex3f(x + size / 2, y + size / 2, z - size / 2);
    glVertex3f(x + size / 2, y - size / 2, z - size / 2);
    glVertex3f(x + size / 2, y - size / 2, z + size / 2);
    glEnd();
}

void BED::drawBlanket(float x, float y, float z, float width, float height, float depth) {
    // Vẽ mặt trên chăn
    glColor3f(0.9, 0.9, 0.9); // Màu trắng cho chăn
    glBegin(GL_QUADS);
    glVertex3f(x, y + height, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x, y + height, z + depth);
    glEnd();

    // Vẽ các mặt của chăn
    glColor3f(0.9, 0.9, 0.9); // Màu trắng cho chăn
    glBegin(GL_QUADS);
    // Mặt dưới chăn
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y, z + depth);
    glVertex3f(x, y, z + depth);
    // Mặt bên chăn
    glVertex3f(x, y, z);
    glVertex3f(x, y + height, z);
    glVertex3f(x, y + height, z + depth);
    glVertex3f(x, y, z + depth);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x + width, y, z + depth);
    // Mặt sau chăn
    glVertex3f(x, y, z);
    glVertex3f(x, y + height, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x + width, y, z);
    // Mặt trước chăn
    glVertex3f(x, y, z + depth);
    glVertex3f(x, y + height, z + depth);
    glVertex3f(x + width, y + height, z + depth);
    glVertex3f(x + width, y, z + depth);
    glEnd();
}

#endif // BED_H
