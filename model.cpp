// model.cpp
#include "model.h"
#include "contactlistener.h"

Model::Model(QWidget *parent)
    : QWidget(parent), scene(640, 480), painter(), elapsedTimer(), windowDimensions(0., 0.)
{
    painter.begin(&scene);

    Level1 *level1 = new Level1(":/background");
	levels.append(level1);
	currentLevel = level1;

	connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
	connect(&(*currentLevel->player), &Player::onDoorContact, &(*currentLevel), &Level::onDoorCollisionState);

	connect(&(*currentLevel), &Level::generateQuestionnaire, this, [this](QString questionText, QHash<QString, bool> responses)
			{ emit generateQuestionnaire(questionText, responses); });

	connect(&(*currentLevel), &Level::displayPopUp, this, [this](bool input, QString answer)
			{ emit displayPopUp(input, answer); });

	worldTimer.start();
	elapsedTimer.start();

	connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
}

Model::~Model()
{
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

void Model::exitDialog() {
    currentLevel->exitDialog();
}

void Model::worldStep()
{

	qint64 currentTime = elapsedTimer.nsecsElapsed();
	qint64 elapsedTime = currentTime - lastFrameTime;

	if (elapsedTime >= FRAME_TIME_TARGET && currentLevel)
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

    currentLevel->renderBackground(&painter);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);

    currentLevel->render(&painter);

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
	currentLevel->player->setMoveState(state, isDown);
}
