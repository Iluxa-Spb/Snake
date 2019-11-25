#include "Functions.h"

Texture texture_;
Texture fieldTexture_;
Texture SnakeSkreen_;
Texture Fon_;
Sprite fieldk;
Sprite apple;
Sprite snakeBodyHotizont;
Sprite snakeBodyVertically;
Sprite TurnDownRight;
Sprite TurnDownLeft;
Sprite TurnUpRight;
Sprite TurnUpLeft;
Sprite snakeHeadUp;
Sprite snakeHeadDown;
Sprite snakeHeadLeft;
Sprite snakeHeadRight;
Sprite snakeTailUp;
Sprite snakeTailDown;
Sprite snakeTailLeft;
Sprite snakeTailRight;
Sprite Screen_;
Sprite fonfield_;
Font font;

void menu()
{
	texture_.loadFromFile("snake-graphics.png");
	SnakeSkreen_.loadFromFile("logo.png");
	Fon_.loadFromFile("fon.jpg");
	fieldTexture_.loadFromFile("field.jpg");
	fonfield_.setTexture(Fon_);
	fonfield_.setTextureRect(IntRect(0,0,2000,2000));
	Screen_.setTexture(SnakeSkreen_);
	Screen_.setTextureRect(IntRect(0, 0, 420, 152));
	fieldk.setTexture(fieldTexture_);
	fieldk.setTextureRect(IntRect(0, 0, 160, 160));
	fieldk.setScale(0.2, 0.2);
	apple.setTexture(texture_);
	apple.setTextureRect(IntRect(0, 192, 64, 64));
	apple.setScale(0.5, 0.5);
	snakeBodyHotizont.setTexture(texture_);
	snakeBodyHotizont.setTextureRect(IntRect(64, 0, 64, 64));
	snakeBodyHotizont.setScale(0.5, 0.5);
	snakeBodyVertically.setTexture(texture_);
	snakeBodyVertically.setTextureRect(IntRect(128, 64, 64, 64));
	snakeBodyVertically.setScale(0.5, 0.5);
	TurnDownRight.setTexture(texture_);
	TurnDownRight.setTextureRect(IntRect(0, 0, 64, 64));
	TurnDownRight.setScale(0.5, 0.5);
	TurnDownLeft.setTexture(texture_);
	TurnDownLeft.setTextureRect(IntRect(128, 0, 64, 64));
	TurnDownLeft.setScale(0.5, 0.5);
	TurnUpRight.setTexture(texture_);
	TurnUpRight.setTextureRect(IntRect(0, 64, 64, 64));
	TurnUpRight.setScale(0.5, 0.5);
	TurnUpLeft.setTexture(texture_);
	TurnUpLeft.setTextureRect(IntRect(128, 128, 64, 64));
	TurnUpLeft.setScale(0.5, 0.5);
	snakeHeadUp.setTexture(texture_);
	snakeHeadUp.setTextureRect(IntRect(192, 0, 64, 64));
	snakeHeadUp.setScale(0.5, 0.5);
	snakeHeadDown.setTexture(texture_);
	snakeHeadDown.setTextureRect(IntRect(256, 64, 64, 64));
	snakeHeadDown.setScale(0.5, 0.5);
	snakeHeadLeft.setTexture(texture_);
	snakeHeadLeft.setTextureRect(IntRect(192, 64, 64, 64));
	snakeHeadLeft.setScale(0.5, 0.5);
	snakeTailUp.setTexture(texture_);
	snakeTailUp.setTextureRect(IntRect(192, 128, 64, 64));
	snakeTailUp.setScale(0.5, 0.5);
	snakeHeadRight.setTexture(texture_);
	snakeHeadRight.setTextureRect(IntRect(256, 0, 64, 64));
	snakeHeadRight.setScale(0.5, 0.5);
	snakeTailDown.setTexture(texture_);
	snakeTailDown.setTextureRect(IntRect(256, 192, 64, 64));
	snakeTailDown.setScale(0.5, 0.5);
	snakeTailLeft.setTexture(texture_);
	snakeTailLeft.setTextureRect(IntRect(192, 192, 64, 64));
	snakeTailLeft.setScale(0.5, 0.5);
	snakeTailRight.setTexture(texture_);
	snakeTailRight.setTextureRect(IntRect(256, 128, 64, 64));
	snakeTailRight.setScale(0.5, 0.5);

	static const int MAX_EL = 10;
	Time speed = microseconds(100000);
	Field field;
	Snake snake;
	float movetime = 1;
	Score score[MAX_EL];
	std::fstream file;
	char name[MAX_EL][MAX_EL];
	bool endGame = false;
	char symbol;
	file.open("SCORE.ini");
	for ( int i = 0; i < MAX_EL; i++)
	{
		if (file.eof())
			break;
		score[i].input(file);
	}
	file.close();
	field.input();
	snake.input();
	font.loadFromFile("CyrilicOld.TTF");
	Text text1("Continiue", font, 20);
	text1.setColor(Color::White);
	Text text2("New Game", font, 20);
	text2.setColor(Color::White);
	Text text3("Score", font, 20);
	text3.setColor(Color::White);
	Text text4("Options", font, 20);
	text4.setColor(Color::White);
	Text text5("Exit", font, 20);
	text5.setColor(Color::White);
	int count = 0;
	Event event;
	int scrX = GetSystemMetrics(SM_CXSCREEN);
	int scrY = GetSystemMetrics(SM_CYSCREEN);
	RenderWindow window(sf::VideoMode(scrX, scrY), "Snake");
	sf::VideoMode::getFullscreenModes;
	Screen_.setPosition((scrX / 2 - 420/2), 0);
	SnakeSkreen_.setSmooth(true);
	texture_.setSmooth(true);
	Fon_.setSmooth(true);
	window.setVerticalSyncEnabled(true);

	while (!endGame)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(Screen_);
		if (Keyboard::isKeyPressed(Keyboard::Up)){
			if ((count > 0) && (count <= 4))
				count--;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			if ((count >= 0) && (count <= 3))
				count++;
		}

		if (Keyboard::isKeyPressed(Keyboard::Return)){
			switch (count){
			case (0) :
			{
						 continueGame(field, snake, movetime, window, scrX, scrY, speed);
						 if (field.getGameOver()){
							 MessageBox(
								 NULL,
								 "You loze! Game Over",
								 "Snake",
								 MB_YESNO | //Да нет (кнопки)
								 MB_DEFBUTTON1 | //Выделеная кнопка
								 MB_ICONEXCLAMATION | //Тип иконки
								 MB_DEFAULT_DESKTOP_ONLY
								 );
						 }
						 system("cls");
						 if (field.getPause() == 'p')
						 {
							 field.delPause();
							 break;
						 }
						 for (int i = 0; i < MAX_EL; i++)
						 {
							 if (score[i].getscore() < field.getscore())
							 {
								 std::cout << "Congratulations! You have " << i + 1 << " top score!" << "\n";
								 std::cout << "Enter you name." << "\n";
								 char winName[MAX_EL + 1];
								 for (int i = 0; i < MAX_EL + 1; i++)
								 {
									 winName[i] = '\0';
								 }
								 std::cin.getline(winName, MAX_EL + 1);
								 score[MAX_EL - 1].setNewScore(winName, field.getscore(), movetime);
								 Score temp;
								 for (int j = MAX_EL - 1; j > i; --j)
								 {
									 temp = score[j];
									 score[j] = score[j - 1];
									 score[j - 1] = temp;
								 }
								 break;
							 }
						 }
						 break;
			}
			case (1) :
			{
						 run(field, snake, movetime, window, scrX, scrY, speed);
						 if (field.getGameOver()){
							 MessageBox(
								 NULL,
								 "You loze! Game Over",
								 "Snake",
								 MB_YESNO | //Да нет (кнопки)
								 MB_DEFBUTTON1 | //Выделеная кнопка
								 MB_ICONEXCLAMATION | //Тип иконки
								 MB_DEFAULT_DESKTOP_ONLY
								 );
						 }
						 system("cls");
						 for (int i = 0; i < MAX_EL; i++)
						 {
							 if (score[i].getscore() < field.getscore())
							 {
								 std::cout << "Congratulations! You have " << i + 1 << " place!" << "\n";
								 std::cout << "Enter you name." << "\n";
								 char winName[MAX_EL + 1];
								 std::cin.getline(winName, MAX_EL + 1);
								 score[MAX_EL - 1].setNewScore(winName, field.getscore(), movetime);
								 Score temp;
								 for (int j = MAX_EL - 1; j > i; --j)
								 {
									 temp = score[j];
									 score[j] = score[j - 1];
									 score[j - 1] = temp;
								 }
								 break;
							 }
						 }
						 break;
			}
			case (2) :
			{
						 Text text("**********SCORE**********", font, 20);
						 text.setColor(Color::White);
						 text.setPosition(scrX / 2.0f - 150, scrY / 2.0f -32 - 100);
						 window.draw(text);
						 for (int i = 0; i < MAX_EL; i++)
						 {
							 char string[19];
							 char num[5];
							 sprintf(num, "%d", score[i].getscore());
							 for (int j = 0; j < 10; j++)
							 {
								 if (score[i].getSymbolName(j) == '\0') string[j] = ' ';
								 else string[j] = score[i].getSymbolName(j);
							 }
							 string[10] = ' ';
							 sprintf(num, "%d", score[i].getscore());
							 string[11] = num[0];
							 string[12] = num[1];
							 if ('\0' == num[2]) string[13] = ' ';
								 else string[13] == num[2];
							 sprintf(num, "%d", score[i].getPlayerTime());
							 string[14] = ' ';
							 string[15] = num[0];
							 string[16] = num[1];
							 string[17] = num[2];
							 string[18] = num[3];
							 string[19] = num[4];
							 text.setString(string);

							 text.setPosition(scrX / 2.0f - 150, scrY / 2.0f + 32 * i - 100);
							 window.draw(text);
						 }
						 window.display();
						 while (event.KeyPressed){
							 sleep(seconds(0.1));
						 if (Keyboard::isKeyPressed(Keyboard::Return)) break;
						 }
						 break;
						 
			}
			case (3) :
			{
						 Text TextSpeed("Set speed 1-5", font, 20);
						 TextSpeed.setColor(Color::White);
						 TextSpeed.setPosition(scrX / 2.0f - 50, scrY / 2.0f);
						 window.draw(TextSpeed);
						 window.display();
						 while (event.KeyPressed){
							 sleep(seconds(0.1));
							 if (Keyboard::isKeyPressed(Keyboard::Num1)){
								 speed = microseconds(70000);
								 break;
							 }
							 if (Keyboard::isKeyPressed(Keyboard::Num2)){
								 speed = microseconds(200000);
								 break;
							 }
							 if (Keyboard::isKeyPressed(Keyboard::Num3)){
								 speed = microseconds(400000);
								 break;
							 }
							 if (Keyboard::isKeyPressed(Keyboard::Num4)){
								 speed = microseconds(600000);
								 break;
							 }
							 if (Keyboard::isKeyPressed(Keyboard::Num5)){
								 speed = microseconds(800000);
								 break;
							 }
						 }
						 break;
			}
			case (4) :
			{
						 Text exit("Are you sure? (Y/N)", font, 20);
						 exit.setColor(Color::White);
						 exit.setPosition(scrX / 2.0f - 80, scrY / 2.0f);
						 window.draw(exit);
						 window.display();
						 while (event.KeyPressed){
							 if (Keyboard::isKeyPressed(Keyboard::Y)){
								 endGame = true;
								 file.open("SCORE.ini");
								 for (size_t i = 0; i < MAX_EL; i++)
								 {
									 score[i].output(file);
								 }
								 file.close();
								 snake.output();
								 field.output();
								 break;
							 }
							 if (Keyboard::isKeyPressed(Keyboard::N))
								 break;
						 }
			}
			{
			default:
				break;
			}
			}
		}
		window.clear();
		window.draw(Screen_);
		//TEXT Continiue
		if (count == 0)
			text1.setColor(Color::Red);
		else
			text1.setColor(Color::White);
		text1.setPosition(scrX / 2.0f - 32, scrY / 2.0f);
		window.draw(text1);
		//TEXT New Game
		if (count == 1)
			text2.setColor(Color::Red);
		else
			text2.setColor(Color::White);
		text2.setPosition(scrX / 2.0f - 32, scrY / 2.0f + 32);
		window.draw(text2);
		//TEXT Score
		if (count == 2)
			text3.setColor(Color::Red);
		else
			text3.setColor(Color::White);
		text3.setPosition(scrX / 2.0f - 32, scrY / 2.0f + 32 * 2);
		window.draw(text3);
		//TEXT Options
		if (count == 3)
			text4.setColor(Color::Red);
		else
			text4.setColor(Color::White);
		text4.setPosition(scrX / 2.0f - 32, scrY / 2.0f + 32 * 3);
		window.draw(text4);
		//TEXT Exit
		if (count == 4)
			text5.setColor(Color::Red);
		else
			text5.setColor(Color::White);
		text5.setPosition(scrX / 2.0f - 32, scrY / 2.0f + 32 * 4);
		window.draw(text5);

		window.display();
		sleep(seconds(0.1));
	}
}
void run(Field & field, Snake & snake, float & movetime, RenderWindow & window, int & scrX, int & scrY, Time & speed)
{	
	Clock clock;
	Time time;
	Text text(" ", font, 20);
	text.setColor(Color::White);
	text.setPosition(scrX / 2 - field.getMAX() * 32 / 2, scrY / 2 - field.getMAX() * 32 / 2 + field.getMAX() * 32);
	field.defField();
	snake.defsnake();
	int positionX = scrX / 2 - field.getMAX() * 32 / 2;
	int positionY = scrY / 2 - field.getMAX() * 32 / 2;
	fonfield_.setPosition(positionX, positionY);
	fonfield_.setScale(0.31,0.31);
	while (!field.getGameOver())
	{
		time = clock.getElapsedTime();
		if (field.checkItem())
			field.generateItem();
		if (field.checkField(snake.gethead()))
		{
			if (field.checkField2(snake.gethead()))
			{
				
				snake.stepField(field.getDirection());
			}
		}
		else
			snake.step(field.getDirection());
		if (field.checkChange(snake.gethead()))
		{
			snake.push(field.getItem());
			field.push(snake.gethead());
			field.addscore();
		}
		else
			field.change(snake.gettemp(), snake.gethead());

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(fonfield_);
		int max = field.getMAX();
		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j < max; j++)
			{
				if (field.getField(i, j) == '*'){
					fieldk.setPosition(positionX + j * 32, positionY + i * 32);
					window.draw(fieldk);
				}
				if (field.getField(i, j) == '+'){
					apple.setPosition(positionX + j * 32, positionY + i * 32);
					window.draw(apple);
				}
				if (field.getField(i, j) == ' ') { continue; }
			}
		}
		switch (field.getDirection())
		{
		case'w':
		{
				   snakeHeadUp.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadUp);
				   break;
		}
		case's':
		{
				   snakeHeadDown.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadDown);
				   break;
		}
		case'a':
		{
				   snakeHeadLeft.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadLeft);
				   break;
		}
		case'd':
		{
				   snakeHeadRight.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadRight);
				   break;
		}
		}
		
		for (int i = 1; i < snake.numhead()-1; i++)
		{
			if ((snake.yCoordinates(i - 1) + 2) == (snake.yCoordinates(i + 1))) {
				snakeBodyHotizont.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyHotizont);
			}
			if ((snake.yCoordinates(i - 1) - 2) == (snake.yCoordinates(i + 1))) {
				snakeBodyHotizont.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyHotizont);
			}
			if ((snake.xCoordinates(i - 1) + 2) == (snake.xCoordinates(i + 1))) {
				snakeBodyVertically.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyVertically);
			}
			if ((snake.xCoordinates(i - 1) - 2) == (snake.xCoordinates(i + 1))) {
				snakeBodyVertically.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyVertically);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) - 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) - 1)))){
				TurnDownRight.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnDownRight);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) - 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) - 1)))){
				TurnUpRight.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnUpRight);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) + 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) + 1)))) {
				TurnUpLeft.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnUpLeft);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) + 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) + 1)))) {
				TurnDownLeft.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnDownLeft);
			}
		}
		if (snake.yCoordinates(0) == (snake.yCoordinates(1) + 1)){
			snakeTailLeft.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailLeft);
		}
		if (snake.yCoordinates(0) == (snake.yCoordinates(1) - 1)){
			snakeTailRight.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailRight);
		}
		if (snake.xCoordinates(0) == (snake.xCoordinates(1) + 1)){
			snakeTailUp.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailUp);
		}
		if (snake.xCoordinates(0) == (snake.xCoordinates(1) - 1)){
			snakeTailDown.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailDown);
		}

		char num[3];
		sprintf(num, "%d", field.getscore());
		char stringScore[10] {'S', 'c', 'o', 'r', 'e', ':', ' ', num[0], num[1], num[2]};
		text.setString(stringScore);
		window.draw(text);

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Right)) { field.setDirectionOb('d'); }
		else if (Keyboard::isKeyPressed(Keyboard::Up)) { field.setDirectionOb('w'); }
		else if (Keyboard::isKeyPressed(Keyboard::Left)) { field.setDirectionOb('a'); }
		else if (Keyboard::isKeyPressed(Keyboard::Down)) { field.setDirectionOb('s'); }
		else if (Keyboard::isKeyPressed(Keyboard::P)) { field.setDirectionOb('p'); }
		if (field.getPause() == 'p')
			break;
		field.checkOver(snake.gethead());
		sf::sleep(speed-clock.getElapsedTime());
		clock.restart();
	}
}

void continueGame(Field & field, Snake & snake, float & movetime, RenderWindow & window, int & scrX, int & scrY, Time & speed)
{
	int positionX = scrX / 2 - field.getMAX() * 32 / 2;
	int positionY = scrY / 2 - field.getMAX() * 32 / 2;
	fonfield_.setPosition(positionX, positionY);
	fonfield_.setScale(0.31, 0.31);
	Clock clock;
	Text text(" ", font, 20);
	text.setColor(Color::White);
	text.setPosition(scrX / 2 - field.getMAX() * 32 / 2, scrY / 2 - field.getMAX() * 32 / 2 + field.getMAX()*32);
	while (!field.getGameOver())
	{
		if (field.checkItem())
			field.generateItem();
		if (field.checkField(snake.gethead()))
		{
			if (field.checkField2(snake.gethead()))
			{
				snake.stepField(field.getDirection());
			}
		}
		else
			snake.step(field.getDirection());
		if (field.checkChange(snake.gethead()))
		{
			snake.push(field.getItem());
			field.push(snake.gethead());
			field.addscore();
		}
		else
			field.change(snake.gettemp(), snake.gethead());

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(fonfield_);
		int max = field.getMAX();
		for (int i = 0; i < max; i++)
		{
			for (int j = 0; j < max; j++)
			{
				if (field.getField(i, j) == '*'){
					fieldk.setPosition(positionX + j * 32, positionY + i * 32);
					window.draw(fieldk);
				}
				if (field.getField(i, j) == '+'){
					apple.setPosition(positionX + j * 32, positionY + i * 32);
					window.draw(apple);
				}
				if (field.getField(i, j) == ' ') { continue; }
			}
		}
		switch (field.getDirection())
		{
		case'w':
		{
				   snakeHeadUp.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadUp);
				   break;
		}
		case's':
		{
				   snakeHeadDown.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadDown);
				   break;
		}
		case'a':
		{
				   snakeHeadLeft.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadLeft);
				   break;
		}
		case'd':
		{
				   snakeHeadRight.setPosition(positionX + 32 * snake.yCoordinates(snake.numhead() - 1), positionY + 32 * snake.xCoordinates(snake.numhead() - 1));
				   window.draw(snakeHeadRight);
				   break;
		}
		}
		for (int i = 1; i < snake.numhead() - 1; i++)
		{
			if ((snake.yCoordinates(i - 1) + 2) == (snake.yCoordinates(i + 1))) {
				snakeBodyHotizont.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyHotizont);
			}
			if ((snake.yCoordinates(i - 1) - 2) == (snake.yCoordinates(i + 1))) {
				snakeBodyHotizont.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyHotizont);
			}
			if ((snake.xCoordinates(i - 1) + 2) == (snake.xCoordinates(i + 1))) {
				snakeBodyVertically.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyVertically);
			}
			if ((snake.xCoordinates(i - 1) - 2) == (snake.xCoordinates(i + 1))) {
				snakeBodyVertically.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(snakeBodyVertically);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) - 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) - 1)))){
				TurnDownRight.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnDownRight);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) - 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) - 1)))){
				TurnUpRight.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnUpRight);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) + 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) + 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) + 1)))) {
				TurnUpLeft.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnUpLeft);
			}
			if ((((snake.xCoordinates(i)) == (snake.xCoordinates(i + 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i - 1) + 1))) ||
				(((snake.xCoordinates(i)) == (snake.xCoordinates(i - 1) - 1)) && ((snake.yCoordinates(i)) == (snake.yCoordinates(i + 1) + 1)))) {
				TurnDownLeft.setPosition(positionX + 32 * snake.yCoordinates(i), positionY + 32 * snake.xCoordinates(i));
				window.draw(TurnDownLeft);
			}
		}
		if (snake.yCoordinates(0) == (snake.yCoordinates(1) + 1)){
			snakeTailLeft.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailLeft);
		}
		if (snake.yCoordinates(0) == (snake.yCoordinates(1) - 1)){
			snakeTailRight.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailRight);
		}
		if (snake.xCoordinates(0) == (snake.xCoordinates(1) + 1)){
			snakeTailUp.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailUp);
		}
		if (snake.xCoordinates(0) == (snake.xCoordinates(1) - 1)){
			snakeTailDown.setPosition(positionX + 32 * snake.yCoordinates(0), positionY + 32 * snake.xCoordinates(0));
			window.draw(snakeTailDown);
		}

		char num[3];
		sprintf(num, "%d", field.getscore());
		char stringScore[10] {'S', 'c', 'o', 'r', 'e', ':', ' ', num[0], num[1], num[2]};
		text.setString(stringScore);
		window.draw(text);

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Right)) { field.setDirectionOb('d'); }
		else if (Keyboard::isKeyPressed(Keyboard::Up)) { field.setDirectionOb('w'); }
		else if (Keyboard::isKeyPressed(Keyboard::Left)) { field.setDirectionOb('a'); }
		else if (Keyboard::isKeyPressed(Keyboard::Down)) { field.setDirectionOb('s'); }
		else if (Keyboard::isKeyPressed(Keyboard::P)) { field.setDirectionOb('p'); }

		if (field.getPause() == 'p')
			break;
		field.checkOver(snake.gethead());
		sf::sleep(speed - clock.getElapsedTime());
		clock.restart();
	}
}