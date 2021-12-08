#include "cipher/additive.h"
#include "cipher/multiplicative.h"

#include <cipher/key_mgr.h>
#include <iostream>

int main()
{
	/* keys */
	additive ad;
	multiplicative mp;
	affine af;
	autokey ak;
	playfair pf;
	vigenere vr;
	transposition tp;

	/* key manager */
	key_mgr km;
	km.add_key(ad);
	km.add_key(mp);
	km.add_key(af);
	km.add_key(ak);
	km.add_key(pf);
	km.add_key(vr);
	km.add_key(tp);

	km.print();

	return 0;
}