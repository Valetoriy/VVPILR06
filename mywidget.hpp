#pragma once

#include <QString>
#include <QtWidgets>
#include <memory>

class MyWidget : public QMainWindow {
    Q_OBJECT

   public:
    MyWidget();
    ~MyWidget();

   private:
    std::unique_ptr<QLineEdit> sqr_in;
    std::unique_ptr<QLineEdit> sqr_out;
    std::unique_ptr<QPushButton> b_sqr;
    std::unique_ptr<QPushButton> b_sqr_clr;
    std::unique_ptr<QLabel> lab_sqr_is;

    std::unique_ptr<QLineEdit> str_in;
    std::unique_ptr<QLineEdit> ind_in;
    std::unique_ptr<QLineEdit> str_out;
    std::unique_ptr<QPushButton> b_str;
    std::unique_ptr<QPushButton> b_str_clr;
    std::unique_ptr<QLabel> lab_str_is;

   private slots:
    void slotSqr();
    void slotSqrClr();

    void slotStr();
    void slotStrClr();
};
