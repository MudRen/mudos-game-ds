#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("�P��", ({ "buddhist cloth","cloth" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@���a�l�̭׹D��������, �q�`���|��W��\n"
                           "���T, �Z�p����, ��W�ᦳ�Ǥ��K��ֳt���.\n");
		set("unit", "��");
		set("value",1000);
		set("material", "linen");
	}
	set("armor_prop/dex",-1);
	set("armor_prop/int",1);
	set("armor_prop/armor",3);
	set("armor_prop/shield",5);
	set("armor_prop/show_damage",1);
	setup();
}
