#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
	set_name(HIC"���Ū��ѱM�ά޵P"NOR,({"bluesky shield","shield"}) );
	set("long","�o�O�Ѧʦ~���s�������Ū��ѱM�ά޵P�C\n");
	set_weight(5600);		
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

