#include <star.hpp>

Star::Star(Vector3 position, float mass, float radius, float semiMajorAxis, int recursionLevel, Color colour) : starMesh(recursionLevel, colour){
    this->mass = mass;
    this->position = position;
    this->radius = radius;
    this->semiMajorAxis = semiMajorAxis;
    this->trueAnomaly = 0.f;
    this->theta = 0.f;
    this->phi = 0.f;

    this->colour = colour;
}

Star::~Star() {
}

/*!
    Draws the star to the screen.
    @param window: Reference to the window.
*/
void Star::Draw(Vector2 originPosition) {
    starMesh.Draw(Vector3{position.x + originPosition.x, position.y + originPosition.y, 0.f}, radius);
}

/*!
    Updates the position of the star and updates the star mesh based on the current theta and phi values.

    @param newPositon The new position of the star.

    @throws None

    @returns void

    @see StarMesh::Update
 */
void Star::Update(Vector3 newPositon) {
    position = newPositon;
    starMesh.Update(theta, phi);
}

void Star::RotateAroundXAxis(float deltaTheta) {
    theta += deltaTheta;
}

void Star::RotateAroundYAxis(float deltaPhi) {
    phi += deltaPhi;
}