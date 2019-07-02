#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
: m_button("Hello World")
{
  set_border_width(10);
  add(m_button);
  m_button.show();
}
