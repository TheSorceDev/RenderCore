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

#include "RC/rendercore.h"
#include <stdexcept>
#include <iostream> 

dVec::dVec() {
	size = 0;
	capacity = 2;
	data = new int[capacity];
}

dVec::~dVec() {
	delete[] data;
}

void dVec::resize() {
	capacity *= 2;
	int* newData = new int[capacity];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void dVec::push_back(int value) {
	if (size == capacity) {
		resize();
	}
	data[size] = value;
	size++;
}

void dVec::pop_back() {
	if (size > 0) {
		size--;
	}
}

int dVec::at(int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	throw std::out_of_range("Index out of bounds");
}

int dVec::getSize() const {
	return size;
}

int dVec::getCapacity() const {
	return capacity;
}

void dVec::display() const {
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
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
	core::vec3 position,
	core::vec3 rotation,
	core::vec3 scale) {
	return new object();
}

scene::scene() {

}

scene::~scene() {

}

object::object() {

}

object::~object() {
	
}