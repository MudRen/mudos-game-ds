#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name(HIY"��������"NOR,({"hammer"}));
	set("long","�o�O�@��ܦn��������C\n");
	set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","gold");
        }
	init_hammer(0);
        setup();
}

