#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIC"���Ū��ѱM���Y��"NOR,({"bluesky helm","helm"}) );
	set("long","�o�O���Ū��ѱM���Y���C\n");
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
//		set("value",3960);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }