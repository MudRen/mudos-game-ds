#include <weapon.h>
inherit BOW;

void create()
{
	set_name("重弩",({"heavy cross bow","bow"}));
	set_weight(10000);
	set("long","這是一把強化過後的弩, 射出的弩箭速度都相當有破壞力。\n");

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("material","wood");
		set("limit_skill",60);
                set("limit_int",30);
                set("limit_dex",30);
                set("limit_str",30);
        }
        set("weapon_prop/str",2);
	set("weapon_prop/dex",-1);
       init_bow(60,TWO_HANDED);
        setup();
}
