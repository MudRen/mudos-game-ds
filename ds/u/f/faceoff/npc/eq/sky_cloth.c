#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(MAG"朱雀戰衣"NOR ,({ "sky cloth","cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","這是傳說中上古時代女媧所穿的衣衫, 傳說中祂穿著這件衣服
手持七彩石縫補天空的破洞, 據說穿上它會受到神力的保護, 但不管怎麼樣, 這
件護甲絕對有你前所未見的神奇防禦力。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/shield",2);
		set("armor_prop/armor", 19);
	}
	setup();
}
