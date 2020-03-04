#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("授武服", ({ "teaching cloth","cloth" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件衣服衣料高級, 而且上面還繡了一個大大的\n"
                           "『雲』的標記在右肩上。\n");
		set("unit", "件");
		set("value",2500);
		set("material", "silk");
		set("limit_con",15);
	}
	set("armor_prop/armor",9);
	set("armor_prop/shield",5);
	set("armor_prop/show_damage",1);
	set("armor_prop/dex",2);
	setup();
}
