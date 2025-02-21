/*========================================================================
** Copyright (c) 2025 TheSorceDev
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any damages
** arising from the use of this software.
**
** Permission is granted to anyone to use this software for any purpose,
** including commercial applications, and to alter it and redistribute it
** freely, subject to the following restrictions:
**
** 1. The origin of this software must not be misrepresented; you must not
**    claim that you wrote the original software. If you use this software
**    in a product, an acknowledgment in the product documentation would
**    be appreciated but is not required.
**
** 2. Altered source versions must be plainly marked as such, and must not
**    be misrepresented as being the original software.
**
** 3. This notice may not be removed or altered from any source
**    distribution.
**
========================================================================*/

#include <RC/rendercore.h>
#include <stdexcept>
#include <stdexcept>
#include <iostream> 

objectVec::objectVec() {
	size = 0;
	capacity = 2;
	data = new object[capacity];
}

objectVec::~objectVec() {
	delete[] data;
}

void objectVec::resize() {
	capacity *= 2;
	object* newData = new object[capacity];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void objectVec::push_back(const object& obj) {
	if (size == capacity) {
		resize();
	}
	data[size] = obj;
	size++;
}

void objectVec::pop_back() {
	if (size > 0) {
		size--;
	}
}

object& objectVec::at(int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	throw std::out_of_range("Index out of bounds");
}

int objectVec::getSize() const {
	return size;
}

int objectVec::getCapacity() const {
	return capacity;
}

RenderCore::RenderCore() {
}

RenderCore::~RenderCore() {
}

void RenderCore::init() {

}

void RenderCore::createWindow() {

}

void RenderCore::run() {

}

scene* RenderCore::createScene(const char* vertexShader,
	const char* fragmentShader) {
	return new scene();
}

void RenderCore::setActiveScene(scene* scene) {
}

object* scene::createObject(const char* modelPath,
	const char* texturePath,
	core::vec3* position = new core::vec3{0, 0, 0},
	core::vec3* rotation = new core::vec3{ 0, 0, 0 },
	core::vec3* scale = new core::vec3{ 1, 1, 1 }) {
	return new object();
}

scene::scene() {
	objectVec objects;
}

scene::~scene() {

}

object::object() {

}

object::~object() {
	
}