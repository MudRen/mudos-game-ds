// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("force", - factor );
	damage = (int)me->query("force")/20 + factor
		- (int)victim->query("force")/25;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "kee", damage * 2 );
			me->receive_wound( "kee", damage );
			if( damage < 10 ) return "$N����$n�����O�Ͼ_�M�e��@�n�C\n";
			else if( damage < 20 ) return "$N�Q$n�H���O�Ͼ_�M�u�K�v�a�@�n�h�F��B�C\n";
			else if( damage < 40 ) return "$N�Q$N�H���O�@�_�M�ݤf���p����@�O����M�s�h�F�����B�T\n";
			else return "$N�Q$n�����O�@�_�M���e�@�¡M���l�V�᭸�X�V�\\�T�T\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}
