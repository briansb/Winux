#include "support.h"

static std::ofstream myfile;

void ProcessArguments(int argc, char** argv) {
	// this routine is custom for each app
	if (argc > 1) window_title = LoseUnderscores(argv[1]); 
	else window_title = WINDOW_TITLE;
	if (argc > 2) {
		if (std::string(argv[2]) == "true") data_logging = true; else data_logging = false;
	}
	//if (argc > 3) number_of_digits = std::stoi(argv[3]); else number_of_digits = NUMBER_OF_DIGITS;

	return;
}

std::string LoseUnderscores(std::string s) {
	std::replace(s.begin(), s.end(), '_', ' '); // replace all '_' to ' '
	return s;
}

void OpenFileAndGenerateHeader(std::string filename) {
	if (myfile.is_open()) {
		std::cout << "File should not be open.  Exiting program." << std::endl;
		exit(1);
	} else {
		myfile.open(filename + ".csv");
		myfile << "Time,";
		myfile << "CPU Execution Time (ms)";
		myfile << std::endl;
	}
}
void WriteDataToFile(std::string datapoint, bool endofline) {
	if (myfile.is_open()) {
		if (!endofline) myfile << datapoint << ",";
		else myfile << datapoint << std::endl;
	}
	else {
		std::cout << "File is not open. Can not write data.  Exiting program." << std::endl;
		exit(1);
	}
}
void CloseFile() {
	myfile.close();
}



