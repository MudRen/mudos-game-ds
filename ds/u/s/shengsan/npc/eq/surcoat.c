#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name(HIC"���Ū��ѱM�Υ~�M"NOR,({"bluesky surcoat","surcoat"}) );
	set("long","�o�O�@�����Ū��ѱM�Υ~�M�C\n");
	set_weight(4800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "crimsonsteel");
		set("unit", "��");
//		set("value",1800);
		set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
        }
        setup();
}

int query_autoload() { return 1; }

