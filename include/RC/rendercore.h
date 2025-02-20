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

#ifndef RC_RENDERCORE_H
#define RC_RENDERCORE_H

#include <Windows.h>

namespace core {
    struct vec3 {
        float x, y, z;

        vec3(float x, float y, float z) : x(x), y(y), z(z) {}

        vec3 operator+(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }

        vec3 operator-(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }

        vec3 operator*(const vec3& v) const { return vec3(x * v.x, y * v.y, z * v.z); }

        vec3 operator/(const vec3& v) const { return vec3(x / v.x, y / v.y, z / v.z); }

        vec3& operator+=(const vec3& v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        vec3& operator-=(const vec3& v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        vec3& operator*=(const vec3& v) {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return *this;
        }

        vec3& operator/=(const vec3& v) {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            return *this;
        }

        vec3 operator*(float s) const { return vec3(x * s, y * s, z * s); }

        vec3 operator/(float s) const { return vec3(x / s, y / s, z / s); }

        vec3& operator*=(float s) {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }

        vec3& operator/=(float s) {
            x /= s;
            y /= s;
            z /= s;
            return *this;
        }

        float length() const { return std::sqrt(x * x + y * y + z * z); }

        vec3 normalize() const {
            float len = length();
            if (len != 0) {
                return *this / len;
            }
            return *this;
        }

        float dot(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }

        vec3 cross(const vec3& v) const {
            return vec3(
                y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x
            );
        }

        static vec3 zero() { return vec3(0, 0, 0); }

        static vec3 unit_x() { return vec3(1, 0, 0); }

        static vec3 unit_y() { return vec3(0, 1, 0); }

        static vec3 unit_z() { return vec3(0, 0, 1); }
    };

    struct vertex {
        vec3 position;
        vec3 normal;
        vec3 texcoord;

        vertex() : position(vec3::zero()), normal(vec3::zero()), texcoord(vec3::zero()) {}
        vertex(const vec3& pos, const vec3& norm, const vec3& tex) : position(pos), normal(norm), texcoord(tex) {}

        bool operator==(const vertex& v) const {
            return position == v.position && normal == v.normal && texcoord == v.texcoord;
        }

        bool operator!=(const vertex& v) const {
            return !(*this == v);
        }
    };
}

class dVec {
private:
    int* data;
    int capacity;
    int size;

    void resize();

public:
    dVec();
    ~dVec();

    void push_back(int value);
    void pop_back();

    int at(int index);
    int getSize() const;
    int getCapacity() const;

    void display() const;
};


class object
{
public:
    object();
    ~object();

private:
	core::vec3 position;
	core::vec3 rotation;
	core::vec3 scale;
};

class scene {
public:
    scene();
    ~scene();

	object* createObject(const char* modelPath, 
        const char* texturePath, 
        core::vec3 position,
        core::vec3 rotation,
        core::vec3 scale);

private:

};

class RenderCore {
public:
    RenderCore();
    ~RenderCore();

	void init();
	void createWindow();
	void run();

	scene* createScene(const char* vertexShader, 
        const char* fragmentShader);

    void setActiveScene(scene* scene);

private:

};

#endif