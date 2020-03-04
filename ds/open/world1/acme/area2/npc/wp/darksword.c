#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit SWORD;

void create()
{
        set_name(HIR "幽冥劍" NOR,({"you ming sword","you","ming","sword"}) );
        set("long",
        "這是一把散發著陰氣的妖劍，劍身透著鮮紅光芒。\n"
        "這把劍傳說是由天殘邪佬在南山荒澤處，尋覓到的\n"
        "紅鐵打造而成，據說打造此劍，花費了無數的人力\n"
        "和財力，和七七四十九年的光陰，而成的舉世無雙\n"
        "之劍。\n"
        );
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
        set("value",8000);
                set("limit_str",20);
		set("limit_con",30);
		set("volume",3);
                set("limit_int",10);
                set("limit_dex",5);
		set("limit_skill",70);
        }
   set("weapon_prop/dodge",7);
    set("weapon_prop/bar",1);
	set("weapon_prop/bio",1);
    set("weapon_prop/tec",-2);
        init_sword(60);
        setup();        
}
