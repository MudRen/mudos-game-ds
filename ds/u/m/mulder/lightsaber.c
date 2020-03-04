// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
string *sabername = ({
	HIR+"光劍"+NOR,
	HIW+"光劍"+NOR,
	HIG+"光劍"+NOR,
	HIC+"光劍"+NOR,
	HIY+"光劍"+NOR,
	HIM+"光劍"+NOR,
	});
void create()
{
	set_name(sabername[random(sizeof(sabername))],({"lightsaber","saber"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是"HIW"『Jedi Knight』"NOR"的標記。\n");
		set("value", -1000);
		set("no_sac",1);
		set("limit_str",20);
		set("no_drop",1);
		set("no_steal",1);
		set("no_get",1);
		set("no_sell",1);
		set("rigidity",1000);
		set("material", "blacksteel");
		set("wield_msg", "$N從腰上拿出一把$n,$N按下按鈕,突然$n伸出一道"HIG"激光"NOR"。\n");
		set("unwield_msg", "$N將手上的$n放回腰間。\n");
	}
     init_sword(60,TWO_HANDED);
	setup();
}
int query_autoload() { return 1; }
