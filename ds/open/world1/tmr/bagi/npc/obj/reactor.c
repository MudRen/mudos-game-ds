#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("青銅丹鼎",({"reactor"}) );
	set_weight(3000);
	set("long",@long
一個青銅做的丹鼎，是方士用來盛配方的器具。
long
);
        set_max_encumbrance(4000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","個");
		set("value",200);
	}
	setup();
}