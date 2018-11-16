#pragma once
#include "Action.h"
// abstract addition class
class AddExp : public Action
{
public:
	AddExp();
	~AddExp();
	virtual bool execute() = 0;
	virtual string getName()const;
	virtual string getString() const = 0;
};