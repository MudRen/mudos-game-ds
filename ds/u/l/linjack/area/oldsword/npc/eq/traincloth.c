#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("�m�Z�A", ({ "training cloth","cloth" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��窫���I��, �O�H���ť��ư���, �������_,\n"
                           "�Q���A�X�Ψӽm�ߪZ�N�ɬ�ۡC\n");
		set("unit", "��");
		set("value",1500);
		set("material", "cloth");
		set("limit_dex",10);
	}
	set("armor_prop/armor",5);
	set("armor_prop/shield",3);
	set("armor_prop/show_damage",1);
	set("armor_prop/int",1);
	set("armor_prop/dex",1);
	setup();
}
