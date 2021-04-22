
#ifndef CS372SPRING2021EXAMPLECODE_COMPOSITE_HPP
#define CS372SPRING2021EXAMPLECODE_COMPOSITE_HPP
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "Visitor.hpp"

class ComponentBase {
public:
   explicit ComponentBase(std::string_view name);
   virtual ~ComponentBase();
   virtual void print() const = 0;
   virtual void accept(Visitor *v) const = 0;
   [[nodiscard]] virtual int getSize() const = 0;
   [[nodiscard]] std::string getName() const;

private:
   const std::string _name;
};

template <typename T>
class ComponentBaseCRTP : public ComponentBase {
   using ComponentBase::ComponentBase;
public:
   void accept(Visitor *v) const override {
      v->visit(static_cast<const T*>(this));
   }
};

class File : public ComponentBaseCRTP<File> {
public:
   File(std::string_view name, int size);
   void print() const override;
   [[nodiscard]] int getSize() const override;

private:
   int _size;
};

class Folder : public  ComponentBaseCRTP<Folder> {
public:
   using ComponentBaseCRTP<Folder>::ComponentBaseCRTP;
   using ChildContainer = std::vector<std::unique_ptr<ComponentBase>>;
   void print() const override;
   [[nodiscard]] int getSize() const override;
   void add(std::unique_ptr<ComponentBase>);
   void remove(std::string_view name);
   [[nodiscard]] const ChildContainer &getChildren() const;

private:
   ChildContainer _children;
};

#endif /* Composite_hpp */
