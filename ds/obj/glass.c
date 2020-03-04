// glass.c

inherit EQUIP;

void create()
{
	set_name("�԰��O������", ({ "detector", "glass", "device" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		"�o�O�Ӧۡu�C�s�]�v���԰��O�������M�A�i�H�Υ��ӱ���(detect)�O�H\n"
		"���԰��O�C\n");
	set("value", 500);
	set("type", "misc");
	set("apply", ([
		"�Y��":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
}

int do_detect(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("�A�n�����֪��԰��O�S\n");

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf("���������%s���԰��O�O�R%d\n",
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );

	return 1;
}

