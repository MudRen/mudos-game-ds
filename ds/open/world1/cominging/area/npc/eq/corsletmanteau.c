#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIM"�ҫ`"HIG"�ܭ�"NOR, ({ "corslet manteau","manteau","corslet" }) );
	set("long", "�o��ܭ��᭱�_�F�Ӥj�j���r�y�Z�z�A�Ѧ��i���o�O��԰��Ϊ��ܭ��C\n");
	set_weight(1200);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
	set("material","leather");
		set("armor_prop/armor", 6);
		set("volume",5);
		set("value", 1800);
	}
	set("wear_msg","$N�q���W�j�X�@��$n�åB��$n�M�b���W�C\n");
	set("unequip_msg","$N�H���p���α��ժ��t�ק�$n�p�ߪ�����h���C\n");
	setup();
}
