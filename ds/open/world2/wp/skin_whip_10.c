#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("�ϥ��@",({"sheep-skin whip","whip"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("material", "skin");
		set("long",@LONG
�o�O�@��H�ϥֻs�������@�C
LONG);
    }
	init_whip(10);
    	setup();
	set("value",800);
	set("volume", 6);
}

