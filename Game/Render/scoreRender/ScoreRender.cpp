#include "ScoreRender.h"


ScoreRender::ScoreRender(sf::Font& font)
    : font(font), score(font)
{
    score.setCharacterSize(28);
    score.setFillColor(sf::Color::White);
    score.setPosition({ 450.f, 100.f });
}
void ScoreRender::update(const MatchScore& matchScore) {
    int ctScore;
    int tScore;

    {
        std::lock_guard<std::mutex> lock(roundsMutex);
        ctScore = matchScore.ctScore;
        tScore = matchScore.tScore;
    }
    score.setString(
        "CT  " + std::to_string(ctScore) +
        " : " + std::to_string(tScore) + "  T"
    );
}

void ScoreRender::drawScore(sf::RenderWindow& window) const {
    window.draw(score);
}