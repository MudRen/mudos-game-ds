#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"月光鎧"NOR, ({ "moonglow armor","armor" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件寶甲外層隱透白光, 有如明月之輝, 在白天就已經\n"
                           "閃閃發光, 夜晚更是亮得如同一輪明月, 實是一件相當難得\n"
			   "的寶甲.\n");
		set("unit", "件");
		set("material","steel");
	set("value",1);
		set("needaward",35);
	}
        set("armor_prop/con",3);
	set("armor_prop/int",3);
	set("armor_prop/dodge",5);
	set("armor_prop/shield",20);
	set("armor_prop/armor",40);
	setup();
}

int query_autoload() { return 1; }

void init()
{
 if( environment(this_object()) == this_player() )
  this_player()->set_temp("has_light",1);
}
