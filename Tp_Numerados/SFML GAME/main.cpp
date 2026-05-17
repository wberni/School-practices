#include <SFML/Graphics.hpp>
#include <optional>

enum class gameState {
    SHOW_RED,
    SHOW_GREEN,
    SHOW_BLUE,
    NONE
};

class Game {
    public:
        Game();
        void run();
    private:
        gameState state;
        sf::RenderWindow window;
        void Render();
        void manageEvents();
};

Game::Game() : state(gameState::NONE), window(sf::VideoMode({400, 600}), "Mi ventana") {}

void Game::manageEvents() {
        while (const std::optional<sf::Event> event = window.pollEvent()) { //pollEvent() retorna un tipo de dato std::opsional, por cada evento externo. en este while estamos haciendo algo {} por cada evento que la ventena reconoce (mover, maximizar, etc.)
            //Cuando se toca el botón de cerrado
            if (event->is<sf::Event::Closed>()) {
                //Cerrar Ventana
                window.close();
            }

            if(const sf::Event::KeyPressed* KeyPressed = event->getIf<sf::Event::KeyPressed>()) { 
                //TRUE --> asifna dirección mem. de donde se guardo toda la info del teclazo al puntero Keypressed
                 //FALSE --> asigna al puntero KeyPressed nullptr porque no fue de tipo Event::Keypressed (false)
                // Si el resultado del if == false, salta el bloque, de lo contrarario, lo ejecuta.
                if (KeyPressed ->scancode == sf::Keyboard::Scancode::R) {
                    state = gameState::SHOW_RED;
                }
                if (KeyPressed->scancode == sf::Keyboard::Scancode::G) {
                    state = gameState::SHOW_GREEN;
                }
                if (KeyPressed->scancode == sf::Keyboard::Scancode::B) {
                    state = gameState::SHOW_BLUE;
                }
            }
            if (const sf::Event::KeyReleased* KeyReleased = event->getIf<sf::Event::KeyReleased>()) {
                if (KeyReleased->scancode == sf::Keyboard::Scancode::R && state == gameState::SHOW_RED) {
                    state = gameState::NONE;
                }
                if (KeyReleased->scancode == sf::Keyboard::Scancode::R && state == gameState::SHOW_GREEN) {
                    state = gameState::NONE;
                }
                if (KeyReleased->scancode == sf::Keyboard::Scancode::R && state == gameState::SHOW_BLUE) {
                    state = gameState::NONE;
                }
            }
            
        }
    }

void Game::Render() {
    switch(state) {
        case gameState::SHOW_RED: {
            window.clear(sf::Color(255, 0, 0)); //Dibuja el color de rgba
            break;
        }
        case gameState::SHOW_GREEN: {
            window.clear(sf::Color(0, 255, 0));
            break;
        }
        case gameState::SHOW_BLUE: {
            window.clear(sf::Color(0, 0, 255));
            break;
        }
        case gameState::NONE: {
            window.clear(sf::Color(200, 200, 200));
            break;
        }
    }
    window.display();
}

void Game::run() {
    while(window.isOpen()) {
        manageEvents();
        Render();
    }
}

int main() {
    Game game;
    game.run();
    return 0;
}


