/**
 *	Shadow's boots
 *	�H����c���d����s.
 */
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
	set_name(HIW"����"NOR, ({ "snow feather boots","boots" }) );
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
    ���u��զp���A��d�פ��e��礣�V�W�ЮJ�C�Ӭݤ��U�A��
ı���u�D�ѵL�Ƴ��ХH�륩�L�񪺤�k�h�h�s´�Ӧ��A��e�s´
���ުk���n�B�a�N���е}�������ݴO�J�c���A�u�S�X���վ��
���Ш��A�E�ݤ��U���}�S�p�}��⳷�խ������ƶh�p�P�C
LONG
    );
		set("unit", "��");
		set("material", "cloth");
		set("needaward", 9);
		set("value", 1);
		set("no_drop", 1);
		set("can_give", 1);

		
		set("wear_msg", HIW"$N"HIW"��W�F�@�����СA�|�P�y�ʪ��Ů�]����ƶh�_�ӡI"NOR);
		set("unequip_msg", HIW"$N"HIW"��U�F���СA���R��������y�]�H���H�I�I\n"NOR);
		
		set_weight(100);
		set("armor_prop/dex",5);
		set("armor_prop/dodge",50);
		set("armor_prop/armor",10);
	}

	
	setup();
}

int query_autoload() { return 1; }
/*
    �j�a���_���W�s�@�y�W���u�E��v�A���s�H�Ϩu�ܡA�����D
�`�C�s���øV���~�L�ơA���@�����u���n�v�A�˦���Ħӻ�Y��
�a�A���ͥi���O�U���A�ڻD�Y�H���n���нs´���u�A�˳Ƥ��H�i
�@��d���{�p
*/