#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIW "懾日劍" NOR, ({ "se ri sword","sword" }) );
        set_weight(17000);
        if( clonep() )
		 set_default_object(__FILE__);
        else {
		set("unit", "把");
        set("material","crimsonsteel");
        set("limit_str",20);
                set("limit_int",25);
		set("long",
			"這是一把閃著比太陽還要亮之光芒的長劍，\n"
			"劍呈金黃色，但卻不是黃金，不知是由何種\n"
			"材質所鑄造而成，在陽光底下閃爍著，非常\n"
			"耀眼。\n");
		set("wield_msg", "$N從背後劍鞘中抽出一把金光閃閃的$n，握在手中當武器。\n");
		set("unwield_msg", "$N將手中的$n插入背後劍鞘中。\n");
          set("value",8000);
        set("replica_ob",__DIR__"longsword");
set("volume",5);
        }
	set("weapon_prop/con", 1);
     set("weapon_prop/dex",3);
    set("weapon_prop/hit", 10);
        init_sword(67,TWO_HANDED);
	setup();
}
