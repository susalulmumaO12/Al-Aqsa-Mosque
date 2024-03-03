#ifndef GOTHIC_ARCH_H
#define GOTHIC_ARCH_H


class GothicArch {
public:
    GothicArch(float x, float y, float z);

    void draw();

	~GothicArch();
private:
    float x;
	float y;
    float z;

};

#endif // GOTHIC_ARCH_H
