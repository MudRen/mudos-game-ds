#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("���@",({"bamboo whip","whip"}));
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "��");
		set("material", "wood");
		set("long",@LONG
�o�O�@��Φˤl�d�������@�C
LONG);
    }
	init_whip(5);
    	setup();
	set("value",300);
	set("volume", 6);
}

