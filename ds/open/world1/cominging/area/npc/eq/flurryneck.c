#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIM"疾風"HIG"項鍊"NOR, ({"flurry necklace","necklace","flurry" }) );
	set("long", "這串項鍊是用來表明在疾風門中身份的項鍊。\n");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "串" );
		set("armor_prop/armor",  3);
	set("material","gem");
		set("value", 450);
	}
	setup();
}
