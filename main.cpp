#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

// Variables
Texture texture_red; 
Texture texture_blue;
Sprite sprite_red;
Sprite sprite_blue;

int main() {

    // Cargamos la textura del archivo
    texture_red.loadFromFile("rcircle.png");
    texture_blue.loadFromFile("bluecircle.png"); // esta imagen tiene 128x128


    // Cargamos el material del sprite
    sprite_red.setTexture(texture_red);
    sprite_blue.setTexture(texture_blue);

    // Redefino el tamaño de la imagen del punto azul
    sprite_blue.setScale(0.25, 0.25);

    sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Puntos azules dentro del rojo en las esquinas con SFML");


    while (ventana.isOpen()) {
        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        // Limpiar la ventana
        ventana.clear();

        // Dibujar puntos rojos en las esquinas
        sprite_red.setPosition(0, 0); // Esquina superior izquierda
        ventana.draw(sprite_red);
        // Dibujar puntos azules dentro del rojo
        sprite_blue.setPosition(64-16, 64-16);
        ventana.draw(sprite_blue);

        sprite_red.setPosition(800 - 128, 0); // Esquina superior derecha
        ventana.draw(sprite_red);
        // Dibujar puntos azules dentro del rojo
        sprite_blue.setPosition(800- 64 - 16, 64 - 16);
        ventana.draw(sprite_blue);

        sprite_red.setPosition(0, 600 - 128); // Esquina inferior izquierda
        ventana.draw(sprite_red);
        // Dibujar puntos azules dentro del rojo
        sprite_blue.setPosition(64 - 16, 600 - 64 - 16);
        ventana.draw(sprite_blue);

        sprite_red.setPosition(800 - 128, 600 - 128); // Esquina inferior derecha
        ventana.draw(sprite_red);
        // Dibujar puntos azules dentro del rojo
        sprite_blue.setPosition(800 - 64 - 16, 600 - 64 - 16);
        ventana.draw(sprite_blue);

        ventana.display(); // Mostrar todo en la ventana
    }

    return 0;
}