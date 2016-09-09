#include "LoadingState.hpp"
#include <render/OpenGLRenderer.hpp>
#include "RWGame.hpp"

LoadingState::LoadingState(RWGame* game) : State(game), next(nullptr) {
}

void LoadingState::enter() {
    game->newGame();
}

void LoadingState::exit() {
}

void LoadingState::tick(float dt) {
    RW_UNUSED(dt);

    // If background work is completed, switch to the next state
    if (getWorld()->_work->isEmpty()) {
        StateManager::get().exec(next);
    }
}

bool LoadingState::shouldWorldUpdate() {
    return false;
}

void LoadingState::setNextState(State* nextState) {
    next = nextState;
}

void LoadingState::handleEvent(const SDL_Event& e) {
    State::handleEvent(e);
}

void LoadingState::draw(GameRenderer* r) {
    static auto kLoadingString = GameStringUtil::fromString("Loading...");
    // Display some manner of loading screen.
    TextRenderer::TextInfo ti;
    ti.text = kLoadingString;
    auto size = r->getRenderer()->getViewport();
    ti.size = 25.f;
    ti.screenPosition = glm::vec2(50.f, size.y - ti.size - 50.f);
    ti.font = 2;
    ti.baseColour = glm::u8vec3(255);
    r->text.renderText(ti);
}
