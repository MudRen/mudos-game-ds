// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIC"一羽"HIW"天劍"NOR, ({ "sword" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把神仙賜與的仙劍﹐擁有神秘的力量, 其份量大約只有一來斤左右, 相當清盈。\n");
		set("value", 5400);
		set("material", "steel");
		set("wield_msg", "$N將手指向天空, 天空突然產生"HIW"一束白光"NOR"射向$N手中, 剛回神$N手中已握了一把$n。\n");
		set("unwield_msg", "$N將手中的$n往空中一拋, 居然憑空消失了!!你不禁懷疑你是不是眼花。\n");
	}
    init_sword(10000);
	setup();
}
