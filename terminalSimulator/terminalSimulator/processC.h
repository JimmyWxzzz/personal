// xuzhu, wang
// processC class that receive user input command and run it on system, store output value if the input command is appropriate 
// or catch the exception when the wrong command line is provided

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <QString>
#include <QTextStream>
#include <QTextBrowser>
#include <vector>
#include <QListWidget>
#include <boost/process.hpp>
#include <boost/process/child.hpp>
#include <boost/process/io.hpp>

class processC {


// commandprocess that takes in the user input as command and check if the current command is
// viable in terminal and store the correct output to the history vector
public:
 explicit processC (const QString& s);
 ~processC();
 int commandprocess(QTextBrowser *browser, QListWidget *list,
 		     std::vector<QString>& history);

private:
 QString s;
 
};

#endif
