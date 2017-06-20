#include "body.h"

Body::Body(const char * modelPath, const BodyProperties & props) {
	model = new Model(modelPath);
	p = props;
}

Body::~Body() {
	delete model;
}

void Body::SetScale(float scl) {
	scale = scl;
}

void Body::Evolve(float timeScale) {
	p.vel += p.accel * (1.0f / 60.0f) * timeScale;
	p.pos += p.vel * (1.0f / 60.0f) * timeScale;
}

void Body::Draw(Shader* shader) {
	transform = glm::mat4();
	transform = glm::translate(transform, glm::vec3(p.pos.x * scale, 0, -p.pos.y * scale)) * glm::scale(transform, glm::vec3(p.rad * scale));
	shader->uMatrix4("model", transform);

	model->Draw(shader);
}