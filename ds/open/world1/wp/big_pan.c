#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
   set_name(CYN"青鐵馬掛筆"NOR, ({ "big pen","pen" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一隻比大楷毛筆猶大了數倍的鐵筆, 上面有 辛嚭 二字...。\n");
		set("material", "iron");
		set("limit_str",9);
	}
    set("weapon_prop/dex",-1);
    init_hammer(23);
    setup();
}

