// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"���C"NOR, ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ѯ¿��ҥ��y���C�M�ݰ_�ӤQ���W�Q, ���q�j�����Q�Ӥ祪�k�C\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
    init_sword(30);
	setup();
}
