#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("�]������", ({ "night-vision glasses","glasses" }) );
	set("long",@LONG
�o�O�@�Ƴ̷s��ު��]������A�i�H�N�L�z�����u�[�j�체���i�H��
�쪺�{�סC
LONG
);
	set_weight(1050);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
//	set("armor_prop/show_damage",1);
	setup();
	set("value",2280);
}

int wear()
{
	if(::wear())
	{
		this_object()->start_light(1);
		return 1;
	}
	else return 0;
}

int unequip()
{
	if(::unequip())
	{
		this_object()->start_light(0);
		return 1;
	}
	else return 0;
}

//int query_autoload() { return 1; }
