#include "Utility.h"

using namespace std;

void Utility::wait(int milliseconds) {
	this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}