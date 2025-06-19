#include <SFML/Graphics.hpp>
#include <random>

int main() {
  // Define window size
  const int width = 800;
  const int height = 600;

  // Create a render window
  sf::RenderWindow window(sf::VideoMode(width, height), "Random Land");

  // Define three random colors
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> colorDist(0, 255);

  sf::Color color1(colorDist(gen), colorDist(gen), colorDist(gen));
  sf::Color color2(colorDist(gen), colorDist(gen), colorDist(gen));
  sf::Color color3(colorDist(gen), colorDist(gen), colorDist(gen));

  // Create a pixel array to represent the land
  sf::Uint8* pixels = new sf::Uint8[width * height * 4];

  // Randomly assign colors to pixels (replace with your land generation logic)
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int randomValue = rand() % 3; // Generate a random number between 0 and 2
      sf::Color color;
      if (randomValue == 0) {
        color = color1;
      } else if (randomValue == 1) {
        color = color2;
      } else {
        color = color3;
      }
      pixels[4 * (y * width + x)] = color.r;
      pixels[4 * (y * width + x) + 1] = color.g;
      pixels[4 * (y * width + x) + 2] = color.b;
      pixels[4 * (y * width + x) + 3] = 255; // Set alpha to 255 for full opacity
    }
  }

  // Create a texture from the pixel array
  sf::Texture texture;
  texture.create(width, height);
  texture.update(pixels);

  // Create a sprite from the texture
  sf::Sprite sprite(texture);

  // Delete the pixel array (no longer needed)
  delete[] pixels;

  // Main game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Clear window
    window.clear();

    // Draw the sprite
    window.draw(sprite);

    // Display the window contents
    window.display();
  }

  return 0;
}

