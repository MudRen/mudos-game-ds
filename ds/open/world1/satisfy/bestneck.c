#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIY"�K���ťO"NOR, ({ "eight necklace","necklace" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�ݰ_�ӹ��O�D�氪�����D�h�Ұt�a���F��,\n"
                           "��k�N����ܤO���۷��¤O�C\n");
		set("unit", "��");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",30000);
		set("armor_prop/wit",2);
		set("armor_prop/sou",1);
		set("armor_prop/int",4);
		set("armor_prop/shield",15);
		set("armor_prop/armor", 1);
	}
	setup();
}

int query_autoload() { return 1; }