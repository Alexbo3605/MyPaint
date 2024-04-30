#pragma once

#include "SerializableShapes.h"

#include <vector>
#include <stack>
#include <iostream>

class Paint
{
	private:
		sf::ContextSettings settings;
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;	

		sf::RectangleShape menu;
		sf::Font font;

		// initialization
		void initVariables();
		void initWindow();
		void initInk();
		void initCircle();
		void initTriangle();
		void initRectangle();
		void initImageSprite();
		void initFonts();


		// Mouse pos
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		// Entities
		std::vector<sf::Drawable*> objectsArray;
		std::stack<sf::Drawable*> objectsArrayBuffer;
		

		//ink
		sf::Vector2f ink;
		std::vector<sf::Vector2f> inks;
		int currentInk = 0;
		SerializableCircleShape inkcer;

		//circle
		SerializableCircleShape circle;

		//triangle
		SerializableCircleShape triangle;

		//rectangle
		SerializableRectangleShape rectangle;

		//image
		sf::Texture imageTexture;
		std::vector<sf::Texture> imageTextures;
		SerializableSprite imageSprite;

		//subsidiary
		sf::Vector2f startPos;

		//drawing object
		enum class paintObject {
			none,
			ink,
			rectangle,
			triangle,
			circle
		};
		paintObject state;

		//buttons
		sf::Text clear_text;
		sf::Text small_text, normal_text, big_text;
		sf::RectangleShape red_pen, black_pen, blue_pen, yellow_pen, white_pen, purple_pen;
		sf::Text triangle_shape_text, rectangle_shape_text, circle_shape_text, ink_shape_text;
		sf::Text save_text, load_text, load_image_text;
		sf::Text filling_text;

		//dependencies
		std::string loadFileName = "load.png";
		const int menuHeigth = 100;
		const int FPS = 30;
		const unsigned int antialiasingLevel = 5;
		std::string filename = "testBin.bin";

		const int smallFont = 8;
		const int normalFont = 12;
		const int bigFont = 16;

		sf::Color fillColor = sf::Color::Green; 
		const sf::Color fillColorVoid = sf::Color(0, 0, 0, 0);

		
	public:
		Paint();
		virtual ~Paint();

		const bool running() const;
		bool clearMemory();

		//update
		void update();
		void updateMousePosition();
		void updateColors();
		void updatePaintColor();
		void updateInkSize();
		void updateState();
		void updateFilling();

		//render
		void pollEvents();
		void render();
		void transformInk();
		void virtualShapeRectangle();
		void virtualShapeCircle();
		void renderAll();
		void renderTexts();

		//draw
		void spawnInk();
		void spawnCircle();
		void spawnTriangle();
		void spawnRectangle();
		void spawnImage();

		//file
		void saveInFile();
		void LoadFromFile();

		// Logic
		bool isDrawing = false;
		bool mouseButtonIsPressed = false;
		bool filling = true;
		bool leftMouseClicked = false;

		bool ZPressed = false;
		bool YPressed = false;
};