// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
//
// Created by Chris Hartman on 3/1/21.
//

#include "Expression.hpp"
using std::move;
using std::string;

SumExpression::SumExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
   :_lhs(move(lhs)),_rhs(move(rhs))
{}

SumExpression::SumExpression(const SumExpression &orig):_lhs(orig._lhs->clone()),_rhs(orig._rhs->clone()) {
}

int SumExpression::evaluate() const {
   return _lhs->evaluate() + _rhs->evaluate();
}

string SumExpression::toString() const  {
   return "(" + _lhs->toString() + "+" + _rhs->toString() + ")";
}

std::unique_ptr<Expression> SumExpression::clone() const {
   return std::make_unique<SumExpression>(*this);
}

MultiplyExpression::MultiplyExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

MultiplyExpression::MultiplyExpression(const MultiplyExpression &orig):_lhs(orig._lhs->clone()),_rhs(orig._rhs->clone()) {
}

int MultiplyExpression::evaluate() const {
   return _lhs->evaluate() * _rhs->evaluate();
}

string MultiplyExpression::toString() const {
   return _lhs->toString() + "*" + _rhs->toString();
}

std::unique_ptr<Expression> MultiplyExpression::clone() const {
   return std::make_unique<MultiplyExpression>(*this);
}

SubtractExpression::SubtractExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

SubtractExpression::SubtractExpression(const SubtractExpression &orig):_lhs(orig._lhs->clone()),_rhs(orig._rhs->clone()) {
}

int SubtractExpression::evaluate() const {
   return _lhs->evaluate() - _rhs->evaluate();
}
string SubtractExpression::toString() const  {
   return _lhs->toString() + "-" + _rhs->toString();
}

std::unique_ptr<Expression> SubtractExpression::clone() const {
   return std::make_unique<SubtractExpression>(*this);
}

DivideExpression::DivideExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

DivideExpression::DivideExpression(const DivideExpression &orig):_lhs(orig._lhs->clone()),_rhs(orig._rhs->clone()) {
}

int DivideExpression::evaluate() const {
   return _lhs->evaluate() / _rhs->evaluate();
}

string DivideExpression::toString() const  {
   return _lhs->toString() + "/" + _rhs->toString();
}

std::unique_ptr<Expression> DivideExpression::clone() const {
   return std::make_unique<DivideExpression>(*this);
}

NumberExpression::NumberExpression(int num) : _number(num)
{}

int NumberExpression::evaluate() const {
   return _number;
}

string NumberExpression::toString() const  {
   return std::to_string(_number);
}

std::unique_ptr<Expression> NumberExpression::clone() const {
   return std::make_unique<NumberExpression>(*this);
}

