#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("木頭", ({ "wood" }) );
	set_weight(100);
	set("long", "一根又大樹上掉下來的木頭，估計重約"+query_weight()+"克。\n");
	set("value", 0);
	set("unit", "根");

	setup();
}

void init()
{
	set("long", "一根又大樹上掉下來的木頭，估計重約"+query_weight()+"克。\n");
}