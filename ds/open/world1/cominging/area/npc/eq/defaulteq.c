#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("預備衣物", ({ "default cloth","cloth" }) );
	set("long", "一件由精工所織成的衣物，似乎不比平常一物一般。\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value",600);
	}
	setup();
}

