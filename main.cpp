#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Err.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <iostream>
#include <string>
#include <queue>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>

//#define kf sf::Keyboard::Key:: ;

/*
enum mouseEventKeys {
	ME_UNKNOWN = 0,
	ME_COORD = 1,
	ME_KEY_LEFT,
	ME_KEY_RIGHT,
	ME_KEY_SPECIAL
};
*/
/*
struct mouseEvent {

	sf::Mouse::Button meKey;

	size_t values[2]; //(release, press) || (pos_x, pos_y)
};
struct keyEvent {
	std::string keyName {'\0'};
};
*/

enum e_scenes {
	SC_EDITOR,
	SC_FLIGHT_SINGLE,
};

//keeping track of some keys (lookback porpuses)
struct keyBools {
	bool mouseLeft;
	bool mouseRight;

	bool keySpace;
	bool keyTab;
};

struct param {
	size_t window_x = 1000;
	size_t window_y = 1000;
};

int main() {
	param runtime_settings;

	sf::RenderWindow window(sf::VideoMode(runtime_settings.window_x, runtime_settings.window_y), "plane creator", 1 | 4);
	window.setVerticalSyncEnabled(false);
	window.setFramerateLimit(60);

	sf::Keyboard::Key registeredKeys[] {
		sf::Keyboard::Key::W,	
		sf::Keyboard::Key::A,	
		sf::Keyboard::Key::S,	
		sf::Keyboard::Key::D,

		sf::Keyboard::Key::LShift,
		sf::Keyboard::Key::RShift,
		sf::Keyboard::Key::LControl,
		sf::Keyboard::Key::RControl,
	};
	
	e_scenes currentScene = SC_EDITOR;

	keyBools lastKeyState;	
		
	while(window.isOpen()) {
		//lists of inputs
		std::vector<sf::Event::KeyEvent> specialKeysPressed;
		std::vector<sf::Mouse::Button> mouseButtonsPressed; //will ever really hold 1, maybe 2 items
		std::vector<sf::Keyboard::Key> keyboardButtonsPressed; //all buttons pressed in frame
		
		// | START INPUT GATHER |
		sf::Event event;
        while (window.pollEvent(event)) {
			auto eventTypeEnum = event.type;
            switch (eventTypeEnum) {
				case sf::Event::Closed:
                	window.close();
					break;
				
				case sf::Event::MouseButtonPressed:
					mouseButtonsPressed.push_back(event.mouseButton.button);
					break;
				case sf::Event::KeyPressed:
					specialKeysPressed.push_back(event.key);
					break;
				default:
					break;
			}
        }

		for (int i = 0; i < sizeof registeredKeys / sizeof registeredKeys[0]; i++) 
			if (sf::Keyboard::isKeyPressed(registeredKeys[i])) 
				keyboardButtonsPressed.push_back(registeredKeys[i]);	

		// | END INPUT GATHER |
		if (currentScene == SC_EDITOR) {
			// | START LOGIC |
				
			// | END LOGIC |
			// | START CALC |

			// | END CALC |
		} else if (currentScene == SC_FLIGHT_SINGLE) {	
			// | START LOGIC |
			
			// | END LOGIC |
			// | START CALC |

			// | END CALC |
		} else {

		}
		// | START DRAW |
		window.clear(sf::Color::Black);

		// remember to draw each object

		window.display();
		// | END DRAW |
	}

	return 0;
}
