#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIY"左極大衣"NOR,({ "joh ji surcoat","surcoat" }) );
	set("long","這是一件官兵所穿著的大衣，大衣後方印著猛虎的樣子，十分好看。\n");
	set_weight(6000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",4);
        set("material","fur");
		set("unit", "件" );
		set("value",1100);
		set("armor_prop/armor", 9);
		set("armor_prop/shield",2);
	}
	setup();
}
