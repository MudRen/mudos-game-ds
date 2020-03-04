#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"無極戰甲"NOR,({ "wu ji armor","armor" }) );
	set("long","這是一件由烏蠶的絲且用手工編織而成的戰\n"
		   "甲，十分的保暖，卻也相當的密實，連上好\n"
		   "的兵刃都無法傷它分毫，在烏蠶的外表覆著\n"
		   "一層青鋼，更增其防禦性能。\n");
	set_weight(15000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",6);
         set("material","steel");
		set("unit", "件" );
       set("value",7500);
		set("armor_prop/armor", 30);
		set("armor_prop/shield",10);
	}
	setup();
}
