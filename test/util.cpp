
#include <SFML/Audio.hpp>

void playSound(sf :: SoundBuffer &buffer) {
  sf :: Sound sound;
  sound.setBuffer(buffer);
  sound.play();
}
