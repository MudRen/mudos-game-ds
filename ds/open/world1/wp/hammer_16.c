#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("�j�K��",({"big hammer","hammer"}));
	set("long",@LONG
�o�⭫���C���窺�j�K��ݰ_�ӤQ����w�A���Y�������g�]���j
�O�������Ӧ��Ǥp�ʤf�C

LONG
);
	set_weight(6800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
	}
	set("value",580);
	init_hammer(16);
        setup();
}
