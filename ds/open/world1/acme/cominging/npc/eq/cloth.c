#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("官服" ,({ "ossifer's cloth","cloth" }) );
	set("long","這是件縣老爺平時上早朝時所穿的衣服。\n");
	set_weight(2500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
        set("material", "cloth");
		set("unit", "件" );
		set("value",800);
	}
	set("armor_prop/armor", 8);
	setup();
}
