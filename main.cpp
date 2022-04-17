#include <QtWidgets>
#include "mywidget.hpp"

auto main(int argc, char *argv[]) -> int {
    QApplication app(argc, argv);
    MyWidget widget;

    widget.show();
    return app.exec();
}
