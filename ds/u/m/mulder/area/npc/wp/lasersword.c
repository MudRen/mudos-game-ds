// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("電光劍", ({ "laser sword","sword" }) );
	set_weight(3600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是未來常用的武器。\n");
		set("value",1800);
		set("material", "laser");
		set("unwield_msg", "$N將手上的"HIB"電光劍"NOR"收藏起來。\n");
	}
    init_sword(10);
	setup();
}
