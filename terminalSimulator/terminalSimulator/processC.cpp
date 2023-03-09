// xuzhu, wang
// processC class that receive user input command and run it on system, store output value if the input command is appropriate 
// or catch the exception when the wrong command line is provided

#include "processC.h"

namespace bp = boost::process;

processC::processC(const QString& string) {
	this->s = string;
}

processC::~processC() {
}


// commandprocess
// commandprocess that takes in the user input as command and check if the current command is
// viable in terminal and store the correct output to the history vector
// @param pout
// @param pin
// @param cmd
// @param browser
// @param histroy
// @param list
// @param data
// @param line
// @param tmp
int processC::commandprocess(QTextBrowser *browser, QListWidget *list,
 		    	       std::vector<QString>& history) {
	
	bp::ipstream pout;
	bp::opstream pin;
	
	
	std::string cmd = s.toStdString();
	
	
	// check if the current command is viable or catch the error
	try
	{	
		
	bp::child c(cmd, (bp::std_out & bp::std_err) > pout,bp::std_in < pin);
	
	std::vector<std::string> data;
    	std::string line;
    	
    	// Running the command line on a child process and record the corresponding output
    	// pipe_stream
	while (c.running() && std::getline(pout, line) && !line.empty())
        	data.push_back(line);
        
      		c.wait();
        
      	 	QString temp;
      	 	
      	 	//Storing the output from pipe_Stream to vector
     		for (size_t i = 0; i < data.size(); i++) {
        		//std::cout << data[i] << std::endl;
        	
        		temp += data[i].c_str();
        		temp +="\n"	;
        	
        	
		}
		
		// Pushing the correct history and output to the windows
		browser->setText(temp);
		history.push_back(temp);
		s += "(0)";
		list->addItem(s);
	}
	
	// catch invalid commands
	catch(std::exception e)
	{
	
        	s += "(-1)";
		list->addItem(s);
		return (-1);	
	}
	return (0);
}
