// xuzhu, wang
// mainwindow class that modifies the format of the windows and defines function that pass user command as parameter and display it in window form

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QtGui>
#include <QLineEdit>
#include <QString>
#include <QComboBox>
#include <QTextBrowser>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QApplication>
#include <boost/process.hpp>
#include <vector>
#include "processC.h"

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
  
// This is the main window
public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

//Private functions for the button and history
  private slots:
  void handleButton();
  void handleListItem(QListWidgetItem *item);

private:
  QPushButton *m_button;
  QLineEdit *text;
  QTextBrowser *browser;
  QListWidget *listW;
  
  std::vector<QString> history;
  
};
#endif // MAINWINDOW_H
