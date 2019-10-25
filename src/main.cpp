#include <iostream>
#include "game.h"

int main() {
  const std::size_t kFramesPerSecond{60};
  const std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  const std::size_t kScreenWidth{640};
  const std::size_t kScreenHeight{640};

  game asteroidGame(kScreenWidth, kScreenHeight, kMsPerFrame);
  asteroidGame.reset();
  asteroidGame.run();
  std::cout << "Score - " << asteroidGame.getScore() << std::endl;
  std::cout << "Game Finished!\n";
  return 0;
}