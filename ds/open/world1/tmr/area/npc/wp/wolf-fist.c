#include <weapon.h>

inherit FIST;

void create()
{
	set_name("狼拳",({"wolf fist","fist"}) );
	set("long",@long
一對江湖拳師常配戴的狼拳，對於徒手博鬥倒增加了不少攻擊力。
long
	);
      set_weight(1500);

	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        set("value",1000);
	set("unit","對");
	set("wield_msg","$N拿起一對$n穿戴在手上，似乎強了不少。\n");
        set("material","iron");
	init_fist(15);
	set("weapon_prop/armor",5);
	}
	setup();

}
