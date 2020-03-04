// An example book

inherit ITEM;

void create()
{
	set_name("�h�a���k�n��", ({ "book" }));
	set_weight(600);
	set("unit", "��");
	set("long",
		"�o�O�@�����Ьh�a���k���J���ѡM�h�a���k�O���F��h�Ѯ��v���Ǫ����k\n"
		"�M���ǩ����M�o�������M�u���ФF�h�a����J�����\\�ҡM���O�ΨӨ����w\n"
		"�g�⤣���F�M�A�X��Ǫ̡C\n");
	set("value", 100);
	set("skill", ([
		"name": 		"liuh-ken",		// name of the skill
		"exp_required":	0,				// minimum combat experience required
										// to learn this skill.
		"sen_cost":		40,				// gin cost every time study this
		"difficulty":	20,				// the base int to learn this skill
										// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	10				// the maximum level you can learn
										// from this object.
	]) );
}
