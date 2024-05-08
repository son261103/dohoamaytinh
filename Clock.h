
#include "glut.h"
#include <ctime>
#include <cmath>
#include <iostream>

class Clock {
public:
    void drawClock();
    void display();
    static void update(int value); // Sử dụng static để phù hợp với cú pháp của glutTimerFunc
    void init();
};

void Clock::drawClock() {
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    float seconds = timeinfo.tm_sec;
    float minutes = timeinfo.tm_min;
    float hours = timeinfo.tm_hour;

    // Chuyển đổi giờ về định dạng 12 giờ
    hours = hours > 12 ? hours - 12 : hours;

    // Clear screen và matrix
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Vẽ hình tròn đại diện cho mặt trước của đồng hồ
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0); // Tâm của đồng hồ
    for (int i = 0; i <= 360; i++) {
        float angle = i * (3.14159265358979323846 / 180.0);
        float x = 0.9 * cos(angle);
        float y = 0.9 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Vẽ kim giây
    glColor3f(1.0, 0.0, 0.0); // Màu đỏ
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.7);
    glEnd();

    // Vẽ kim phút
    glColor3f(0.0, 1.0, 0.0); // Màu xanh lá cây
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5 * sin(minutes * 6 * 3.14159 / 180), 0.5 * cos(minutes * 6 * 3.14159 / 180));
    glEnd();

    // Vẽ kim giờ
    glColor3f(0.0, 0.0, 1.0); // Màu xanh dương
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.4 * sin((hours * 30 + minutes / 2) * 3.14159 / 180), 0.4 * cos((hours * 30 + minutes / 2) * 3.14159 / 180));
    glEnd();

    glutSwapBuffers();
}

void Clock::display() {
    drawClock();
}

void Clock::update(int value) {
    glutPostRedisplay(); // Yêu cầu vẽ lại
    glutTimerFunc(1000, Clock::update, 0); // Sử dụng Clock::update thay vì update
}

void Clock::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Màu nền đen
}
