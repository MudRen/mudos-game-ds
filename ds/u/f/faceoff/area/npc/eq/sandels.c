#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("�w����c", ({ "sandels","boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��c���~�����[�@�h�w��, �W�[��a���i���O.\n");
		set("unit", "��");
		set("material", "fur");
		set("armor_prop/shield",1);
		set("armor_prop/armor",2);
	}
	setup();
}
