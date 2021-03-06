#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name(HIG"商隱劍"NOR, ({ "shang-ing sword", "sword", "shang-in" }));
	set("long", "這把劍已經有十分久遠的歷史, 傳說是疾風門開山祖師留下的寶劍。\n");
	set_weight(12500);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("volume",2);
		set("material", "crimsonsteel");
		set("limit_skill",50);
		set("limit_int",25);
		set("limit_dex",25);
       set("value",10000);
		set("limit_lv",        15);
	set("replica_ob",__DIR__"longsword");
	}
	set("weapon_prop/hit", 15);
	set("weapon_prop/con",  2);
	set("weapon_prop/dex",2);

	set("wield_msg","$N從腰部上抽出一把"HIY"$n"NOR"。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

	init_sword(65);
	setup();
}
