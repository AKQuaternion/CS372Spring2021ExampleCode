
#ifndef CS372SPRING2020EXAMPLECODE_COMPOSITE_HPP
#define CS372SPRING2020EXAMPLECODE_COMPOSITE_HPP
#include <vector>
#include <memory>
#include <string_view>
#include <string>

class ComponentBase
{
public:
    explicit ComponentBase(std::string_view name);
    virtual ~ComponentBase();
    virtual void print()  const=0;
    [[nodiscard]] virtual int getSize() const=0;
    [[nodiscard]] std::string getName() const;
private:
    const std::string _name;
};

class File : public ComponentBase
{
public:
    File(std::string_view name, int size);
    void print()  const override;
    [[nodiscard]] int getSize() const override;
private:
    int _size;
};

class Folder : public ComponentBase
{
public:
    using ComponentBase::ComponentBase;
    using ChildContainer = std::vector<std::unique_ptr<ComponentBase>>;
    void print()  const override;
    [[nodiscard]] int getSize() const override;
    void add(std::unique_ptr<ComponentBase>);
    void remove(std::string_view name);
    [[nodiscard]] const ChildContainer & getChildren() const;
private:
    ChildContainer _children;
};

#endif /* Composite_hpp */
