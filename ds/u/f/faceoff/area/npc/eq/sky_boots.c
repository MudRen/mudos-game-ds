#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(MAG"朱雀戰靴"NOR, ({ "sky boots","boots" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這是傳說中上古時代女媧所穿的皮靴,
 據說穿上它會受到神力的保護, 但不管怎麼樣, 這件護具可
 以提供你良好的足部防禦力。\n");
		set("unit", "件");
		set("material", "fur");
		set("armor_prop/shield",4);
		set("armor_prop/armor",9);
	}
	setup();
}