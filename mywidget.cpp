#include "mywidget.hpp"

MyWidget::~MyWidget() {}

auto MyWidget::slotSqr() -> void {
    double d;
    QString tmp;

    d = sqr_in->text().toDouble();
    d = d * d;
    sqr_out->setText(tmp.setNum(d));
}

auto MyWidget::slotSqrClr() -> void {
    sqr_in->setText("");
    sqr_out->setText("");
}

auto MyWidget::slotStr() -> void {
    QString tmp = str_in->text();
    int ind = ind_in->text().toInt();
    tmp[ind - 1] = tmp[0];

    str_out->setText(tmp);
}

auto MyWidget::slotStrClr() -> void {
    str_in->setText("");
    ind_in->setText("");
    str_out->setText("");
}

MyWidget::MyWidget()
    : sqr_in{std::make_unique<QLineEdit>(this)},
      sqr_out{std::make_unique<QLineEdit>(this)},
      b_sqr{std::make_unique<QPushButton>("*", this)},
      b_sqr_clr{std::make_unique<QPushButton>("C", this)},
      lab_sqr_is{std::make_unique<QLabel>("^2=", this)},

      str_in{std::make_unique<QLineEdit>(this)},
      ind_in{std::make_unique<QLineEdit>(this)},
      str_out{std::make_unique<QLineEdit>(this)},
      b_str{std::make_unique<QPushButton>("Apply", this)},
      b_str_clr{std::make_unique<QPushButton>("C", this)},
      lab_str_is{std::make_unique<QLabel>("=>", this)} {
    this->resize(375, 300);

    sqr_in->move(60, 30);
    sqr_in->resize(70, 20);
    lab_sqr_is->move(140, 30);
    lab_sqr_is->resize(30, 20);
    sqr_out->move(180, 30);
    sqr_out->resize(70, 20);
    sqr_out->setReadOnly(true);
    b_sqr->move(70, 80);
    b_sqr->resize(50, 50);
    b_sqr_clr->move(190, 80);
    b_sqr_clr->resize(50, 50);

    str_in->move(60, 160);
    str_in->resize(100, 20);
    ind_in->move(170, 160);
    ind_in->resize(20, 20);
    lab_str_is->move(200, 160);
    lab_str_is->resize(20, 20);
    str_out->move(230, 160);
    str_out->resize(100, 20);
    str_out->setReadOnly(true);
    b_str->move(87, 210);
    b_str->resize(50, 50);
    b_str_clr->move(255, 210);
    b_str_clr->resize(50, 50);

    connect(b_sqr.get(), SIGNAL(clicked()), this, SLOT(slotSqr()));
    connect(b_sqr_clr.get(), SIGNAL(clicked()), this, SLOT(slotSqrClr()));

    connect(b_str.get(), SIGNAL(clicked()), this, SLOT(slotStr()));
    connect(b_str_clr.get(), SIGNAL(clicked()), this, SLOT(slotStrClr()));
}
