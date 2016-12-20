#pragma once

#include <boost/variant.hpp>

struct DESTROY { };
struct CHANGE_LIFE { int value; };

typedef boost::variant<
	DESTROY,
	CHANGE_LIFE
	> Message;

class MessageHandler : public boost::static_visitor<void>
{
public:
	MessageHandler();
	~MessageHandler();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}

};

