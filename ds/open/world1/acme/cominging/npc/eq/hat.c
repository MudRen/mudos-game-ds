#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("烏沙帽" ,({ "Ossifer's hat","hat" }) );
	set_weight(1000);
	set("long","這是一頂縣老爺平時所穿載的，這頂帽子代表著「權利」。\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","cloth");
		set("unit", "頂" );
		set("value",500);
	}
	set("armor_prop/armor", 3);
	set("armor_prop/int",1);
	setup();
} 
