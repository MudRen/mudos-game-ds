#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIM"����"HIG"��"NOR, ({ "fly armor", "armor" , "fly" }) );
	set("long", "�o�_�Z�ҬO�����E�b�`�s���צ欰��K�樫�ҥΪ��˥Ҥ��@�C\n");
	set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("armor_prop/dex",    3);
	set("armor_prop/armor",18);
	set("material","steel");
		set("volume",4);
		set("limit_lv",10);
		set("limit_con",10);
	set("value", 17500);
	}
	set("wear_msg","$N�@�˳ƤW$n��M�Pı�����ƪ��C\n");
	set("unequip_msg","$N�@��U$n���W�I���@�n�^�˦b�a�W�C\n");
	setup();
}
