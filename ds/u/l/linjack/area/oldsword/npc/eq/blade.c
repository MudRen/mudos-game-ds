#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("單刀", ({ "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這種刀在江湖上十分常見, 刃長近三尺, 是一般刀客常用的刀。\n");
		set("value", 1000);
		set("material", "iron");
	}
    init_blade(15);
    setup();
}
