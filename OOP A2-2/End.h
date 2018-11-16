#pragma once
#include "Action.h"
#include "Run.h"
#include <string>
using namespace std;
// end class
class End : public Action
{
public:
	End();
	~End();
	virtual bool execute();
	virtual string getName()const;
	virtual string getString() const;
};

