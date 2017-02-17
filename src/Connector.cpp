#ifndef __CONNECTOR_CPP__
#define __CONNECTOR_CPP__

#include "Connector.h"

Connector::Connector(Base* lhs, Base* rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

string Connector::get_string() {
    return "cannot get command string of a connector";
}
