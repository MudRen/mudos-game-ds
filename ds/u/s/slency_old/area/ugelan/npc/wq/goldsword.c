// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"��  �C"NOR, ({ "Gold sword","sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ѯª��ҥ��y���C�M�ݰ_�ӤQ���W�Q�B�۷����ˤO, ���q�j�����Q�Ӥ祪�k�C\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤, �Pı���q�۷��C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
    init_sword(80);
	setup();
}
