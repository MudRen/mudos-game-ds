#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIM"�e��"HIG"����"NOR, ({"flurry necklace","necklace","flurry" }) );
	set("long", "�o�궵��O�ΨӪ���b�e����������������C\n");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("armor_prop/armor",  3);
	set("material","gem");
		set("value", 450);
	}
	setup();
}
