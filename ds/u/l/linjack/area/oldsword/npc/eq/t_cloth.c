#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("�ªZ�A", ({ "teaching cloth","cloth" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���A��ư���, �ӥB�W����¸�F�@�Ӥj�j��\n"
                           "�y���z���аO�b�k�ӤW�C\n");
		set("unit", "��");
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
