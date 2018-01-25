#include "Game.h"

bool updatable = false;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	point[0] = Vector(-1.0f, 1.0f, -5.0f);//front left top corner
	point[1] = Vector(-1.0f, -1.0f, -5.0f);//front left bottom corner
	point[2] = Vector(1.0f, -1.0f, -5.0f);//front right bottom corner
	point[3] = Vector(1.0f, 1.0f, -5.0f);//front right top corner
	point[4] = Vector(-1.0f, 1.0, -15.0f);//back left top corner
	point[5] = Vector(-1.0f, -1.0f, -15.0f);//back left bottom corner
	point[6] = Vector(1.0f,-1.0f, -15.0f);//back right bottom corner
	point[7] = Vector(1.0f, 1.0f, -15.0f);//back right top corner
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(point[3].getX(), point[3].getY(), point[3].getZ());
		glVertex3f(point[0].getX(), point[0].getY(), point[0].getZ());
		glVertex3f(point[1].getX(), point[1].getY(), point[1].getZ());
		glVertex3f(point[2].getX(), point[2].getY(), point[2].getZ());

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(point[7].getX(), point[7].getY(), point[7].getZ());
		glVertex3f(point[4].getX(), point[4].getY(), point[4].getZ());
		glVertex3f(point[5].getX(), point[5].getY(), point[5].getZ());
		glVertex3f(point[6].getX(), point[6].getY(), point[6].getZ());

		//right face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(point[3].getX(), point[3].getY(), point[3].getZ());
		glVertex3f(point[7].getX(), point[7].getY(), point[7].getZ());
		glVertex3f(point[6].getX(), point[6].getY(), point[6].getZ());
		glVertex3f(point[2].getX(), point[2].getY(), point[2].getZ());

		//left face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(point[0].getX(), point[0].getY(), point[0].getZ());
		glVertex3f(point[4].getX(), point[4].getY(), point[4].getZ());
		glVertex3f(point[5].getX(), point[5].getY(), point[5].getZ());
		glVertex3f(point[1].getX(), point[1].getY(), point[1].getZ());
		
		//top face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(point[7].getX(), point[7].getY(), point[7].getZ());
		glVertex3f(point[4].getX(), point[4].getY(), point[4].getZ());
		glVertex3f(point[0].getX(), point[0].getY(), point[0].getZ());
		glVertex3f(point[3].getX(), point[3].getY(), point[3].getZ());

		//bottom face
		glColor3f(0.0f, 0.4f, 0.8f);
		glVertex3f(point[6].getX(), point[6].getY(), point[6].getZ());
		glVertex3f(point[5].getX(), point[5].getY(), point[5].getZ());
		glVertex3f(point[1].getX(), point[1].getY(), point[1].getZ());
		glVertex3f(point[2].getX(), point[2].getY(), point[2].getZ());

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	
	Matrix3 matrix;
	initialize();
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		for (index = 0; index < 8; index++)
		{
			cout << "rotating" << endl;
			point[index] = matrix.Rotation(1) * point[index];
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		for (index = 0; index < 8; index++)
		{
			point[index] = matrix.Rotation(-1) * point[index];
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		for (index = 0; index < 8; index++)
		{
			
			point[index] = matrix.Scale(101,101) * point[index];
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		for (index = 0; index < 8; index++)
		{
			point[index] = matrix.Scale(99,99) * point[index];
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::T))
	{
		for (index = 0; index < 8; index++)
		{

			point[index] = matrix.Translate(1, 1) * point[index];
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		for (index = 0; index < 8; index++)
		{
			point[index] = matrix.Translate(-1, -1) * point[index];
		}
	}
	/*
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}
	
	if (updatable)
	{
		
		rotationAngle += 0.05f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}*/
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis
	glCallList(1);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

