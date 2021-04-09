//
// Created by Chris Hartman on 2019-04-19.
//

#ifndef CS372SPRING2021EXAMPLECODE_COMMAND_HPP
#define CS372SPRING2021EXAMPLECODE_COMMAND_HPP

#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include "HomeAutomationComponent.hpp"

class Command {
   public:
    virtual ~Command() = default;
    virtual void execute() =0;
};

/* In this example code we include the declarations of derived command
 * classes in the same file as the base class. In a "real" project they are
 * usually in a different include file, so that clients who deal only with
 * base class handles do not need to recomplile or change in any way when
 * a new command is added.
 * */

class SayHiCommand : public Command {
   public:
    void execute() override;
};

class ExitCommand : public Command {
   public:
    void execute() override;
};

class HACOnCommand : public Command {
   public:
    explicit HACOnCommand(std::shared_ptr<HomeAutomationComponent> hac);

    void execute() override;

   private:
    std::shared_ptr<HomeAutomationComponent> _hac;
};

class HACOffCommand : public Command {
public:
   explicit HACOffCommand(std::shared_ptr<HomeAutomationComponent> hac);

   void execute() override;

private:
   std::shared_ptr<HomeAutomationComponent> _hac;
};

class NullCommand : public Command {
public:
   void execute() override;
};

class VoidFunctionCommand : public Command {
   public:
    explicit VoidFunctionCommand(std::function<void()> f);
    void execute() override;

   private:
    std::function<void()> _f;
};

class MacroCommand : public Command {
   public:
    explicit MacroCommand(std::vector<std::shared_ptr<Command>> commands);

    void execute() override {
        for (const auto& s : _commands) s->execute();
    }

   private:
    std::vector<std::shared_ptr<Command>> _commands;
};

#endif  // CS372S2019DESIGNPATTERNSEXAMPLES_COMMAND_HPP
