//
//  Visitor.hpp
//  2017CS372DesignPatterns
//
//  Created by Chris Hartman on 4/12/17.
//  Copyright © 2017 Chris Hartman. All rights reserved.
//

#ifndef CS372SPRING2021EXAMPLECODE_VISITOR_HPP
#define CS372SPRING2021EXAMPLECODE_VISITOR_HPP

class File;
class Folder;
#include <cstddef>

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(const File *) = 0;
    virtual void visit(const Folder *) = 0;
};

class PrintVisitor : public Visitor {
public:
    virtual void visit(const File *);
    virtual void visit(const Folder *);
private:
    int _tab=0;
};

class SizeVisitor : public Visitor {
public:
    virtual void visit(const File *);
    virtual void visit(const Folder *);
    std::size_t getSize() const {return _size;}
private:
   std::size_t _size=0;
};
#endif /* Visitor_hpp */
