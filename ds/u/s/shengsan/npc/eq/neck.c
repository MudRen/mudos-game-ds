#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIC"���Ū��ѱM�ζ���"NOR,({"bluesky necklace","necklace"}));
	set("long","�o�O�@�����Ū��ѱM�ζ���C/n");
	set_weight(720);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "��");
//		set("value",1800);
        	set("armor_prop/armor", 10);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }

