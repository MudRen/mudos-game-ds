#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(HIB"�ŦB��"NOR, ({ "Blue ice ring","ring" }) );
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", @LONG
    �۶Ǧb�W�j���ҮɥN���@�y����F�_�����ŦB���A�B������
�õۤd�~���o�������q�ۡA�M�ӦB���צ~���N�b�h�h�B�����A�s
�s��¶���a�Q��Ϧ��B�Z�H���H�I�ǡA���D�Z�\���j���h�_�h�w
���J�s���ۡI���ŦB�٥��O�\�@�Q���u���Сv������J�B�����o
�q�ۨû��o��N�W�K�u�v��v�������J�ӵZ�Ӧ����٫��C
LONG
    );
		set("unit", "�u");
		set("value", 1);
		set("no_drop", 1);
		set("can_give", 1);
				
		set("wear_msg", HIB"$N"HIB"���W�F�ŦB�١A�@�h���Ŧ⪺��������Ţ�n��$N"HIB"�I"NOR);
		set("unequip_msg", BLU"$N"BLU"���U�F�ŦB�١A���������]�C�C�ƴ���Ť�...\n"NOR);
		
		set_weight(100);
		set("armor_prop/int", 10);
		set("armor_prop/armor", 5);
		set("armor_prop/shield", 10);		
	}
	
	setup();
}

int query_autoload() { return 1; }
