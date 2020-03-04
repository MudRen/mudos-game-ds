#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name("紅色大袍", ({ "buddhist robe","robe" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件大型的袈裟通常都是一寺之主才會穿的(權力?)象徵之物,\n"
                           "你仔細一瞧, 果然品質上好.\n");
		set("unit", "件");
		set("value",1999);
		set("material", "cloth");
	}
	set("armor_prop/dex",-1);
	set("armor_prop/int",1);
	set("armor_prop/armor",7);
	set("armor_prop/shield",7);
	setup();
}
