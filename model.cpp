// model.cpp
#include "model.h"
#include "contactlistener.h"
#include "level1.h"
#include "level2.h"

Model::Model(QWidget *parent)
    : QWidget(parent), scene(640, 480), painter(), elapsedTimer(), windowDimensions(0., 0.)
{
    painter.begin(&scene);

    Level1 *level1 = new Level1(":/level1");
	levels.append(level1);
    setupLevel(level1);

    Level2 *level2 = new Level2(":/level2");
    levels.append(level2);
    setupLevel(level2);

    currentLevel = level1;

	connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);

	worldTimer.start();
	elapsedTimer.start();

	connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);

    //emit showInitialContextDialogue();
}

Model::~Model()
{
}

void Model::setupLevel(Level *level) {
    connect(&(*level), &Level::generateQuestionnaire, this, [this](QString questionText, QHash<QString, bool> responses)
            { emit generateQuestionnaire(questionText, responses); });

    connect(&(*level), &Level::displayPopUp, this, [this](bool input, QString answer)
            { emit displayPopUp(input, answer); });
}

void Model::updateDimensions(int width, int height) {
    painter.end();
    windowDimensions = b2Vec2(width, height);
    scene = QPixmap(width, height);
    painter.begin(&scene);
}

void Model::isInputCorrect(QString response)
{
	currentLevel->isInputCorrect(response);
}

void Model::getCurrentContext(){
    emit sendCurrentContext(currentLevel->context);
}

void Model::exitDialog() {
    // go to next level
    currentLevel->exitDialog();

    currentLevelIndex++;

    if (currentLevelIndex >= levels.size()) {
        qDebug() << "finished all the levels!";
        currentLevel = nullptr;
        return;
    }

    currentLevel = levels.at(currentLevelIndex);
    emit showContextDialogue();
    emit unlockLevel(currentLevelIndex);
}

void Model::worldStep()
{

	qint64 currentTime = elapsedTimer.nsecsElapsed();
	qint64 elapsedTime = currentTime - lastFrameTime;

    if (elapsedTime >= FRAME_TIME_TARGET && currentLevel != nullptr)
	{
		lastFrameTime = currentTime;
		currentLevel->step();

		// qreal frameRate = 1e9 / static_cast<qreal>(elapsedTime);
		// int roundedFrameRate = qRound(frameRate);
		// qDebug() << "Frame Rate:" << roundedFrameRate << "FPS";
	}

	renderScene();
}

void Model::renderScene()
{
	scene.fill(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);

    if (currentLevel != nullptr) {
        currentLevel->renderBackground(&painter);
        currentLevel->render(&painter);
    }

	// fix scale
    float max = (float)qMin(scene.width(), scene.height());
    float ratio = max / 600.;
    QTransform transform;
    transform.scale(1.0 * ratio, -1.0 * ratio);
    painter.setTransform(transform);

	emit renderSceneOnView(scene);
}

void Model::onPlayerMoveState(Player::Movement state, bool isDown)
{
    if (currentLevel != nullptr)
        currentLevel->player->setMoveState(state, isDown);
}

void Model::onLevelSelected(int lvl)
{
    currentLevelIndex = lvl - 1;
    currentLevel = levels.at(currentLevelIndex);
    emit showContextDialogue();
}
