// cloth.c
#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
	set_name(HIC"���Ū��ѱM�Τ�M"NOR,({"bluesky gloves","gloves"}));
	set("long","�@�����Ū��ѱM�Τ�M�C\n");
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "silver");
//		set("value",3900);
        	set("armor_prop/armor", 10);
        }
        setup();
}

int query_autoload() { return 1; }

