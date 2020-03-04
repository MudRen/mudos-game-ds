#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name("修羅魔劍", ({ "shura sword","sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把長劍相傳是四大靈劍之首, 是由左宗平親手所製, 蘊藏靈氣。\n");
		set("value", 60000);
		set("material", "crimsonsteel");
		set("wield_msg",HIW"$N「鏘」地一聲抽出一把$n握在手中, 頓時昊光萬丈!\n"NOR);
		set("unwield_msg",CYN"$N將手中的$n收回劍鞘之中, 四周光芒漸漸暗淡。\n");
		set("limit_skill",60);
		set("limit_int",45);
		set("limit_dex",45);
                set("replica_ob",__DIR__"shurasword2");
	}
    set("weapon_prop/dex",2);
    set("weapon_prop/con",2);
    set("weapon_prop/parry",5); 
    set("weapon_prop/int",2);
    set("weapon_prop/str",2);
    set("weapon_prop/hit",5);
    init_sword(62);
    setup();
}
