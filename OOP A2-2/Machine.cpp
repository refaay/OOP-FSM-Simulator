#include "Machine.h"

Machine::Machine(const string& s){ // FSM constructor
	States = new vector < State >;
	Transitions = new vector < Transition > ;
	ended = false; // fsm not ended yet
	ifstream infile; // Input file for each machine
	infile.open(s + ".txt"); // open fsm definition file
	if (!infile.is_open()) throw string("Failed to load file!"); // ifstream error
	char str[100]; // max line size assumed to be 100
	stringstream ss; // for easier string manipulation
	string s2; // extracted from ss
	infile.getline(str, 100); // first line
	ss << str;
	ss >> s2;
	if (s2 != "FSM") throw string(s + "'s input file doesn't start with FSM!\n" + "Actual == " + s2); // first word
	ss >> s2;
	if (s2 != s) throw string(s + "'s FSM name doesn't match opened one!\n" + "Actual == " + s2); // second word

	// Variables
	infile.getline(str, 100); // second line
	ss.clear(); // to return iterator and flush previous line
	ss << str;
	ss >> s2;
	if (s2 != "VAR") throw  string(s + " input file doesn't have VAR part!\n" + "Actual == " + s2); // first word
	while (ss >> s2){ // till end of variables
		if (!ss.eof()){
			if (s2[s2.length() - 1] != ',') throw string(s + " FSM variables miss separating commas!\n" + "Actual == " + s2);
			s2.erase(s2.length() - 1, 1);
		}
		Var* temp = new Var; // temporary variable
		if (findVar(s2[0])) throw string(s + " FSM have duplicate variables!\n" + "v == " + s2);
		(*temp).setName(s2[0]); // assumed variables are only 1 chararter, if not, get first char only, limitting to around 20 variables
		(*temp).setValue(0); // initially
		(Vars).push_back(temp);
	}

	// States
	while (s2 != "States:" && !infile.eof()){ // skip lines till States
		infile.getline(str, 100); // third and all unrelated following lines
		ss.clear(); ss << str; ss >> s2;
	}
	if (infile.eof()) throw  string(s + " doesn't have \"States:\""); // if no actual (*States) listed in file, exit
	while (!infile.eof()){ // file size limit
		infile.getline(str, 100); // (*States)' lines, max = 100 chars
		ss.clear(); ss << str; ss >> s2;
		if (s2 == "Transitions:") break; // get all (*States)
		if (s2.length() != 0){ // skip empty lines
			if (s2[s2.length() - 1] != ':') throw string(s + " FSM States' names miss \":\"!\n" + "Actual == " + s2);
			s2.erase(s2.length() - 1, 1); // erase ':'
			State temps; // temporary state
			vector<Action*> tempva;
			if (findState(s2)) throw string(s + " FSM have duplicate States!\n" + "state == " + s2); // if already found
			temps.setName(s2); // names state
			while (!ss.eof()){ // till end of current line
				ss >> s2; // get next action
				if (s2 == "wait" || s2 == "wait,") { // construct & push wait
					Wait* tw = new Wait(temps.getName());
					(*tw).setTrans(Transitions);
					tempva.push_back(tw);
					break;
				}
				else if (s2 == "end" || s2 == "end,"){ // construct & push end
					End* te = new End;
					tempva.push_back(te);
					break;
				}
				else if (findVar(s2[0])){ // construct & push addexp, variables cannot be equal o, w, e, r, s to avoid clash with other actions
					if (isdigit(s2[4]) && isdigit(s2[2])){ // add ints action
						AddExpInts* tai = new AddExpInts(int(s2[2] - '0'), int(s2[4] - '0'), getVar(s2[0]));
						tempva.push_back(tai);
					}
					else if (isdigit(s2[4])){ // add var int action
						if (findVar(s2[2])) {
							AddExpVarInt* tavi = new AddExpVarInt(getVar(s2[2]), int(s2[4] - '0'), getVar(s2[0]));
							tempva.push_back(tavi);
						}
						else  throw string(s + "'s Add var int expression uses an undefined variable!\n" + "Actual == " + s2);
					}
					else if (isdigit(s2[2])){ // add var int action
						if (findVar(s2[4])){
							AddExpVarInt* tavi = new AddExpVarInt(getVar(s2[4]), int(s2[2] - '0'), getVar(s2[0]));
							tempva.push_back(tavi);
						}
						else  throw string(s + "'s Add var int expression uses an undefined variable!\n" + "Actual == " + s2);
					}
					else if (!findVar(s2[4]) || !findVar(s2[2])) throw string(s + "'s Add vars expression uses undefined variable!\n" + "Actual == " + s2);
					else {
						// AddVars Action
						AddExpVars* tav = new AddExpVars(getVar(s2[2]), getVar(s2[4]), getVar(s2[0]));
						tempva.push_back(tav);
					}
				}
				else if (s2 == "out"){ // construct & push out action
					for (int r = 0; r < 100; r++) // clear str
						str[r] = NULL;
					ss.getline(str, 100, ','); // commas cannot be used in printed strings
					s2 = str;
					if (s2[0] == '\"' || (s2[0] == ' ' && s2[1] == '\"')){ // outstring
						s2.erase(s2.length() - 1, 1);  // erase ending "
						s2.erase(0, 1); // erase beginning space
						s2.erase(0, 1); // erase beginning "
						OutString* tos = new OutString(s2);
						tempva.push_back(tos);
					}
					else if (findVar(s2[1])){ // print var
						OutExp*  tov = new OutExp(getVar(s2[1]));
						tempva.push_back(tov);
					}
					else throw string(s + "'s Out Action parameters undefined!\n" + "Actual == " + s2);
				}
				else if (s2 == "sleep"){ // construct & push sleep action
					ss >> s2;
					if (s2[s2.length() - 1] != ',') throw string(s + "'s FSM sleep miss ending commas!\n" + "Actual == " + s2);
					s2.erase(s2.length() - 1, 1); // erase ','
					if (validateSleepAmount(stoi(s2, nullptr, 10))){ 
						SleepA* ts = new SleepA(stoi(s2, nullptr, 10)); 
						tempva.push_back(ts);
					}
					else throw string(s + "'s sleep action uses unvalidated time amount!\n" + "Actual == " + s2);
				}
				else if (s2 == "run"){ // construct & push run action
					ss >> s2;
					if (s2[s2.length() - 1] != ',') throw string(s + "'s FSM run miss ending commas!\n" + "Actual == " + s2);
					s2.erase(s2.length() - 1, 1); // erase ','
					if (findFSM(s2))  throw string(s + "'s FSM run will create an infinite loop!\n" + "Actual == " + s2); // runs only if this machine was not opened and stored in FSM stack before
					Run* tr = new Run(s2);
					tempva.push_back(tr);
				}
				else {
					throw string(s + " has an undefined action!\n" + "Actual == " + s2); // if not defined at all
				}
			}
			// push actions in state & push state
			temps.setActions(tempva);
			(*States).push_back(temps);
		}
	}
	if (infile.eof()) throw  string(s + " doesn't have \"Transitions:\"");

	// Transitions part
	while (!infile.eof()){
		infile.getline(str, 100); // transitions' lines
		ss.clear();
		ss << str;
		ss >> s2;
		if (s2.length() != 0){ // skip empty lines
			Transition tempt; // temp
			if (s2[s2.length() - 1] != ',') throw string(s + " FSM transitions miss separating commas!\n" + "s2 == " + s2);
			s2.erase(s2.length() - 1, 1); // erase commas
			if (!findState(s2)) throw string("Transitions use undefined States!");
			tempt.setCurrent(s2); // first state in transition
			ss >> s2;
			if (s2[s2.length() - 1] != ',') throw string(s + " FSM transitions miss separating commas!\n" + "s2 == " + s2);
			s2.erase(s2.length() - 1, 1); // erase commas
			tempt.setNext(s2); // second state in transition
			ss >> s2;
			if (!isdigit(s2[0])) throw string("Transitions use non integer values!");
			tempt.setValue(int(s2[0] - '0')); // transition value
			if (findTrans(tempt.getCurrent(), tempt.getNext(), tempt.getValue())) throw string(s + " FSM have duplicate transitions!\n" + "state == " + s2);
			(*Transitions).push_back(tempt); // push into transitions

		}
	}
	currentState = (*States)[0].getName(); // first state will be executed first
	(*rM).push_back(s); // push into running machines
}

Machine::~Machine() // delete all non static pointers
{
	for (int p = 0; p < Vars.size(); p++)
		delete(Vars[p]);
	for (int p = 0; p < currentActions.size(); p++)
		delete(currentActions[p]);
	delete(States);
	delete(Transitions);
}

bool Machine::findVar(const char& v) const{ // returns true if variable already found
	bool found = false;
	for (unsigned int i = 0; i < (Vars).size() && !found; i++){ // search
		found = (v == (*Vars[i]).getName());
	}
	return found;
}

Var* Machine::getVar(const char& c)const{ // return variable of given name, always validated before use
	bool found = false;
	unsigned int i;
	for (i = 0; i < (Vars).size() && !found; i++){ // search
		found = (c == (*Vars[i]).getName());
	}
	return (Vars)[i - 1];
}

bool Machine::findState(const string& v) const{ // search for state of given name
	bool found = false;
	for (unsigned int i = 0; i < (*States).size() && !found; i++){ // search
		found = (v == (*States)[i].getName());
	}
	return found;
}

bool Machine::findTrans(const string& v1, const string& v2, const int& v3) const{ // search for transition of given data
	bool found = false;
	for (unsigned int i = 0; i < (*Transitions).size() && !found; i++){ // search
		found = (v1 == (*Transitions)[i].getCurrent() && v2 == (*Transitions)[i].getNext() && v3 == (*Transitions)[i].getValue());
	}
	return found;
}

bool Machine::execute(){ // execute machines, starting by first action of first state
	do{
		bool found = false;
		unsigned int i, j;
		for (i = 0; i < (*States).size() && !found; i++){ // search for the needed state
			found = (currentState == (*States)[i].getName());
		}
		currentActions = (*States)[i - 1].getActions(); // get the state's actions

		for (j = 0; j < currentActions.size(); j++){ // execute all actions for current state
			(*currentActions[j]).execute();
			if ((*currentActions[j]).getName() == "Run") // if a run action, execute a new machine of the previously given name
				Machine((*currentActions[j]).getString()).execute();
		}
		j--;
		if ((*currentActions[j]).getName() == "Wait"){ // if a wait action, get the name of the next state
			currentState = (*currentActions[j]).getString();
		}
		else if ((*currentActions[j]).getName() == "End"){ // if an end action, pop last machine and terminate if it was the first to be executed
			(*rM).pop_back();
			if ((*rM).size() == 0)
				throw string("All states finished!");
			ended = true;
		}
	} while (!ended); // till current machine is ended
	return true;
}

bool Machine::findFSM(const string& fsm){ // true if given machine name was run before
	bool found = false;
	for (unsigned int i = 0; i < (*rM).size() && !found; i++){ // search
		found = (fsm == (*rM)[i]);
	}
	return found;
}

bool Machine::validateSleepAmount(const int& a)const{ // more that 1000 second is unvalid
	return (a <= 1000);
}