#pragma once

#include <boost/variant.hpp>
#include <string>

struct DESTROY { };
struct CHANGE_LIFE { int value; };
struct UICONTEXT { std::string c; };

typedef boost::variant<
	DESTROY,
	CHANGE_LIFE,
	UICONTEXT
	> GOMessage;

/** \brief Message recu et envoyer par les GameObject, qui les dispatchent aux GameComponents
*
*/
class GOMessageHandler : public boost::static_visitor<void>
{
public:
	GOMessageHandler();
	~GOMessageHandler();

	virtual void operator()(DESTROY const& e) {}
	virtual void operator()(CHANGE_LIFE const& e) {}
	virtual void operator()(UICONTEXT const& e) {}
};



typedef boost::variant<
	DESTROY
> SCMessage;

class SCMessageHandler : public boost::static_visitor<void>
{
public:
	SCMessageHandler();
	~SCMessageHandler();

	virtual void operator()(DESTROY const& e) {}
};
