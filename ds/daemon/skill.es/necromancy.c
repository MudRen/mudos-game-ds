// necromancy.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism") < (int)me->query_skill("necromancy")/2 )
		return notify_fail("�A���Ѯv���D�׬������M�L�k�⮩�󰪲`���T�s�D�N�C\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

string scribe_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("�A����z�٨S���������^�M���ֱ����A��"
			+ bug->name() + "�a�T\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("�A���k�O�����C\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("�A���믫�L�k�����C\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("�A���ؾ����M���C���~�M�}�l�ײ߭T�s�D�N�����k�N....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("�i�O�A�߫�@�áM�ܥX�F�@�����زu��" + bug->name() + "�T\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("�A����z���Q" + bug->name() + "���M�֧�e�����a�T\n");
	}	
	else return 1;
}
