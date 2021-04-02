#ifndef ARMOR_HPP
#define ARMOR_HPP

#include <memory>
#include <string>

class ArmorComponent {
public:
   virtual ~ArmorComponent() = default;
   [[nodiscard]] virtual std::string description() const = 0;
   [[nodiscard]] virtual int getAC() const = 0;
};

class PlateArmor : public ArmorComponent {
   [[nodiscard]] std::string description() const override;
   [[nodiscard]] int getAC() const override;
};

class LeatherArmor : public ArmorComponent {
   [[nodiscard]] std::string description() const override;
   [[nodiscard]] int getAC() const override;
};

class ArmorDecorator : public ArmorComponent {
public:
   explicit ArmorDecorator(std::unique_ptr<ArmorComponent> wrappee);
   [[nodiscard]] std::string description() const override = 0;
   [[nodiscard]] int getAC() const override =0;
private:
   std::unique_ptr<ArmorComponent> _wrappee;
};

class RustyDecorator : public ArmorDecorator {
public:
   using ArmorDecorator::ArmorDecorator;
   [[nodiscard]] std::string description() const override;
   [[nodiscard]] int getAC() const override;
};


class MagicDecorator : public ArmorDecorator {
public:
   using ArmorDecorator::ArmorDecorator;
   [[nodiscard]] std::string description() const override;
   [[nodiscard]] int getAC() const override;
};

#endif
