// sword.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIR "�G�C����" NOR, ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�o�O�@�����J�����j�C�M�D�_�Ӧ��@�ѭ����M�C����۳\\�h�A�q�����L���G\n"
			"��M�u���C�`��������Ө̵}�i�H��{���f�r�R�u �� �� �v\n");
		set("value", 18000);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
		set("unequip_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}

	init_sword(44);
	setup();

	set("weapon_prop/spirituality", 30);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage;

	if( victim->is_ghost() ) {
		if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) {
			damage = me->query_spi();
			victim->receive_wound("gin", damage);
			me->receive_heal("gin", damage);
			me->receive_heal("kee", damage);
			me->receive_heal("sen", damage);
			return HIY "���ռC�o�X�@�Ѫ��⪺�\\��M�y�M$N�������C\n" NOR;
		}
		return random(me->query_spi());
	}
}
