#include <weapon.h>
inherit FIST;
void create()
{
    set_name("�K����",({"iron fist","fist"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("material", "iron");
		set("long",@LONG
�o�O�@��μ��K���y�s��������C
LONG);
    }
	init_fist(10);
    	setup();
	set("value",800);
	set("volume", 6);
}

