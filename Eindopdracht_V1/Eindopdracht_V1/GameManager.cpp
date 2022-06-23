
#include "GameManager.h"

GameManager::GameManager() {

    if(!font.loadFromFile("Calibri Regular.ttf")) {
        //error
    }

	score = 10;

	scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(Color::Green);
    scoreText.setString(to_string(score));
    scoreText.setPosition(Vector2f(10,10));
    scoreText.setStyle(Text::Bold);

}

GameManager::~GameManager() {
    delete(player);
    for(int i = 0; i < enemyAmount; i++) {
        delete(cars[i]);
    }
}

void GameManager::Update(Time dt) {

    scoreText.setString(to_string(score));

    player->Update(dt);

    for(int i = 0; i < enemyAmount; i++) {
        cars[i]->Update(dt);

        if(cars[i]->body->CheckCollision(player->GetPosition().x,player->GetPosition().y,player->GetSize().x,player->GetSize().y) != 'x') {
            score += 1;
            cars[i]->ResetPosition();
        }

        if(cars[i]->body->CheckCollision(0,windowHeight + 60,windowWidth,10) == 't') {
            score -= 1;
            cars[i]->ResetPosition();
        }

        cars[i]->speedMultiplier = score * 35;

    }

    if(Keyboard::isKeyPressed(Keyboard::Left)) {
        player->MoveLeft();
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right)) {
        player->MoveRight();
    }

}

void GameManager::Draw(RenderWindow& window) {
    player->Draw(window);
    for(int i = 0; i < enemyAmount; i++) {
        cars[i]->Draw(window);
    }
    window.draw(scoreText);
}
