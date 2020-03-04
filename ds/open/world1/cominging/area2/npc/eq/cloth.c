#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("金縷衣", ({ "golden cloth","cloth" }) );
	set("long", "一件閃閃發亮的衣服, 擁有不錯的防禦力。\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件" );
		set("armor_prop/con",    2);
		set("armor_prop/armor",  10);
		set("value", 7600);
	}
	setup();
}