#include <weapon.h>
inherit FIST;
void create()
{
    set_name("��s����",({"wood fist","fist"}));
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("material", "wood");
		set("long",@LONG
�o�O�@��Τ��Y�s��������C
LONG);
    }
	init_fist(5);
    	setup();
	set("value",300);
	set("volume", 4);
}

