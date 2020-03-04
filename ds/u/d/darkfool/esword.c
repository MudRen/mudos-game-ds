#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIW"邪劍"HIB"劍魔憑依"NOR, ({"evil sword","sword"}));
	set_weight(1000);
	if( clonep() )
	     set_default_object(__FILE__);
           else {
		set("unit", "把");
		set("long","一把看起來舊舊的長劍，密密麻麻的古文刻滿了整個劍身。你凝視著劍上\n"
		"的古文，突然覺得那些奇形怪狀的字好像有生命般自己流動了起來！令你\n"
		"不禁打了一個寒顫。\n");
		set("value", 8000);
		set("material", "steel");
		set("wield_msg", "$N將$n刷地一聲抽出來握在手上。\n");
		set("unwield_msg", "$N將$n收了起來。\n");
	        	
	}
	init_sword(100);
	setup();
}