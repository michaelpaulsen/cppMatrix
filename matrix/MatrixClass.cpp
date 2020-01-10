#include <iostream>
class Matrix
{
private:
	int width, height;
public:
	float** d;
	Matrix(int w, int h) {
		d = new float*[h];
		for (int t = 0; t < h; t++) {
			d[t] = new float[w];
		}
		width = w;
		height = h;
	}
	~Matrix() {
		for (int i = 0; i < this->height; ++i) {
			delete[] d[i];
		}
		delete[] d;
	}
	void set(int x, int y, float v) {
		this->d[y][x] = v;
		std::printf("%d %d: %f\n", x, y, d[y][x]);

	}
	int getWidth() {
		return this->width;
	}
	int getHeight() {
		return this->height;
	}
	int length() {
		return this->getHeight() * this->getWidth();
	}
	Matrix operator* (Matrix o) {
		try {
			Matrix c = Matrix(this->getHeight(), o.getWidth());
			if (this->getWidth() != o.getHeight()) {
				throw(1);
			}
			for(int i = 0; i < this->getHeight(); i++){
				/*y of self; y of output */
				for (int m = 0; m < this->getWidth(); m++) {
					/*x of self; y of other */
					for (int n = 0; n < o.getWidth(); n++) {
						/*x of other; x of out */
						float self = this->d[i][m];
						float other = o.d[m][n];
						std::printf("%f ", other * self);
						c.d[i][n] = other + self;
					}
				}
				std::printf("\n");
			}
			std::printf("%d", c.length());
		}
		catch (int e) {
			std::printf("error code %i ", e);
			if (e == 1) {
				std::printf("(dim error)");
			}
		}
		catch (...) {
			std::printf("uncaught exeption");
		}
	}
};