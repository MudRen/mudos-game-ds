#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "逍遙劍" NOR, ({ "loiter sword","sword" }) );
        set_weight(12000);
        if( clonep() )
		 set_default_object(__FILE__);
        else {
		set("unit", "把");
        set("material","crimsonsteel");
		set("limit_str",23);
		set("long",
            "這是一把綠色的長劍，劍郴處刻著「逍遙」二字，此劍看來相當鋒利。\n");
		set("wield_msg", "$N從背後劍鞘中抽出一把金光閃閃的$n，握在手中當武器。\n");
		set("unwield_msg", "$N將手中的$n插入背後劍鞘中。\n");
        set("value",6000);
        }
	set("weapon_prop/con", 1);
	init_sword(45);
	setup();
}
