#include <cmath>
#include <cassert>
#include <initializer_list>
#include <utility>
#include <cstring>

class Vec2 {
public:
    float x;
    float y;

    Vec2(); /*присваиваем x и у*/
    Vec2(float, float);

    Vec2 operator+(const Vec2&) const; /*выполняем операции над х и у*/
    Vec2 operator-(const Vec2&) const;
    Vec2 operator*(const Vec2&) const;
    Vec2 operator/(const Vec2&) const;

    bool operator==(const Vec2&) const; /* проверяем имеют ли векторы одинаковые значения*/

    bool operator>(const Vec2&) const; /*проверяем какой вектор ближе или дальше от исходного*/
    bool operator<(const Vec2&) const;
    bool operator>=(const Vec2&) const;
    bool operator<=(const Vec2&) const;

    Vec2 operator-() const; /*делаем оба значения х и у отрицательными*/

    Vec2 operator*(const float&) const; /*скалярные операции над х и у*/
    Vec2 operator/(const float&) const;

    static float DotProduct(const Vec2&, const Vec2&); /*скалярное произведение*/
    static float CrossProduct(const Vec2&, const Vec2&); /*векторное произведение*/

    static float Magnitude(const Vec2&); /*возвращает длину вектора начиная от начала координат*/

    static Vec2 Normal(const Vec2&); /*возвращает единичный вектор*/
};

Vec2::Vec2()
{
    x = 0.0;
    y = 0.0;
}

Vec2::Vec2(float sourceX, float sourceY)
{
    x = sourceX;
    y = sourceY;
}

Vec2 Vec2::operator+(const Vec2& v) const
{
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2& v) const
{
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(const Vec2& v) const
{
    return Vec2(x * v.x, y * v.y);
}

Vec2 Vec2::operator/(const Vec2& v) const
{
    return Vec2(x / v.x, y / v.y);
}

bool Vec2::operator==(const Vec2& v) const
{
    return ((x == v.x) && (y == v.y));
}

bool Vec2::operator>(const Vec2& v) const
{
    return (x * x + y * y) > (v.x * v.x + v.y * v.y);
}

bool Vec2::operator<(const Vec2& v) const
{
    return (x * x + y * y) < (v.x * v.x + v.y * v.y);
}

bool Vec2::operator>=(const Vec2& v) const
{
    return (x * x + y * y) > (v.x * v.x + v.y * v.y) ||
        (x * x + y * y) == (v.x * v.x + v.y * v.y);
}

bool Vec2::operator<=(const Vec2& v) const
{
    return (x * x + y * y) < (v.x * v.x + v.y * v.y) ||
        (x * x + y * y) == (v.x * v.x + v.y * v.y);
}
Vec2 Vec2::operator-() const
{
    return Vec2(-x, -y);
}

Vec2 Vec2::operator*(const float& scalar) const
{
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(const float& scalar) const
{
    return Vec2(x / scalar, y / scalar);
}

float Vec2::DotProduct(const Vec2& a, const Vec2& b)
{
    return ((a.x * b.x) + (a.y * b.y));
}

float Vec2::CrossProduct(const Vec2& a, const Vec2& b)
{
    return ((a.x * b.y) - (a.y * b.x));
}

float Vec2::Magnitude(const Vec2& v)
{
    return sqrt((v.x * v.x) + (v.y * v.y));
}

Vec2 Vec2::Normal(const Vec2& v)
{
    float magnitude = Magnitude(v);
    return Vec2(v.x / magnitude, v.y / magnitude);
}

class Vec3 {
public:
    float x;
    float y;
    float z;

    Vec3(); /*присваиваем x и у*/
    Vec3(float, float, float);

    Vec3 operator+(const Vec3&) const; /*выполняем операции над х и у*/
    Vec3 operator-(const Vec3&) const;
    Vec3 operator*(const Vec3&) const;
    Vec3 operator/(const Vec3&) const;

    bool operator==(const Vec3&) const; /* проверяем имеют ли векторы одинаковые значения*/

    bool operator>(const Vec3&) const; /*проверяем какой вектор ближе или дальше от исходного*/
    bool operator<(const Vec3&) const;
    bool operator>=(const Vec3&) const;
    bool operator<=(const Vec3&) const;

    Vec3 operator-() const; /*делаем оба значения х и у отрицательными*/

    Vec3 operator*(const float&) const; /*скалярные операции над х и у*/
    Vec3 operator/(const float&) const;

    static float DotProduct(const Vec3&, const Vec3&); /*скалярное произведение*/
    static float CrossProduct(const Vec3&, const Vec3&); /*векторное произведение*/

    static float Magnitude(const Vec3&); /*возвращает длину вектора начиная от начала координат*/

    static Vec3 Normal(const Vec3&); /*возвращает единичный вектор*/
};

Vec3::Vec3()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vec3::Vec3(float sourceX, float sourceY, float sourceZ)
{
    x = sourceX;
    y = sourceY;
    z = sourceZ;
}

Vec3 Vec3::operator+(const Vec3& v) const
{
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const
{
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(const Vec3& v) const
{
    return Vec3(x * v.x, y * v.y, z * v.z);
}

Vec3 Vec3::operator/(const Vec3& v) const
{
    return Vec3(x / v.x, y / v.y, z / v.z);
}

bool Vec3::operator==(const Vec3& v) const
{
    return ((x == v.x) && (y == v.y) && (z == v.z));
}

bool Vec3::operator>(const Vec3& v) const
{
    return (x * x + y * y + z * z) > (v.x * v.x + v.y * v.y + v.z * v.z);
}

bool Vec3::operator<(const Vec3& v) const
{
    return (x * x + y * y + z * z) < (v.x * v.x + v.y * v.y + v.z * v.z);
}

bool Vec3::operator>=(const Vec3& v) const
{
    return (x * x + y * y + z * z) > (v.x * v.x + v.y * v.y + v.z * v.z) ||
        (x * x + y * y + z * z) == (v.x * v.x + v.y * v.y + v.z * v.z);
}

bool Vec3::operator<=(const Vec3& v) const
{
    return (x * x + y * y + z * z) < (v.x * v.x + v.y * v.y + v.z * v.z) ||
        (x * x + y * y + z * z) == (v.x * v.x + v.y * v.y + v.z * v.z);
}
Vec3 Vec3::operator-() const
{
    return Vec3(-x, -y, -z);
}

Vec3 Vec3::operator*(const float& scalar) const
{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(const float& scalar) const
{
    return Vec3(x / scalar, y / scalar, z / scalar);
}

float Vec3::DotProduct(const Vec3& a, const Vec3& b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

float Vec3::CrossProduct(const Vec3& a, const Vec3& b)
{
    return ((a.x * b.y) - (a.y * b.x) - (a.z * b.z));
}

float Vec3::Magnitude(const Vec3& v)
{
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z*v.z));
}

Vec3 Vec3::Normal(const Vec3& v)
{
    float magnitude = Magnitude(v);
    return Vec3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}

class Vec4 {
public:
    float x;
    float y;
    float z;
    float w;

    Vec4(); /*присваиваем x и у*/
    Vec4(float, float, float, float);

    Vec4 operator+(const Vec4&) const; /*выполняем операции над х и у*/
    Vec4 operator-(const Vec4&) const;
    Vec4 operator*(const Vec4&) const;
    Vec4 operator/(const Vec4&) const;

    bool operator==(const Vec4&) const; /* проверяем имеют ли векторы одинаковые значения*/

    bool operator>(const Vec4&) const; /*проверяем какой вектор ближе или дальше от исходного*/
    bool operator<(const Vec4&) const;
    bool operator>=(const Vec4&) const;
    bool operator<=(const Vec4&) const;

    Vec4 operator-() const; /*делаем оба значения х и у отрицательными*/

    Vec4 operator*(const float&) const; /*скалярные операции над х и у*/
    Vec4 operator/(const float&) const;

    static float DotProduct(const Vec4&, const Vec4&); /*скалярное произведение*/
    static float CrossProduct(const Vec4&, const Vec4&); /*векторное произведение*/

    static float Magnitude(const Vec4&); /*возвращает длину вектора начиная от начала координат*/

    static Vec4 Normal(const Vec4&); /*возвращает единичный вектор*/
};

Vec4::Vec4()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
    w = 0.0;
}

Vec4::Vec4(float sourceX, float sourceY, float sourceZ, float sourceW)
{
    x = sourceX;
    y = sourceY;
    z = sourceZ;
    w = sourceW;
}

Vec4 Vec4::operator+(const Vec4& v) const
{
    return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator-(const Vec4& v) const
{
    return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vec4 Vec4::operator*(const Vec4& v) const
{
    return Vec4(x * v.x, y * v.y, z * v.z, w * v.w);
}

Vec4 Vec4::operator/(const Vec4& v) const
{
    return Vec4(x / v.x, y / v.y, z / v.z, w / v.w);
}

bool Vec4::operator==(const Vec4& v) const
{
    return ((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w));
}

bool Vec4::operator>(const Vec4& v) const
{
    return (x * x + y * y + z * z + w * w) > (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

bool Vec4::operator<(const Vec4& v) const
{
    return (x * x + y * y + z * z + w * w) < (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

bool Vec4::operator>=(const Vec4& v) const
{
    return (x * x + y * y + z * z + w * w) > (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w) ||
        (x * x + y * y + z * z + w * w) == (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

bool Vec4::operator<=(const Vec4& v) const
{
    return (x * x + y * y + z * z + w * w) < (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w) ||
        (x * x + y * y + z * z + w * w) == (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
Vec4 Vec4::operator-() const
{
    return Vec4(-x, -y, -z, -w);
}

Vec4 Vec4::operator*(const float& scalar) const
{
    return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vec4 Vec4::operator/(const float& scalar) const
{
    return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Vec4::DotProduct(const Vec4& a, const Vec4& b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

float Vec4::CrossProduct(const Vec4& a, const Vec4& b)
{
    return ((a.x * b.y) - (a.y * b.x) - (a.z * b.z) - (a.w * b.w));
}

float Vec4::Magnitude(const Vec4& v)
{
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

Vec4 Vec4::Normal(const Vec4& v)
{
    float magnitude = Magnitude(v);
    return Vec4(v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w / magnitude);
}





class Mat2 {
private:
	float *temp;
public:

	Mat2();
	~Mat2();
	Mat2(Mat2&& m);

	Mat2& operator=(Mat2&& m);

	Mat2(const float m); 

	template<typename... Arguments>
	Mat2(Arguments&&... args);

	Mat2(const Mat2& m);

	bool operator==(const Mat2& m) const;

	bool operator!=(const Mat2& m) const;

	Mat2 operator+(const Mat2& m);
	Mat2 operator+(const float m) const;
	Mat2& operator+=(const Mat2& m);
	Mat2& operator+=(const float m);
	Mat2 operator-(const Mat2& m);
	Mat2 operator-(const float m) const;
	Mat2& operator-=(const Mat2& m);
	Mat2& operator-=(const float m);
	Mat2 operator*(const Mat2& m) const;
	Mat2 operator*(const float m) const;
    Mat2& operator*=(const Mat2& m);
	Mat2& operator*=(const float m);
	Mat2 operator/(const float m) const;
	Mat2& operator/=(const float m);

	Vec2 operator*(const Vec2& v) const;

	float& operator[](int i);

	float const& operator[](int i) const;

	float det() const;

    Mat2 inverse() const;

    Mat2 trans() const;

    Vec2 row(int i);
    Vec2 row(int i) const;

    Vec2 column(int i);
    Vec2 column(int i) const;

};

Mat2::Mat2() {
	temp = (float*)calloc(4, sizeof(float));
};

Mat2::~Mat2(){
	free(temp);
};

Mat2::Mat2(Mat2&& m) {
	temp = (float*)calloc(4, sizeof(float));
	temp = m.temp;
	m.temp = nullptr;
};

Mat2& Mat2::operator=(Mat2&& m) {
	temp = m.temp;
	m.temp = nullptr;
	return *this;
};

Mat2::Mat2(const float m){
	temp = (float*)calloc(4, sizeof(float));
	temp[0] = static_cast<float>(m);
	temp[3] = temp[0];
}

template<typename... Arguments>
Mat2::Mat2(Arguments&&... args) {
	temp = (float*)calloc(4, sizeof(float));
	int i = 0;
	for (auto j : { args... })
		temp[i++] = static_cast<float>(j);
}

Mat2::Mat2(const Mat2& m) {
	temp = (float*)calloc(4, sizeof(float));
	std::memcpy(temp, m.temp, sizeof(float) * 4);
};

bool Mat2::operator==(const Mat2& m) const {
	return (!memcmp(temp, m.temp, sizeof(float) * 4));
};

bool Mat2::operator!=(const Mat2& m) const {
	return !(*this == m);
};

Mat2 Mat2::operator+(const Mat2& m) {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] + m.temp[i];
	return x;
};

Mat2 Mat2::operator+(const float m) const {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] + m;
	return x;
};

Mat2& Mat2::operator+=(const Mat2& m) {
	for (int i = 0; i < 4; ++i)
		temp[i] += m.temp[i];
	return *this;
};

Mat2& Mat2::operator+=(const float m) {
	for (int i = 0; i < 4; ++i)
		temp[i] += m;
	return *this;
};

Mat2 Mat2::operator-(const Mat2& m) {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] - m.temp[i];
	return m;
};

Mat2 Mat2::operator-(const float m) const {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] - m;
	return x;
};

Mat2& Mat2::operator-=(const Mat2& m) {
	for (int i = 0; i < 4; ++i)
		temp[i] -= m.temp[i];
	return *this;
};

Mat2& Mat2::operator-=(const float m) {
	for (int i = 0; i < 4; ++i)
		temp[i] -= m;
	return *this;
};

Mat2 Mat2::operator*(const Mat2& m) const {
	Mat2 x;
	x.temp[0] = (temp[0] * m.temp[0]) + (temp[1] * m.temp[2]);
	x.temp[1] = (temp[0] * m.temp[1]) + (temp[1] * m.temp[3]);
	x.temp[2] = (temp[2] * m.temp[0]) + (temp[3] * m.temp[2]);
	x.temp[3] = (temp[2] * m.temp[1]) + (temp[3] * m.temp[3]);
	return x;
};

Mat2 Mat2::operator*(const float m) const {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] * m;
	return x;
};

Mat2& Mat2::operator*=(const Mat2& m) {
	Mat2 x;
	x.temp[0] = (temp[0] * m.temp[0]) + (temp[1] * m.temp[2]);
	x.temp[1] = (temp[0] * m.temp[1]) + (temp[1] * m.temp[3]);
	x.temp[2] = (temp[2] * m.temp[0]) + (temp[3] * m.temp[2]);
	x.temp[3] = (temp[2] * m.temp[1]) + (temp[3] * m.temp[3]);
	*this = std::move(x);
	return *this;
};

Mat2& Mat2::operator*=(const float m) {
	for (int i = 0; i < 4; ++i)
		temp[i] *= m;
	return *this;
};

Mat2 Mat2::operator/(const float m) const {
	Mat2 x;
	for (int i = 0; i < 4; ++i)
		x.temp[i] = temp[i] / m;
	return x;
};

Mat2& Mat2::operator/=(const float m) {
	for (int i = 0; i < 4; ++i)
		temp[i] /= m;
	return *this;
};

Vec2 Mat2::operator*(const Vec2& v) const {
	Vec2 Vec;
	Vec.x = temp[0] * v.x + temp[1] * v.y;
	Vec.y = temp[2] * v.x + temp[3] * v.y;
	return Vec;
};

float& Mat2::operator[](int i) {
	assert(i >= 0 && i <= 3);
	return temp[i];
};

float const& Mat2::operator[](int i) const {
	assert(i >= 0 && i <= 3);
	return temp[i];
};

float Mat2::det() const {
	return (temp[0] * temp[3]) - (temp[1] * temp[2]);
};

Mat2 Mat2::inverse() const {
	Mat2 inv(*this);
	assert(this->det() != 0);
	std::swap(inv.temp[0], inv.temp[3]);
	inv.temp[1] *= -1;
	inv.temp[2] *= -1;
	for (int i = 0; i < 4; ++i)
		inv.temp[i] /= this->det();
	return inv;
};

Mat2 Mat2::trans() const {
	Mat2 t(*this);
	std::swap(t.temp[1], t.temp[2]);
	return t;
};

Vec2 Mat2::row(int i) {
    assert(i >= 0 && i <= 1);
    return Vec2(temp[i * 2], temp[i * 2 + 1]);
};

Vec2 Mat2::row(int i) const {
    assert(i >= 0 && i <= 1);
    return Vec2(temp[i * 2], temp[i * 2 + 1]);
};

Vec2 Mat2::column(int i) {
    assert(i >= 0 && i <= 1);
    return Vec2(temp[i], temp[i + 2]);
};

Vec2 Mat2::column(int i) const {
    assert(i >= 0 && i <= 1);
    return Vec2(temp[i], temp[i + 2]);
};

class Mat3 {
private:
	float* temp;
public:

	Mat3();
	~Mat3();
	Mat3(Mat3&& m);

	Mat3& operator=(Mat3&& m);

	Mat3(const float m);

	template<typename... Arguments>
	Mat3(Arguments&&... args);

	Mat3(const Mat3& m);

	bool operator==(const Mat3& m) const;

	bool operator!=(const Mat3& m) const;

	Mat3 operator+(const Mat3& m);
	Mat3 operator+(const float m) const;
	Mat3& operator+=(const Mat3& m);
	Mat3& operator+=(const float m);
	Mat3 operator-(const Mat3& m);
	Mat3 operator-(const float m) const;
	Mat3& operator-=(const Mat3& m);
	Mat3& operator-=(const float m);
	Mat3 operator*(const Mat3& m) const;
	Mat3 operator*(const float m) const;
	Mat3& operator*=(const Mat3& m);
	Mat3& operator*=(const float m);
	Mat3 operator/(const float m) const;
	Mat3& operator/=(const float m);

	Vec3 operator*(const Vec3& v) const;

	float& operator[](int i);

	float const& operator[](int i) const;

	float det() const;

	Mat3 inverse() const;

	Mat3 trans() const;

	Vec3 row(int i);
	Vec3 row(int i) const;

	Vec3 column(int i);
	Vec3 column(int i) const;

};

Mat3::Mat3() {
	temp = (float*)calloc(9, sizeof(float));
};

Mat3::~Mat3() {
	free(temp);
};

Mat3::Mat3(Mat3&& m) {
	temp = (float*)calloc(9, sizeof(float));
	temp = m.temp;
	m.temp = nullptr;
};

Mat3& Mat3::operator=(Mat3&& m) {
	temp = m.temp;
	m.temp = nullptr;
	return *this;
};

Mat3::Mat3(const float m) {
	temp = (float*)calloc(9, sizeof(float));
	temp[0] = static_cast<float>(m);
	temp[8] = temp[0];
}

template<typename... Arguments>
Mat3::Mat3(Arguments&&... args) {
	temp = (float*)calloc(9, sizeof(float));
	int i = 0;
	for (auto j : { args... })
		temp[i++] = static_cast<float>(j);
}

Mat3::Mat3(const Mat3& m) {
	temp = (float*)calloc(9, sizeof(float));
	std::memcpy(temp, m.temp, sizeof(float) * 9);
};

bool Mat3::operator==(const Mat3& m) const {
	return (!memcmp(temp, m.temp, sizeof(float) * 9));
};

bool Mat3::operator!=(const Mat3& m) const {
	return !(*this == m);
};

Mat3 Mat3::operator+(const Mat3& m) {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] + m.temp[i];
	return x;
};

Mat3 Mat3::operator+(const float m) const {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] + m;
	return x;
};

Mat3& Mat3::operator+=(const Mat3& m) {
	for (int i = 0; i < 9; ++i)
		temp[i] += m.temp[i];
	return *this;
};

Mat3& Mat3::operator+=(const float m) {
	for (int i = 0; i < 9; ++i)
		temp[i] += m;
	return *this;
};

Mat3 Mat3::operator-(const Mat3& m) {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] - m.temp[i];
	return m;
};

Mat3 Mat3::operator-(const float m) const {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] - m;
	return x;
};

Mat3& Mat3::operator-=(const Mat3& m) {
	for (int i = 0; i < 9; ++i)
		temp[i] -= m.temp[i];
	return *this;
};

Mat3& Mat3::operator-=(const float m) {
	for (int i = 0; i < 9; ++i)
		temp[i] -= m;
	return *this;
};

Mat3 Mat3::operator*(const Mat3& m) const {
	Mat3 x;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			x[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k)
					x[i * 3 + j] += m[i * 3 + k] * temp[k * 3 + j];
		}
	return x;
}

Mat3 Mat3::operator*(const float m) const {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] * m;
	return x;
};

Mat3& Mat3::operator*=(const Mat3& m) {
	Mat3 x;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			x[i * 3 + j] = 0;
				for (int k = 0; k < 3; ++k)
					x[i * 3 + j] += m[i * 3 + k] * temp[k * 3 + j];
		}
	*this = std::move(x);
	return *this;
};

Mat3& Mat3::operator*=(const float m) {
	for (int i = 0; i < 9; ++i)
		temp[i] *= m;
	return *this;
};

Mat3 Mat3::operator/(const float m) const {
	Mat3 x;
	for (int i = 0; i < 9; ++i)
		x.temp[i] = temp[i] / m;
	return x;
};

Mat3& Mat3::operator/=(const float m) {
	for (int i = 0; i < 9; ++i)
		temp[i] /= m;
	return *this;
};

Vec3 Mat3::operator*(const Vec3& v) const {
	Vec3 Vec;
	Vec.x = temp[0] * v.x + temp[1] * v.y + temp[2] * v.z;
	Vec.y = temp[3] * v.x + temp[4] * v.y + temp[5] * v.z;
	Vec.z = temp[6] * v.x + temp[7] * v.y + temp[8] * v.z;
	return Vec;
};

float& Mat3::operator[](int i) {
	assert(i >= 0 && i <= 8);
	return temp[i];
};

float const& Mat3::operator[](int i) const {
	assert(i >= 0 && i <= 8);
	return temp[i];
};

float Mat3::det() const {
	return (temp[0] * ((temp[4] * temp[8]) - (temp[5] * temp[7])) - temp[1] * ((temp[3] * temp[8]) - (temp[5] * temp[6])) + temp[2] * ((temp[3] * temp[7]) - (temp[4] * temp[6])));
};

Mat3 Mat3::inverse() const {
	assert(this->det() != 0);
	Mat3 inv(
		(temp[4] * temp[8] - temp[5] * temp[7]) / this->det(),
		-(temp[1] * temp[8] - temp[2] * temp[7]) / this->det(),
		(temp[1] * temp[5] - temp[2] * temp[4]) / this->det(),
		-(temp[3] * temp[8] - temp[5] * temp[6]) / this->det(),
		(temp[0] * temp[8] - temp[2] * temp[6]) / this->det(),
		-(temp[0] * temp[5] - temp[2] * temp[3]) / this->det(),
		(temp[3] * temp[7] - temp[4] * temp[6]) / this->det(),
		-(temp[0] * temp[7] - temp[1] * temp[6]) / this->det(),
		(temp[0] * temp[4] - temp[1] * temp[3]) / this->det()
	);
	return inv;
};

Mat3 Mat3::trans() const {
	Mat3 t(*this);
	std::swap(t.temp[1], t.temp[3]);
	std::swap(t.temp[2], t.temp[6]);
	std::swap(t.temp[5], t.temp[7]);
	return t;
};

Vec3 Mat3::row(int i) {
	assert(i >= 0 && i <= 2);
	return Vec3(temp[i * 3], temp[i * 3 + 1], temp[i * 3 + 2]);
};

Vec3 Mat3::row(int i) const {
	assert(i >= 0 && i <= 2);
	return Vec3(temp[i * 3], temp[i * 3 + 1], temp[i * 3 + 2]);
};

Vec3 Mat3::column(int i) {
	assert(i >= 0 && i <= 2);
	return Vec3(temp[i], temp[i + 3], temp[i + 6]);
};

Vec3 Mat3::column(int i) const {
	assert(i >= 0 && i <= 2);
	return Vec3(temp[i], temp[i + 3], temp[i + 6]);
};

class Mat4 {
private:
	float* temp;
public:

	Mat4();
	~Mat4();
	Mat4(Mat4&& m);

	Mat4& operator=(Mat4&& m);

	Mat4(const float m);

	template<typename... Arguments>
	Mat4(std::initializer_list<float> args);

	Mat4(const Mat4& m);

	bool operator==(const Mat4& m) const;

	bool operator!=(const Mat4& m) const;

	Mat4 operator+(const Mat4& m);
	Mat4 operator+(const float m) const;
	Mat4& operator+=(const Mat4& m);
	Mat4& operator+=(const float m);
	Mat4 operator-(const Mat4& m);
	Mat4 operator-(const float m) const;
	Mat4& operator-=(const Mat4& m);
	Mat4& operator-=(const float m);
	Mat4 operator*(const Mat4& m) const;
	Mat4 operator*(const float m) const;
	Mat4& operator*=(const Mat4& m);
	Mat4& operator*=(const float m);
	Mat4 operator/(const float m) const;
	Mat4& operator/=(const float m);

	Vec4 operator*(const Vec4& v) const;

	float& operator[](int i);

	float const& operator[](int i) const;

	float det() const;

	Mat4 inverse() const;

	Mat4 trans() const;

	Vec4 row(int i);
	Vec4 row(int i) const;

	Vec4 column(int i);
	Vec4 column(int i) const;

	Mat4(const Vec4& v1, const Vec4& v2, const Vec4& v3, const Vec4& v4);

	Mat4 translate(const Vec3& vec);

	Mat4 scale(const Vec3& vec);

	Mat4 rotate(Vec3& vec, float ang);
};

Mat4::Mat4() {
	temp = (float*)calloc(16, sizeof(float));
};

Mat4::~Mat4() {
	free(temp);
};

Mat4::Mat4(Mat4&& m) {
	temp = (float*)calloc(16, sizeof(float));
	temp = m.temp;
	m.temp = nullptr;
};

Mat4& Mat4::operator=(Mat4&& m) {
	temp = m.temp;
	m.temp = nullptr;
	return *this;
};

Mat4::Mat4(const float m) {
	temp = (float*)calloc(16, sizeof(float));
	temp[0] = static_cast<float>(m);
	temp[15] = temp[0];
}

template<typename... Arguments>
Mat4::Mat4(std::initializer_list<float> args) {
	temp = (float*)calloc(16, sizeof(float));
	assert((args.size() <= 16) && "out of range");
	int i = 0;
	for (auto j : args)
		temp[i++] = j;
}

Mat4::Mat4(const Mat4& m) {
	temp = (float*)calloc(16, sizeof(float));
	std::memcpy(temp, m.temp, sizeof(float) * 16);
};

bool Mat4::operator==(const Mat4& m) const {
	return (!memcmp(temp, m.temp, sizeof(float) * 16));
};

bool Mat4::operator!=(const Mat4& m) const {
	return !(*this == m);
};

Mat4 Mat4::operator+(const Mat4& m) {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] + m.temp[i];
	return x;
};

Mat4 Mat4::operator+(const float m) const {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] + m;
	return x;
};

Mat4& Mat4::operator+=(const Mat4& m) {
	for (int i = 0; i < 16; ++i)
		temp[i] += m.temp[i];
	return *this;
};

Mat4& Mat4::operator+=(const float m) {
	for (int i = 0; i < 16; ++i)
		temp[i] += m;
	return *this;
};

Mat4 Mat4::operator-(const Mat4& m) {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] - m.temp[i];
	return m;
};

Mat4 Mat4::operator-(const float m) const {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] - m;
	return x;
};

Mat4& Mat4::operator-=(const Mat4& m) {
	for (int i = 0; i < 16; ++i)
		temp[i] -= m.temp[i];
	return *this;
};

Mat4& Mat4::operator-=(const float m) {
	for (int i = 0; i < 16; ++i)
		temp[i] -= m;
	return *this;
};

Mat4 Mat4::operator*(const Mat4& m) const {
	Mat4 x;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			x[i * 4 + j] = 0;
			for (int k = 0; k < 4; k++)
				x[i * 4 + j] += m[i * 4 + k] * temp[k * 4 + j];
		}
	}
	return x;
}

Mat4 Mat4::operator*(const float m) const {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] * m;
	return x;
};

Mat4& Mat4::operator*=(const Mat4& m) {
	Mat4 x;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			x[i * 4 + j] = 0;
			for (int k = 0; k < 4; k++)
				x[i * 4 + j] += m[i * 4 + k] * temp[k * 4 + j];
		}
	}
	*this = std::move(x);
	return *this;
};

Mat4& Mat4::operator*=(const float m) {
	for (int i = 0; i < 16; ++i)
		temp[i] *= m;
	return *this;
};

Mat4 Mat4::operator/(const float m) const {
	Mat4 x;
	for (int i = 0; i < 16; ++i)
		x.temp[i] = temp[i] / m;
	return x;
};

Mat4& Mat4::operator/=(const float m) {
	for (int i = 0; i < 16; ++i)
		temp[i] /= m;
	return *this;
};

Vec4 Mat4::operator*(const Vec4& v) const {
	Vec4 Vec;
	Vec.x = temp[0] * v.x + temp[1] * v.y + temp[2] * v.z + temp[3] * v.w;
	Vec.y = temp[4] * v.x + temp[5] * v.y + temp[6] * v.z + temp[7] * v.w;
	Vec.z = temp[8] * v.x + temp[9] * v.y + temp[10] * v.z + temp[11] * v.w;
	Vec.w = temp[12] * v.x + temp[13] * v.y + temp[14] * v.z + temp[15] * v.w;
	return Vec;
};

float& Mat4::operator[](int i) {
	assert(i >= 0 && i <= 15);
	return temp[i];
};

float const& Mat4::operator[](int i) const {
	assert(i >= 0 && i <= 15);
	return temp[i];
};

float Mat4::det() const {
	return temp[0] * (temp[5] * temp[10] * temp[15] - temp[5] * temp[11] * temp[14] - temp[9] * temp[6] * temp[15] + temp[9] * temp[7] * temp[14] + temp[13] * temp[6] * temp[11] - temp[13] * temp[7] * temp[10]) 
		+ temp[1] * (-temp[4] * temp[10] * temp[15] + temp[4] * temp[11] * temp[14] + temp[8] * temp[6] * temp[15] - temp[8] * temp[7] * temp[14] - temp[12] * temp[6] * temp[11] + temp[12] * temp[7] * temp[10])
		+ temp[2] * (temp[4] * temp[9] * temp[15] - temp[4] * temp[11] * temp[13] - temp[8] * temp[5] * temp[15] + temp[8] * temp[7] * temp[13] + temp[12] * temp[5] * temp[11] - temp[12] * temp[7] * temp[9])
		+ temp[3] * (-temp[4] * temp[9] * temp[14] + temp[4] * temp[10] * temp[13] + temp[8] * temp[5] * temp[14] - temp[8] * temp[6] * temp[13] - temp[12] * temp[5] * temp[10] + temp[12] * temp[6] * temp[9]);
}

Mat4 Mat4::inverse() const {
	float det = this->det();
	assert(det != 0);
	Mat4 inv{
		(temp[5] * temp[10] * temp[15] - temp[5] * temp[11] * temp[14] - temp[9] * temp[6] * temp[15] + temp[9] * temp[7] * temp[14] + temp[13] * temp[6] * temp[11] - temp[13] * temp[7] * temp[10]) / det,
		(-temp[1] * temp[10] * temp[15] + temp[1] * temp[11] * temp[14] + temp[9] * temp[2] * temp[15] - temp[9] * temp[3] * temp[14] - temp[13] * temp[2] * temp[11] + temp[13] * temp[3] * temp[10]) / det,
		(temp[1] * temp[6] * temp[15] - temp[1] * temp[7] * temp[14] - temp[5] * temp[2] * temp[15] + temp[5] * temp[3] * temp[14] + temp[13] * temp[2] * temp[7] - temp[13] * temp[3] * temp[6]) / det,
		(-temp[1] * temp[6] * temp[11] + temp[1] * temp[7] * temp[10] + temp[5] * temp[2] * temp[11] - temp[5] * temp[3] * temp[10] - temp[9] * temp[2] * temp[7] + temp[9] * temp[3] * temp[6]) / det,
		(-temp[4] * temp[10] * temp[15] + temp[4] * temp[11] * temp[14] + temp[8] * temp[6] * temp[15] - temp[8] * temp[7] * temp[14] - temp[12] * temp[6] * temp[11] + temp[12] * temp[7] * temp[10]) / det,
		(temp[0] * temp[10] * temp[15] - temp[0] * temp[11] * temp[14] - temp[8] * temp[2] * temp[15] + temp[8] * temp[3] * temp[14] + temp[12] * temp[2] * temp[11] - temp[12] * temp[3] * temp[10]) / det,
		(-temp[0] * temp[6] * temp[15] + temp[0] * temp[7] * temp[14] + temp[4] * temp[2] * temp[15] - temp[4] * temp[3] * temp[14] - temp[12] * temp[2] * temp[7] + temp[12] * temp[3] * temp[6]) / det,
		(temp[0] * temp[6] * temp[11] - temp[0] * temp[7] * temp[10] - temp[4] * temp[2] * temp[11] + temp[4] * temp[3] * temp[10] + temp[8] * temp[2] * temp[7] - temp[8] * temp[3] * temp[6]) / det,
		(temp[4] * temp[9] * temp[15] - temp[4] * temp[11] * temp[13] - temp[8] * temp[5] * temp[15] + temp[8] * temp[7] * temp[13] + temp[12] * temp[5] * temp[11] - temp[12] * temp[7] * temp[9]) / det,
		(-temp[0] * temp[9] * temp[15] + temp[0] * temp[11] * temp[13] + temp[8] * temp[1] * temp[15] - temp[8] * temp[3] * temp[13] - temp[12] * temp[1] * temp[11] + temp[12] * temp[3] * temp[9]) / det,
		(temp[0] * temp[5] * temp[15] - temp[0] * temp[7] * temp[13] - temp[4] * temp[1] * temp[15] + temp[4] * temp[3] * temp[13] + temp[12] * temp[1] * temp[7] - temp[12] * temp[3] * temp[5]) / det,
		(-temp[0] * temp[5] * temp[11] + temp[0] * temp[7] * temp[9] + temp[4] * temp[1] * temp[11] - temp[4] * temp[3] * temp[9] - temp[8] * temp[1] * temp[7] + temp[8] * temp[3] * temp[5]) / det,
		(-temp[4] * temp[9] * temp[14] + temp[4] * temp[10] * temp[13] + temp[8] * temp[5] * temp[14] - temp[8] * temp[6] * temp[13] - temp[12] * temp[5] * temp[10] + temp[12] * temp[6] * temp[9]) / det,
		(temp[0] * temp[9] * temp[14] - temp[0] * temp[10] * temp[13] - temp[8] * temp[1] * temp[14] + temp[8] * temp[2] * temp[13] + temp[12] * temp[1] * temp[10] - temp[12] * temp[2] * temp[9]) / det,
		(-temp[0] * temp[5] * temp[14] + temp[0] * temp[6] * temp[13] + temp[4] * temp[1] * temp[14] - temp[4] * temp[2] * temp[13] - temp[12] * temp[1] * temp[6] + temp[12] * temp[2] * temp[5]) / det,
		(temp[0] * temp[5] * temp[10] - temp[0] * temp[6] * temp[9] - temp[4] * temp[1] * temp[10] + temp[4] * temp[2] * temp[9] + temp[8] * temp[1] * temp[6] - temp[8] * temp[2] * temp[5]) / det
	};
	return inv;
};

Mat4 Mat4::trans() const {
	Mat4 t(*this);
	for (int i = 0; i < 4; ++i)
		for (int j = i + 1; j < 4; ++j)
			std::swap(t.temp[i * 4 + j], t.temp[j * 4 + i]);
	return t;
};

Vec4 Mat4::row(int i) {
	assert(i >= 0 && i <= 3);
	return Vec4(temp[i * 4], temp[i * 4 + 1], temp[i * 4 + 2], temp[i * 4 + 3]);
};

Vec4 Mat4::row(int i) const {
	assert(i >= 0 && i <= 3);
	return Vec4(temp[i * 4], temp[i * 4 + 1], temp[i * 4 + 2], temp[i * 4 + 3]);
};

Vec4 Mat4::column(int i) {
	assert(i >= 0 && i <= 3);
	return Vec4(temp[i], temp[i + 4], temp[i + 8], temp[i + 12]);
};

Vec4 Mat4::column(int i) const {
	assert(i >= 0 && i <= 3);
	return Vec4(temp[i], temp[i + 4], temp[i + 8], temp[i + 12]);
};

Mat4::Mat4(const Vec4& v1, const Vec4& v2, const Vec4& v3, const Vec4& v4) {
	temp = (float*)calloc(16, sizeof(float));
	temp[0] = v1.x, temp[1] = v1.y, temp[2] = v1.z, temp[3] = v1.w;
	temp[4] = v2.x, temp[5] = v2.y, temp[6] = v2.z, temp[7] = v2.w;
	temp[8] = v3.x, temp[9] = v3.y, temp[10] = v3.z, temp[11] = v3.w;
	temp[12] = v4.x, temp[13] = v4.y, temp[14] = v4.z, temp[15] = v4.w;
}

Mat4 Mat4::translate(const Vec3& vec) {
	Mat4 x(*this);
	x[3] = vec.x;
	x[7] = vec.y;
	x[11] = vec.z;
	return x;
}

Mat4 Mat4::scale(const Vec3& vec) {
	Mat4 x(*this);
	x[0] = vec.x;
	x[5] = vec.y;
	x[10] = vec.z;
	return x;
}

Mat4 Mat4::rotate(Vec3& vec, float ang) {
	float const cos_a = cos(ang);
	float const sin_a = sin(ang);

	Vec3 a = vec.Normal(vec);
	Vec3 temp(a * (1.f - cos_a));

	Mat4 rotate;
	rotate[0] = cos_a + temp.x * a.x;
	rotate[1] = temp.x * a.y + sin_a * a.z;
	rotate[2] = temp.x * a.z - sin_a * a.y;

	rotate[4] = temp.y * a.x - sin_a * a.z;
	rotate[5] = cos_a + temp.y * a.y;
	rotate[6] = temp.y * a.z + sin_a * a.x;

	rotate[8] = temp.z * a.x + sin_a * a.y;
	rotate[9] = temp.z * a.y - sin_a * a.x;
	rotate[10] = cos_a + temp.z * a.z;

	Vec4 temp1 = (row(0) * rotate[0]) + (row(1) * rotate[1]) + (row(2) * rotate[2]);
	Vec4 temp2 = (row(0) * rotate[4]) + (row(1) * rotate[5]) + (row(2) * rotate[6]);
	Vec4 temp3 = (row(0) * rotate[8]) + (row(1) * rotate[9]) + (row(2) * rotate[10]);
	return Mat4(temp1, temp2, temp3, row(3));
}