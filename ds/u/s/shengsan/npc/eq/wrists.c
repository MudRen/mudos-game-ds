#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIC"���Ū��ѱM���@�u"NOR,({"bluesky wrists","wrists"}) );
	set("long","�o�O���Ū��ѱM���@�u�C\n");
	set_weight(2800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "steel");
//		set("value",1800);
		set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }
