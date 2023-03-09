// xuzhu, wang
// mainwindow class that modifies the format of the windows and defines function that pass user command as parameter and display it in window form


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  // Create the button, make "this" the parent
  m_button = new QPushButton("execute", this);
  // set size and location of the button
  m_button->setGeometry(QRect(QPoint(350, 50), QSize(100, 30)));
 
  // Connect button signal to appropriate slot
  connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
  
  // Setting up the textbox for user input
  text = new QLineEdit("", this);
  text->setGeometry(QRect(QPoint(50, 50), QSize(200, 30)));
  text->setPlaceholderText("Please enter commands");
  
  // Setting up the textfield for output
  browser = new QTextBrowser(this);
  browser->setGeometry(QRect(QPoint(50, 150), QSize(300, 300)));
  
  
  // Setting up the textfield for clickable history
  listW = new QListWidget(this);
  listW->setGeometry(QRect(QPoint(400, 150), QSize(300, 300)));
  
  // Setting up the textfield for output label
  QLabel *output = new QLabel(this);
  output->setText("Output");
  output->setGeometry(QRect(QPoint(60, 120), QSize(50, 20)));
  
  // Setting up the textfield for history label
  QLabel *hist = new QLabel(this);
  hist->setText("History");
  hist->setGeometry(QRect(QPoint(400, 120), QSize(50, 20)));
  
  // Linking the function when a history is clicked
  connect(listW, &QListWidget::itemDoubleClicked, this, &MainWindow::handleListItem);
}

// destructor
MainWindow::~MainWindow(){}

// handleButton
// Perform execution for userinput when hitting execute
// passes input command to processC to process
// @param txt
// @param obj
// @param browser
// @param listW
// @param histroy
void MainWindow::handleButton()
{
	QString txt = text->text();
	processC obj(txt);
	obj.commandprocess(browser, listW, history);
}

// handleListItem
// Pull up output of a certain history
// @param index
// @param item
// @param txt
// @param browser
// @param history
void MainWindow::handleListItem(QListWidgetItem *item) {
	int index = listW->row(item);
	
	QString txt = item->text();
	if (txt.contains("0") == true)
		browser->setText(history[index]);
	
}
