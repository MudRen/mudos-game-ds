#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW"���üC"NOR, ({ "yun-tsang sword", "yun-tsang", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�@��q�鴲�o�۬��R���ݥ��A�����C�A��ⳡ���J�\\�ӿ��A\n"
			"�C�`��ۤ@�T�y�����b�A��륩���Ҽ˯u�O�O�H�R������C\n");
		set("value", 12400);
		set("material", "silver");
		set("wield_msg", "�uť���u�B�v�a�@�n�M$N���⤤�w�g�h�F�@����~�|�g���_�C�w�w$n�C\n");
		set("unequip_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
	init_sword(20);
	setup();
}
