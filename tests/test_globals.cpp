#include "test_globals.hpp"

#include <GameConfig.hpp>

#if RW_TEST_WITH_DATA
std::string Global::getGamePath() {
    return GameConfig("openrw.ini").getGameDataPath();
}
#endif
