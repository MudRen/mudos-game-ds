#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(GRN"商隱劍"NOR, ({ "shang in sword","sword" }) );
	set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把劍已經有十分久遠的歷史, 傳說是疾風門開山祖師留下的寶劍。\n");
		set("value", 15000);
		set("material", "crimsonsteel");
		set("limit_skill",40);
		set("limit_int",20);
		set("limit_con",20);
		set("weapon_prop/dex",1);
		set("weapon_prop/int",1);
		set("weapon_prop/parry",3);
		set("weapon_prop/dodge",3);
	}
    init_sword(45);
    setup();
}
