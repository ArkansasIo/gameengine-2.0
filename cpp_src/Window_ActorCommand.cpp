#include "Window_ActorCommand.h"

Window_ActorCommand::Window_ActorCommand() : Window_Command(0, 0, 192, 0), _actorId(0) {
}

Window_ActorCommand::~Window_ActorCommand() {
}

void Window_ActorCommand::setup(int actorId) {
    _actorId = actorId;
}
