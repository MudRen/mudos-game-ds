// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�j�M", ({ "blade" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@�������`�H�Ұt�a���M��, ���L�o�j�W�F�X�o�C\n");
		set("value", 15);
		set("material", "steel");
		set("wield_msg", "$N�u�q�y�����X�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���^�y���C\n");
	}
    init_blade(30);
	setup();
}
