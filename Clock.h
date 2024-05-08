#include "glut.h"
#include <ctime>
#include <cmath>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Clock {
public:
    Clock();
    void drawClock(float x, float y, float z, float size);
    void updateClock(int value);

private:
    float hour;
    float minute;
    float second;
    void drawHourHand(float x, float y, float z, float length);
    void drawMinuteHand(float x, float y, float z, float length);
    void drawSecondHand(float x, float y, float z, float length);
    void drawCircle(float radius);
};

Clock::Clock() {
    // Khởi tạo giờ, phút và giây ban đầu
    time_t now;
    struct tm currentTime;
    time(&now);
    localtime_s(&currentTime, &now);
    hour = currentTime.tm_hour % 12;
    minute = currentTime.tm_min;
    second = currentTime.tm_sec;
}

void Clock::drawClock(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y + 0.5f, z); // Điều chỉnh vị trí trên trục y để đặt đồng hồ lên cao một chút
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(size); // Vẽ mặt đồng hồ

    // Vẽ kim giờ, phút, giây với màu tương ứng
    glColor3f(0.0f, 0.0f, 0.0f); // Màu đen cho kim giờ và kim phút
    drawHourHand(x, y + 0.5f, z + 015, size / 2.2); // Điều chỉnh vị trí của kim giờ
    drawMinuteHand(x, y+0.5, z+0.3, size / 2.5); // Điều chỉnh vị trí của kim phút

    glColor3f(1.0f, 0.0f, 0.0f); // Màu đỏ cho kim giây
    drawSecondHand(x, y+0.5, z+0.3, size / 2.2); // Điều chỉnh vị trí của kim giây

    glPopMatrix();
}


void Clock::updateClock(int value) {
    // Cập nhật thời gian
    time_t now;
    struct tm currentTime;
    time(&now);
    localtime_s(&currentTime, &now);
    hour = currentTime.tm_hour % 12;
    minute = currentTime.tm_min;
    second = currentTime.tm_sec;

    glutPostRedisplay(); // Cập nhật lại cửa sổ hiển thị
}


void Clock::drawHourHand(float x, float y, float z, float length) {
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của kim giờ
    glRotatef(-30.0 * hour - (0.5 * minute), 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, length, 0.0f);
    glEnd();
    glPopMatrix();
}

void Clock::drawMinuteHand(float x, float y, float z, float length) {
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của kim phút
    glRotatef(-6.0 * minute - (0.1 * second), 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, length, 0.0f);
    glEnd();
    glPopMatrix();
}

void Clock::drawSecondHand(float x, float y, float z, float length) {
    glPushMatrix();
    glTranslatef(x, y, z); // Điều chỉnh vị trí của kim giây
    glRotatef(-6.0 * second, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, length, 0.0f);
    glEnd();
    glPopMatrix();
}

void Clock::drawCircle(float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= 360; i++) {
        float angle = 2.0f * M_PI * i / 360.0f;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

