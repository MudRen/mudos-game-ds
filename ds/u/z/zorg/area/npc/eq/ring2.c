#include <path.h>
#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIC"能量戒子"NOR,({"pwoerful ring","ring"}));

	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",HIB"這是一枚不尋常的戒子，看來這戒子有一些特別之處。\n"NOR);	    
                	set("unit", "枚");
		set("value",4000);
         		set("material", "starring");
		set("armor_prop/armor", 10);
		set("limit_str",32);
		set("armor_prop/int",5);
	}
	set("wield_msg","$N從袋裡拿出$N戴在手上！\n");
	set("unwield_msg", "$N將手中的$n小心收好。\n");
	setup();
}
