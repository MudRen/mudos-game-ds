#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name("隱絕。地脈", ({ "special blade","blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把刀和一般長刀慣用者使用的長刀並無兩樣, 不過仔細\n"
                            "觀看便會發現, 此刀的刀刃較寬且鈍, 刀感厚實, 實在不知這\n"
			    "種渾無霸氣的刀, 如何稱得上是一把寶刀?\n");
		set("value", 18000);
		set("material", "steel");
		set("limit_skill",40);
		set("limit_dex",30);
		set("limit_int",15);
		set("replica_ob",__DIR__"bigblade.c");
        }
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/bio",-1);
    set("weapon_prop/tec",-1);
    set("weapon_prop/hit",8);
    init_blade(45);
    setup();
}
