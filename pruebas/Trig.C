#include <iostream>

int
main(void) {

  int angle = 0;
  int radian = 180;
  double ttable[46];

  asm {
	mov	esi, 0
	mov	cx, 46
	finit
more:	fldpi
	fild	radian
	fdiv
	fild	angle
	fmul
	fptan
	fdiv
	fstp	ttable[esi]
	inc	angle
	add	esi, 0x08d
	loop	more
	fwait
  }
	
  cout << "Angle Tangent\n\n";
  for (int i = 0; i < 46; i++) {
    cout << i << "\t" << ttable[i] << "\n";
  }

}
