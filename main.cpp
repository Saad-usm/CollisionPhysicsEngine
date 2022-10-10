// Language: cpp
// Path: main.cpp
#include <iostream>

using namespace std;

// augment particles with position

// a particle class with weight and velocity
class Particle {
private:
  double weight;
  double velocity;
  double position;
  double size;
public:
  Particle(double weight, double velocity, double position, double size) {
    this->weight = weight;
    this->velocity = velocity;
    this->position = position;
    this->size = size;

  }
  double getWeight() {
    return weight;
  }
  double getVelocity() {
    return velocity;
  }

  double getPosition() {
    return position;
  }

  double getSize() {
    return size;
  } 

  void setWeight(double weight) {
    this->weight = weight;
  }

  void setVelocity(double velocity) {
      this->velocity = velocity;
  }

  void setPosition(double position) {
      this->position = position;
  }

};

// class that holds multiple particles
class ParticleSystem {
public:

  Particle** particles;
  int numParticles;
  ParticleSystem(int numParticles) {
    this->numParticles = numParticles;
     particles = new Particle*[100];
    for (int i = 0; i < 100; i++) {
        particles[i] = new Particle(1, 2, 5, 1);
    }
  }
  ~ParticleSystem() {
       for (int i = 0; i < 100; i++) {
        delete particles[i];
    }
    delete[] particles;
  }

  // update the particles position with 1/10 of the velocity
  void update() {
    for (int i = 0; i < 100; i++) {
        particles[i]->setPosition(particles[i]->getPosition() + particles[i]->getVelocity() * 0.1);
    }
  }
};


// create particles in main function, update them and print their position
int main() {
  ParticleSystem* ps = new ParticleSystem(100);
  cout << ps->particles[0]->getPosition() << endl;
  ps->update();
  cout << ps->particles[0]->getPosition() << endl;
  delete ps;
  return 0;
}