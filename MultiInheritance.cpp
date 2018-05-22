#include <iostream>

using namespace std;
class Machine {
public:
	virtual void play() {
		cout << "Machine Playing..." << endl;
	}	
};

class MusicalInstrument {
public:
	virtual void play() {
		cout << "MusicalInstrument Playing..." << endl;
	}	
};

class Synthesizer: public Machine, public MusicalInstrument {
public:
	void play() {
		cout << "Synthesizer Playing..." << endl;
	}
	
	virtual ~Synthesizer() {
		cout << "Synthesizer released..." << endl;
	}
};

int main(int argc, char *argv[]) {
	Synthesizer *synth = new Synthesizer();
	
	synth->Machine::play();
	synth->MusicalInstrument::play();
	synth->play();
	
	delete synth;
}