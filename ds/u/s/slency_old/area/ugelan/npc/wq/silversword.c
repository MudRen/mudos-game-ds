// sword.c : an example weapon

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"��  �C"NOR, ({ "silver sword","sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��ѯ»ȩҥ��y���C�M�ݰ_�ӤQ���W�Q�B�۷����ˤO, �M�ӥ��q�o�u���G�Ӥ祪�k, �A�X�k�ʰt�ΡC\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤, �{�{�X�@�D�ե��C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
    init_sword(50);
	setup();
}
