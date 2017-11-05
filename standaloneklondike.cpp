#include "standaloneklondike.hpp"
#include "consoleview.hpp"
#include "locallogic.hpp"

StandAloneKlondike::StandAloneKlondike()
    : Klondike(new LocalLogic(), new ConsoleView()) {}