#include <ansi2.h>
#include <armor.h>
inherit LEGGING;
void create()
{
	set_name(HIC"�^���H��"NOR ,({ "hero leggings","leggings" }) );
	set("long","�L�W�^����~�˳Ƥ��@�A�ണ���˳ƪ̪��t�סC\n");
	set_weight(2000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("material", "leather");
	set("volume",5);
	set("unit", "��");
	set("value",1500);
	}
	set("armor_prop/armor",3);
	set("armor_prop/dex",3);
	set("armor_prop/dodge",10);
	setup();
}
