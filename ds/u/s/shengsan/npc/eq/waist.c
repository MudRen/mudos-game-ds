#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create()
{
	set_name(HIC"���Ū��ѱM�Χ��y"NOR,({"bluesky waist","waist"}));
	set("long","�@�����Ū��ѱM�Χ��y�C\n");
	set_weight(180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit","��");
		set("material","silk");
//		set("value",1800);
        	set("armor_prop/armor", 10);
	}
	setup();
}

int query_autoload() { return 1; }

