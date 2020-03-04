// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name(HIB"�q���C"NOR, ({ "laser sword","sword"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O���ӱ`�Ϊ��Z���C\n");
		set("value", 400);
		set("material", "platminum");
		set("wield_msg", "$N���U"HIB"�q���C"NOR"���s,��M�g�X�@��C�C\n");
		set("unwield_msg", "$N�N��W��"HIB"�q���C"NOR"���ð_�ӡC\n");
	}
    init_sword(2500);
	setup();
}
