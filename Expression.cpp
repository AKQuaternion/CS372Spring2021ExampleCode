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

int SumExpression::evaluate() const {
   return _lhs->evaluate() + _rhs->evaluate();
}

string SumExpression::toString() const  {
   return "(" + _lhs->toString() + "+" + _rhs->toString() + ")";
}

std::unique_ptr<Expression> SumExpression::clone() const {
   return std::make_unique<SumExpression>(_lhs->clone(),_rhs->clone());
}

MultiplyExpression::MultiplyExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

int MultiplyExpression::evaluate() const {
   return _lhs->evaluate() * _rhs->evaluate();
}

string MultiplyExpression::toString() const {
   return _lhs->toString() + "*" + _rhs->toString();
}

std::unique_ptr<Expression> MultiplyExpression::clone() const {
   return std::make_unique<MultiplyExpression>(_lhs->clone(),_rhs->clone());
}

SubtractExpression::SubtractExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

int SubtractExpression::evaluate() const {
   return _lhs->evaluate() - _rhs->evaluate();
}
string SubtractExpression::toString() const  {
   return _lhs->toString() + "-" + _rhs->toString();
}

std::unique_ptr<Expression> SubtractExpression::clone() const {
   return std::make_unique<SubtractExpression>(_lhs->clone(),_rhs->clone());
}

DivideExpression::DivideExpression(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
      :_lhs(move(lhs)),_rhs(move(rhs))
{}

int DivideExpression::evaluate() const {
   return _lhs->evaluate() / _rhs->evaluate();
}
string DivideExpression::toString() const  {
   return _lhs->toString() + "/" + _rhs->toString();
}

std::unique_ptr<Expression> DivideExpression::clone() const {
   return std::make_unique<DivideExpression>(_lhs->clone(),_rhs->clone());
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
   return std::make_unique<NumberExpression>(_number);
}
