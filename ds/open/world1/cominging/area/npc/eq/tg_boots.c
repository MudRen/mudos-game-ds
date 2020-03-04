#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("過膝長靴", ({ "boots" }) );

	set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
            "一種士兵專用的鞋子，長過膝蓋\，並不怎麼方便行動，不\n"
			"過防禦力也因此增加了不少。\n");
		set("unit", "雙");
	set("material","leather");
		set("volume",2);
		set("value",800);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 3);
		set("armor_prop/dex",-1);
	}
	set("wear_msg","$N穿上一雙$n，似乎行動有些的緩慢。");
	set("unequip_msg","$N脫下了一雙$n，行動又恢復了！");
	setup();
}
