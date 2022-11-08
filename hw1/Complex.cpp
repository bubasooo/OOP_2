//
// Created by c4lculater on 26.10.2022.
//

class Complex {
public:
    Complex(int re = 0, int im = 0) : re(re), im(im) {}
    bool operator <(const Complex& other) const {
        return re*re + im*im < other.getIm()*other.getIm() + other.getRe()*other.getRe();
    }

    bool operator >(const Complex& other) const {
        return re*re + im*im > other.getIm()*other.getIm() + other.getRe()*other.getRe();
    }

    int getRe() const {
        return re;
    }

    int getIm() const {
        return im;
    }

private:
    int re;
    int im;
};

bool predicat(const Complex& num) {
    return num.getRe() % 2 == 0;
}