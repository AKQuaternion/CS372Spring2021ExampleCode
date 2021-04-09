//
// Created by Chris Hartman on 2019-04-19.
//

#include "Command.hpp"

#include <utility>
void SayHiCommand::execute() { std::cout << "Hi!\n"; }

void ExitCommand::execute() { exit(0); }

void HACOnCommand::execute() { _hac->on(); }

HACOnCommand::HACOnCommand(std::shared_ptr<HomeAutomationComponent> hac)
      : _hac(std::move(hac)) {}

void HACOffCommand::execute() { _hac->off(); }

HACOffCommand::HACOffCommand(std::shared_ptr<HomeAutomationComponent> hac)
      : _hac(std::move(hac)) {}

void NullCommand::execute() { }

VoidFunctionCommand::VoidFunctionCommand(std::function<void()> f) : _f(std::move(f)) {}

void VoidFunctionCommand::execute() { _f(); }

MacroCommand::MacroCommand(std::vector<std::shared_ptr<Command>> commands)
   : _commands(std::move(commands)) {}

