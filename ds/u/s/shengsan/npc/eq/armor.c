#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name(HIC"���Ū��ѱM�β���"NOR,({"bluesky armor","armor"}) );
	set("long","�@�����Ū��ѱM�β��ҡC\n");
	set_weight(8300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit", "��");
//		set("value",8300);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
        }
        setup();
}

int query_autoload() { return 1; }

