#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�����M",({"cloudy blade","blade"}));
	set("long","�@�⻴�X���j�M�A��A���_�ɡA���G���q��P�Ū��j�M�٭n���C\n");
	set_weight(5000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("unit", "��");
set("volume",2);
        set("material","steel");
       set("value",2250);
		set("limit_str", 10);
	}
	init_blade(35);
	setup();
}
