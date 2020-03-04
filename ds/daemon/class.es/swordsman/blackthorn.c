// blackthorn.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��Ĭ�C", ({ "blackthorn sword", "blackthorn", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�o�O�@��q���K�ª����C�M�W���ͺ��F�y�U���˹_�M�D�O�쳱�h�a\n"
			"���N�۶Ǫ��_�C�M�ڻ��o��C���H���g��M�û��O������C\n");
		set("value", 2400);
		set("material", "blacksteel");
		set("wield_msg", "�uť���u�B�v�a�@�n�M$N���⤤�w�g�h�F�@��H���|�g���_�C�w�w$n�C\n");
		set("unequip_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
	init_sword(58);
	setup();
}
