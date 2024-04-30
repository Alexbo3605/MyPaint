#include "paint.h"

//                   //
//    ІНІЦІАЛІЗАЦІЯ  //
//                   // 
void Paint::initVariables()
{
	this->window = nullptr;
}

void Paint::initWindow() //ініціалізація вікна
{
	this->videoMode.height = 800;
	this->videoMode.width = 1000;

	settings.antialiasingLevel = antialiasingLevel;

	this->window = new sf::RenderWindow(this->videoMode, "Paint", sf::Style::Titlebar | sf::Style::Close, settings);
	this->window->setFramerateLimit(FPS);

	this->menu.setSize(sf::Vector2f(1000, menuHeigth)); //встановлюєм розміри меню
	this->menu.setFillColor(sf::Color(195, 195, 195));
}

const bool Paint::running() const
{
	return this->window->isOpen();
}


void Paint::initInk()
{
	objectsArray.reserve(1000);
	this->inkcer.setRadius(smallFont);
	this->inkcer.setFillColor(sf::Color::White);
	state = paintObject::ink;
}

void Paint::initCircle()
{
	this->circle.setRadius(50);
	this->circle.setOutlineThickness(smallFont);
	this->circle.setOutlineColor(sf::Color::White);
	this->circle.setFillColor(sf::Color::White);
}

void Paint::initTriangle()
{
	this->triangle.setRadius(50);
	this->triangle.setPointCount(3);
	this->triangle.setOutlineThickness(smallFont);
	this->triangle.setOutlineColor(sf::Color::White);
	this->triangle.setFillColor(sf::Color::White);
}

void Paint::initRectangle()
{
	this->rectangle.setSize(sf::Vector2f(50, 50));
	this->rectangle.setOutlineThickness(smallFont);
	this->rectangle.setOutlineColor(sf::Color::White);
	this->rectangle.setFillColor(sf::Color::White);
}

void Paint::initImageSprite()
{
	this->imageSprite.setPosition(0, 100);
}

void Paint::initFonts() //підключаєм стилі
{
	this->font.loadFromFile("fonts/hatsch.otf");

	this->clear_text.setFont(this->font);
	this->clear_text.setFillColor(sf::Color::White);
	this->clear_text.setCharacterSize(35);
	this->clear_text.setPosition(sf::Vector2f(870, 8));
	this->clear_text.setString("Clear");

	this->red_pen.setSize(sf::Vector2f(20, 20));
	this->red_pen.setFillColor(sf::Color::Red);
	this->red_pen.setOutlineColor(sf::Color::Black);
	this->red_pen.setOutlineThickness(1);
	this->red_pen.setPosition(sf::Vector2f(400, 20));

	this->black_pen.setSize(sf::Vector2f(20, 20));
	this->black_pen.setFillColor(sf::Color::Black);
	this->black_pen.setOutlineColor(sf::Color::Black);
	this->black_pen.setOutlineThickness(1);
	this->black_pen.setPosition(sf::Vector2f(430, 20));

	this->blue_pen.setSize(sf::Vector2f(20, 20));
	this->blue_pen.setFillColor(sf::Color::Blue);
	this->blue_pen.setOutlineColor(sf::Color::Black);
	this->blue_pen.setOutlineThickness(1);
	this->blue_pen.setPosition(sf::Vector2f(460, 20));

	this->yellow_pen.setSize(sf::Vector2f(20, 20));
	this->yellow_pen.setFillColor(sf::Color::Yellow);
	this->yellow_pen.setOutlineColor(sf::Color::Black);
	this->yellow_pen.setOutlineThickness(1);
	this->yellow_pen.setPosition(sf::Vector2f(490, 20));

	this->white_pen.setSize(sf::Vector2f(20, 20));
	this->white_pen.setFillColor(sf::Color::White);
	this->white_pen.setOutlineColor(sf::Color::Black);
	this->white_pen.setOutlineThickness(1);
	this->white_pen.setPosition(sf::Vector2f(520, 20));

	this->purple_pen.setSize(sf::Vector2f(20, 20));
	this->purple_pen.setFillColor(sf::Color::Magenta);
	this->purple_pen.setOutlineColor(sf::Color::Black);
	this->purple_pen.setOutlineThickness(1);
	this->purple_pen.setPosition(sf::Vector2f(550, 20));

	this->small_text.setFont(this->font);
	this->small_text.setFillColor(sf::Color::White);
	this->small_text.setCharacterSize(20);
	this->small_text.setPosition(sf::Vector2f(10, 20));
	this->small_text.setString("Small");

	this->normal_text.setFont(this->font);
	this->normal_text.setFillColor(sf::Color::White);
	this->normal_text.setCharacterSize(20);
	this->normal_text.setPosition(sf::Vector2f(90, 20));
	this->normal_text.setString("Normal");

	this->big_text.setFont(this->font);
	this->big_text.setFillColor(sf::Color::White);
	this->big_text.setCharacterSize(20);
	this->big_text.setPosition(sf::Vector2f(190, 20));
	this->big_text.setString("Big");

	this->filling_text.setFont(this->font);
	this->filling_text.setFillColor(sf::Color::White);
	this->filling_text.setCharacterSize(20);
	this->filling_text.setPosition(sf::Vector2f(250, 20));
	this->filling_text.setString("Filling");

	this->triangle_shape_text.setFont(this->font);
	this->triangle_shape_text.setFillColor(sf::Color::White);
	this->triangle_shape_text.setCharacterSize(20);
	this->triangle_shape_text.setPosition(sf::Vector2f(10, 60));
	this->triangle_shape_text.setString("Triangle");

	this->circle_shape_text.setFont(this->font);
	this->circle_shape_text.setFillColor(sf::Color::White);
	this->circle_shape_text.setCharacterSize(20);
	this->circle_shape_text.setPosition(sf::Vector2f(130, 60));
	this->circle_shape_text.setString("Circle");

	this->rectangle_shape_text.setFont(this->font);
	this->rectangle_shape_text.setFillColor(sf::Color::White);
	this->rectangle_shape_text.setCharacterSize(20);
	this->rectangle_shape_text.setPosition(sf::Vector2f(230, 60));
	this->rectangle_shape_text.setString("Rectangle");

	this->ink_shape_text.setFont(this->font);
	this->ink_shape_text.setFillColor(sf::Color::White);
	this->ink_shape_text.setCharacterSize(20);
	this->ink_shape_text.setPosition(sf::Vector2f(370, 60));
	this->ink_shape_text.setString("Ink");

	this->load_text.setFont(this->font);
	this->load_text.setFillColor(sf::Color::White);
	this->load_text.setCharacterSize(35);
	this->load_text.setPosition(sf::Vector2f(600, 55));
	this->load_text.setString("Load");

	this->save_text.setFont(this->font);
	this->save_text.setFillColor(sf::Color::White);
	this->save_text.setCharacterSize(35);
	this->save_text.setPosition(sf::Vector2f(740, 55));
	this->save_text.setString("Save");

	this->load_image_text.setFont(this->font);
	this->load_image_text.setFillColor(sf::Color::White);
	this->load_image_text.setCharacterSize(35);
	this->load_image_text.setPosition(sf::Vector2f(600, 8));
	this->load_image_text.setString("Load Image");
}


Paint::Paint() //ініціалізуємо всі елементи
{
	this->initVariables();
	this->initInk();
	this->initRectangle();
	this->initTriangle();
	this->initCircle();
	this->initImageSprite();
	this->initFonts();
	this->initWindow();
}

Paint::~Paint() {
	delete this->window;
}


//                      //
//    СТВОРЕННЯ ПОДІЙ   //
//                      // 
void Paint::spawnInk() //створення чорнил
{
	this->ink = this->mousePosView;
	this->inks.push_back(this->ink);
}

void Paint::spawnCircle()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isDrawing)
	{
		if ((!isDrawing) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			startPos = sf::Vector2f(static_cast<float>(mousePosView.x), static_cast<float>(mousePosView.y));

			SerializableCircleShape* circlePtr = new SerializableCircleShape(circle);
			circlePtr->setRadius(0);
			circlePtr->setOrigin(0, 0);
			circlePtr->setPosition(startPos);

			this->objectsArray.push_back(circlePtr); 
			isDrawing = true;
		}
	}
}


void Paint::spawnTriangle()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isDrawing)
	{
		if ((!isDrawing) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			startPos = sf::Vector2f(static_cast<float>(mousePosView.x), static_cast<float>(mousePosView.y));

			SerializableCircleShape* trianglePtr = new SerializableCircleShape(triangle);
			trianglePtr->setRadius(0);
			trianglePtr->setOrigin(0, 0);
			trianglePtr->setPosition(startPos);
			
			this->objectsArray.push_back(trianglePtr); 
			isDrawing = true;
		}
	}
}

void Paint::spawnRectangle()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isDrawing)
	{
		if ((!isDrawing) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
			startPos = sf::Vector2f(static_cast<float>(mousePosView.x), static_cast<float>(mousePosView.y));
			sf::Vector2f size = { 0,0 };

			SerializableRectangleShape* rectanglePtr = new SerializableRectangleShape(rectangle);
			rectanglePtr->setPosition(startPos);
			rectanglePtr->setSize(size);

			this->objectsArray.push_back(rectanglePtr);
			isDrawing = true;
		}
	}
}

void Paint::spawnImage()
{
	/*loadFileName = QString selectedFilePath = QFileDialog::getOpenFileName();*/
	SerializableSprite* imageSpritePtr = new SerializableSprite(imageSprite);

	imageTexture.loadFromFile(loadFileName);
	imageSpritePtr->setTexture(imageTexture);
	
	imageTextures.push_back(imageTexture);
	this->objectsArray.push_back(imageSpritePtr);
}

bool Paint::clearMemory()
{
	for (auto& i : objectsArray) //очищаємо всі елементи
	{
		delete i;
	}
	this->objectsArray.clear();

	while (!objectsArrayBuffer.empty()) //очищаємо буфер елементів
	{
		if (objectsArrayBuffer.top() != nullptr)
		{
			delete objectsArrayBuffer.top();
		}
		objectsArrayBuffer.pop();
	}
	imageTextures.clear(); //видаляємо текстури
	return true;
}


void Paint::pollEvents() //обробка подій
{
	while (this->window->pollEvent(this->ev)) //поки є події
	{
		if (this->ev.type == sf::Event::Closed)//закриття вікнна
		{
			this->window->close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->load_image_text.getGlobalBounds().contains(this->mousePosView))
			{
				this->spawnImage();
			}
			if (this->load_text.getGlobalBounds().contains(this->mousePosView))
			{
				this->LoadFromFile();
			}
			else if (this->save_text.getGlobalBounds().contains(this->mousePosView))
			{
				this->saveInFile();
			}
			else if (this->clear_text.getGlobalBounds().contains(this->mousePosView)) //кнопка очищення
			{
				this->inks.clear(); this->currentInk = 0;
				this->imageTextures.clear();
				this->clearMemory();
				isDrawing = false;
			}
			else //малювання
			{
				if (this->mousePosView.y > menuHeigth) //якщо мишка нище ніж меню то малюєм
				{
					if (!isDrawing)
					{
						switch (state) {
						case paintObject::ink:
							this->spawnInk();
							break;
						case paintObject::circle:
							this->spawnCircle();
							break;
						case paintObject::triangle:
							this->spawnTriangle();
							break;
						case paintObject::rectangle:
							this->spawnRectangle();
							break;
						}
					}
					else
					{
						switch (state) {
						case paintObject::circle:
						case paintObject::triangle:
							this->virtualShapeCircle();
							break;
						case paintObject::rectangle:
							this->virtualShapeRectangle();
							break;
						}
					}
				}
			}
		}
		if (this->ev.type == sf::Event::MouseButtonPressed)
		{
			mouseButtonIsPressed = true;
		}
		else if (this->ev.type == sf::Event::MouseButtonReleased) 
		{
			mouseButtonIsPressed = false;
		}


		// Ctrl+Z (підтримує одноразове натискання клавіш)
		if (this->ev.type == sf::Event::KeyPressed) 
		{
			if (this->ev.key.code == sf::Keyboard::Z && !ZPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
			{
				if (!objectsArray.empty()) 
				{
					objectsArrayBuffer.emplace(objectsArray.back());
					objectsArray.pop_back();
				}
				ZPressed = true;
			}

			//Ctrl+Y (підтримує одноразове натискання клавіш)
			else if (this->ev.key.code == sf::Keyboard::Y && !YPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
			{
				if (!objectsArrayBuffer.empty()) 
				{
					objectsArray.push_back(objectsArrayBuffer.top());
					objectsArrayBuffer.pop();
				}
				YPressed = true;
			}
		}
		else if (this->ev.type == sf::Event::KeyReleased) 
		{
			// Якщо клавіша відпущена, встановіть відповідну змінну у стан натисненої
			if (this->ev.key.code == sf::Keyboard::Z) 
			{
				ZPressed = false;
			}
			else if (this->ev.key.code == sf::Keyboard::Y) 
			{
				YPressed = false;
			}
		}

		// Ctrl+Z (підтримує затискання клавіш)
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
		//{
		//	std::cout << "Undo action " << objectsArray.size() << "  " << objectsArrayBuffer.size() << std::endl;
		//	if (!objectsArray.empty()) {
		//		objectsArrayBuffer.emplace(objectsArray.back());  
		//		objectsArray.pop_back();
		//	}	
		//}
		//Ctrl+Y (підтримує затискання клавіш)
		//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
		//{
		//	
		//	std::cout << "Redo action "  << objectsArray.size() << std::endl;
		//	if (!objectsArrayBuffer.empty()) {
		//		objectsArray.push_back(objectsArrayBuffer.top());
		//		objectsArrayBuffer.pop();
		//	}
		//}
	}
}


//                //
//    ОНОВЛЕННЯ   //
//                // 
void Paint::updatePaintColor() //встановлюєм колір елементів
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		fillColor = sf::Color::Green;

		if (this->red_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::Red;
		}
		else if (this->black_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::Black;
		}
		else if (this->blue_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::Blue;
		}
		else if (this->yellow_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::Yellow;
		}
		else if (this->white_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::White;
		}
		else if (this->purple_pen.getGlobalBounds().contains(this->mousePosView)) {
			fillColor = sf::Color::Magenta;
		}
		if (fillColor != sf::Color::Green) {
			this->inkcer.setFillColor(fillColor);

			this->inkcer.setOutlineColor(fillColor);
			this->rectangle.setOutlineColor(fillColor);
			this->circle.setOutlineColor(fillColor);
			this->triangle.setOutlineColor(fillColor);

			this->rectangle.setFillColor(fillColor);
			this->circle.setFillColor(fillColor);
			this->triangle.setFillColor(fillColor);
		}
	}
}

void Paint::updateInkSize() //оновлення розміру малювання
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //якщо лівим кліком на текст
	{
		if (this->small_text.getGlobalBounds().contains(this->mousePosView))
		{
			this->inkcer.setRadius(smallFont);

			this->rectangle.setOutlineThickness(smallFont);
			this->circle.setOutlineThickness(smallFont);
			this->triangle.setOutlineThickness(smallFont);

		}
		else if (this->normal_text.getGlobalBounds().contains(this->mousePosView))
		{
			this->inkcer.setRadius(normalFont);

			this->rectangle.setOutlineThickness(normalFont);
			this->circle.setOutlineThickness(normalFont);
			this->triangle.setOutlineThickness(normalFont);
		}
		else if (this->big_text.getGlobalBounds().contains(this->mousePosView))
		{
			this->inkcer.setRadius(bigFont);

			this->rectangle.setOutlineThickness(bigFont);
			this->circle.setOutlineThickness(bigFont);
			this->triangle.setOutlineThickness(bigFont);
		}
	}
}

void Paint::updateState() //оновлення фігури малювання
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //якщо лівим кліком на текст
	{
		if (this->ink_shape_text.getGlobalBounds().contains(this->mousePosView))
		{
			state = paintObject::ink;
			isDrawing = false;
		}
		else if (this->circle_shape_text.getGlobalBounds().contains(this->mousePosView))
		{
			state = paintObject::circle;
		}
		else if (this->rectangle_shape_text.getGlobalBounds().contains(this->mousePosView))
		{
			state = paintObject::rectangle;
		}
		else if (this->triangle_shape_text.getGlobalBounds().contains(this->mousePosView))
		{
			state = paintObject::triangle;
		}
		if (!this->leftMouseClicked) 
		{
			this->leftMouseClicked = true; // Позначаємо, що клік відбувся у поточному фреймі
			if (this->filling_text.getGlobalBounds().contains(this->mousePosView)) 
			{
				filling = !filling;
			}
		}
	}
	else 
	{
		this->leftMouseClicked = false; // Позначаємо, що клік більше не затримується
	}
}

void Paint::updateFilling() //оновлення фігури малювання
{
	if (!filling)// немає заливки
	{
		this->rectangle.setFillColor(fillColorVoid);
		this->circle.setFillColor(fillColorVoid);
		this->triangle.setFillColor(fillColorVoid);
	}
	else {
		fillColor = rectangle.getOutlineColor();
		this->rectangle.setFillColor(fillColor);
		this->circle.setFillColor(fillColor);
		this->triangle.setFillColor(fillColor);
	}
}

void Paint::updateMousePosition() //оновлення координат миші
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}


void Paint::updateColors() //анімація наведення на текст
{

	// Кольори за замовчуванням
	sf::Color defaultColor = sf::Color::White;
	sf::Color selectedColor = sf::Color(0, 0, 0);

	// Встановлення за замовчуванням
	this->clear_text.setFillColor(defaultColor);
	this->small_text.setFillColor(defaultColor);
	this->normal_text.setFillColor(defaultColor);
	this->big_text.setFillColor(defaultColor);
	this->filling_text.setFillColor(defaultColor);
	this->triangle_shape_text.setFillColor(defaultColor);
	this->circle_shape_text.setFillColor(defaultColor);
	this->rectangle_shape_text.setFillColor(defaultColor);
	this->ink_shape_text.setFillColor(defaultColor);
	this->save_text.setFillColor(defaultColor);
	this->load_text.setFillColor(defaultColor);
	this->load_image_text.setFillColor(defaultColor);

	// кнопка очищення
	if (this->clear_text.getGlobalBounds().contains(this->mousePosView)) {
		this->clear_text.setFillColor(selectedColor);
	}

	// кнопки вибору розміру
	if (this->small_text.getGlobalBounds().contains(this->mousePosView)) {
		this->small_text.setFillColor(selectedColor);
	}
	else if (this->normal_text.getGlobalBounds().contains(this->mousePosView)) {
		this->normal_text.setFillColor(selectedColor);
	}
	else if (this->big_text.getGlobalBounds().contains(this->mousePosView)) {
		this->big_text.setFillColor(selectedColor);
	}

	//вибір заливки
	if (this->filling_text.getGlobalBounds().contains(this->mousePosView) || filling) {
		this->filling_text.setFillColor(selectedColor);
	}

	// кнопки вибору фігур
	if (this->triangle_shape_text.getGlobalBounds().contains(this->mousePosView) || state == paintObject::triangle) {
		this->triangle_shape_text.setFillColor(selectedColor);
	}
	else if (this->circle_shape_text.getGlobalBounds().contains(this->mousePosView) || state == paintObject::circle) {
		this->circle_shape_text.setFillColor(selectedColor);
	}
	else if (this->rectangle_shape_text.getGlobalBounds().contains(this->mousePosView) || state == paintObject::rectangle) {
		this->rectangle_shape_text.setFillColor(selectedColor);
	}
	else if (this->ink_shape_text.getGlobalBounds().contains(this->mousePosView) || state == paintObject::ink) {
		this->ink_shape_text.setFillColor(selectedColor);
	}

	//кнопки збереження та відновлення
	if (this->save_text.getGlobalBounds().contains(this->mousePosView)) {
		this->save_text.setFillColor(selectedColor);
	}
	else if (this->load_text.getGlobalBounds().contains(this->mousePosView)) {
		this->load_text.setFillColor(selectedColor);
	}
	else if (this->load_image_text.getGlobalBounds().contains(this->mousePosView)) {
		this->load_image_text.setFillColor(selectedColor);
	}
}


void Paint::update() //оновлення фрейму
{
	this->pollEvents(); //обробляємо всі події
	this->updateMousePosition(); //оновлюємо позицію миші
	this->updateColors(); //оновлюємо кольори кнопок
	this->updatePaintColor(); //оновлюємо колір малювання
	this->updateState(); //оновлюємо стан малювання
	this->updateFilling(); //оновлюємо стан заливки
	this->updateInkSize(); //оновлюємо розмір "пера"
}


//                  //
//    ВІДМАЛЬОВКА   //
//                  // 
void Paint::renderAll() 
{
	if (!inks.empty() && state == paintObject::ink) //перетворення чорнил
	{ 
		this->transformInk();
	}

	for (auto &i : this->objectsArray) //відмальовка
	{
		this->window->draw(*i);
	}
	this->window->draw(this->menu);
}

void Paint::renderTexts() // оновлюємо текст
{
	this->window->draw(this->clear_text);

	this->window->draw(this->red_pen);
	this->window->draw(this->black_pen);
	this->window->draw(this->blue_pen);
	this->window->draw(this->yellow_pen);
	this->window->draw(this->white_pen);
	this->window->draw(this->purple_pen);

	this->window->draw(this->small_text);
	this->window->draw(this->normal_text);
	this->window->draw(this->big_text);
	this->window->draw(this->filling_text);

	this->window->draw(this->triangle_shape_text);
	this->window->draw(this->circle_shape_text);
	this->window->draw(this->rectangle_shape_text);
	this->window->draw(this->ink_shape_text);

	this->window->draw(this->load_text);
	this->window->draw(this->save_text);
	this->window->draw(this->load_image_text);
}

void Paint::render() //відмальовка вікна
{
	this->window->clear();

	this->renderAll();
	this->renderTexts();

	this->window->display();
}

void Paint::transformInk() //створення чорнил
{
	//проходимо по вектору точок і тансформуємо у вектор кіл
	float circleRadius = inkcer.getRadius() * 0.8; // Радіус кіл (щільність малювання)
	int size = this->inks.size() - 1;

	if (mouseButtonIsPressed) //якщо лкм затиснута
	{ 
		bool check = true;
		for (int i = currentInk; i < size; ++i) 
		{
			check = false;
			
			const sf::Vector2f& pointA = inks[i];
			const sf::Vector2f& pointB = inks[i + 1];

			float distance = std::sqrt(((pointB.x - pointA.x) * (pointB.x - pointA.x)) + ((pointB.y - pointA.y) * (pointB.y - pointA.y)));

			// Розбиваємо відрізок на менші відрізки
			int numSegments = std::ceil(distance / (circleRadius)) + 1; // Кількість сегментів

			for (int j = 1; j < numSegments; ++j) 
			{
				float t = static_cast<float>(j) / static_cast<float>(numSegments - 1);
				sf::Vector2f segmentPoint(pointA.x + t * (pointB.x - pointA.x), pointA.y + t * (pointB.y - pointA.y)); //лінійна інтерполяція

				SerializableCircleShape* inkcerPtr = new SerializableCircleShape(inkcer);
				inkcerPtr->setPosition(segmentPoint.x - circleRadius, segmentPoint.y - circleRadius);
				this->objectsArray.push_back(inkcerPtr);
			}

			if (!this->inks.empty()) {
				currentInk = this->inks.size() - 1;
			}
		}
		
		if (check) {
			SerializableCircleShape* inkcerPtr = new SerializableCircleShape(inkcer);
			inkcerPtr->setPosition(inks[size]); 
			this->objectsArray.push_back(inkcerPtr); 
		}
	}
	else{
		currentInk = this->inks.size() ;
	}
}


void Paint::virtualShapeRectangle() //динамічне оновлення прямокутника
{
	if (mouseButtonIsPressed)
	{
		if (!objectsArray.empty())
		{
			sf::Vector2f endPos(static_cast<float>(mousePosView.x), static_cast<float>(mousePosView.y));
			sf::Vector2f size = endPos - static_cast<SerializableRectangleShape*>(objectsArray.back())->getPosition();
			static_cast<SerializableRectangleShape*>(objectsArray.back())->setSize(size);
		}
	}
	else {
		isDrawing = false;
	}
}

void Paint::virtualShapeCircle() //динамічне оновлення фігури
{
	if (mouseButtonIsPressed)
	{
		if (!objectsArray.empty())
		{
			sf::Vector2f endPos(static_cast<float>(mousePosView.x), static_cast<float>(mousePosView.y));
			sf::Vector2f size = endPos - static_cast<SerializableCircleShape*>(objectsArray.back())->getPosition();

			float x = static_cast<SerializableCircleShape*>(objectsArray.back())->getPosition().x;
			float y = static_cast<SerializableCircleShape*>(objectsArray.back())->getPosition().y;
			float radius = std::sqrt(((endPos.x - x) * (endPos.x - x)) + ((endPos.y - y) * (endPos.y - y)));

			static_cast<SerializableCircleShape*>(objectsArray.back())->setRadius(radius);
			static_cast<SerializableCircleShape*>(objectsArray.back())->setOrigin(radius, radius);
		}
	}
	else {
		isDrawing = false;
	}
}


//                             //
//  ЗБЕРЕЖЕННЯ ТА ВІДНОВЛЕННЯ  //
//                             // 
void Paint::saveInFile() 
{
	std::ofstream file(filename, std::ios::binary | std::ios::out);
	if (file.is_open()) 
	{
		int imageTexturesCount = 0;
		for (const auto& obj : objectsArray) 
		{
			if (typeid(*obj) == typeid(SerializableCircleShape)) 
			{
				SerializableCircleShape* circle = dynamic_cast<SerializableCircleShape*>(obj);
				circle->serialize(file);
			}
			else if (typeid(*obj) == typeid(SerializableRectangleShape)) 
			{
				SerializableRectangleShape* circle = dynamic_cast<SerializableRectangleShape*>(obj);
				circle->serialize(file);
			}
			else if (typeid(*obj) == typeid(SerializableSprite)) 
			{
				SerializableSprite* circle = dynamic_cast<SerializableSprite*>(obj);
				circle->serialize(file, imageTextures[imageTexturesCount]);
				imageTexturesCount++;
			}
		}
		file.close();
	}
}
	
void Paint::LoadFromFile()
{
	this->clearMemory();

	std::ifstream file(filename, std::ios::binary | std::ios::in);
	if (file.is_open()) 
	{
		while (!file.eof()) 
		{
			size_t len;
			file.read((char*)&len, sizeof(len));

			if (file.eof()) break;

			char* buf = new char[len];
			file.read(buf, len);
		
			// Create an object from the appropriate type
			if (strcmp(buf, "CircleShape") == 0 )
			{
				SerializableCircleShape* obj = new SerializableCircleShape();
				obj->deserialize(file);
				objectsArray.push_back(obj);
			}
			else if (strcmp(buf, "RectangleShape") == 0)
			{
				SerializableRectangleShape* obj = new SerializableRectangleShape();
				obj->deserialize(file);
				objectsArray.push_back(obj);
			}
			else if (strcmp(buf, "Sprite") == 0)
			{
				SerializableSprite* obj = new SerializableSprite();
				obj->deserialize(file, &imageTextures);
				objectsArray.push_back(obj);
			}
			delete[] buf;
		}
		file.close();
	}
}

