// Room: /d/gumu/lingwu.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>

inherit ROOM;
void create()
{
	set("short",HIC"�⮩��"NOR);
	set("long", @LONG
���a�ѦU�̤l�����R�פ��ΡC�a�W�Ȧ��X�ӻZ�ΡA�X��֨k�֤k��
�b���ػ⮩�C�F���۾��W���@��Y�_�A��ۤ��֤�r(wall), �譱�a�W
���@��W���A��ۨǥj�Ǫ��ϧ�(ground), ���W���@�Ǭ��k�ϧ�(top)�C
LONG	);
	set("exits", ([
		"north" : __DIR__"mudao23",
	]));
	set("item_desc", ([
		"top"    : HIC "\t�ɤk�C��_�šA�p������A���Φ��ܡC\n"NOR,
        "wall"   : HIC "\t���\\�ߪk...�j�Ӥl�̥i��ߤ_���C\n"NOR,
		"ground" : HIC "\t�{���ˮ����N...�j�Ӥl�̥i��ߤ_���C\n"NOR,
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_lingwu", "lingwu");
	add_action("do_lingwu", "think");
}

int do_lingwu(string arg)
{
	mapping fam;
	object me=this_player();
	int c_exp, c_skill;

	if ( !arg ) 
		return notify_fail("�A�n�ѷӭ����ӻ⮩�H\n");
	
	// add by tmr 2006/10/23
    return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");

	c_skill=(int)me->query_skill("dodge", 1);
	c_exp=me->query("combat_exp");
	if (!(fam = me->query("family")) || fam["family_name"] != "�j�Ӭ�")
    return notify_fail("�A���O�j�ӶǤH�A�L�k�⮩�j�ӪZ�\\�C\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����ۭ��I\n");
	if ((int)me->query_skill("literate", 1) < 30)
		return notify_fail("�A�X��r���Ѥ@�Y���A�⮩��ԣ�H\n");
	if (arg == "top")
	{
		message_vision(HIY"$N�}�l�������W���k�ϧΡC\n"NOR, me);
		if ((int)me->query("jing") < 25)
			return notify_fail("�A�@�}�w�ۡA�Q�O�θ��L�סA�ӥ𮧤@�|�F�C\n");
		me->receive_damage("jing", 25);
		if ((int)me->query_skill("force", 1) < 30)
		{
			message_vision(HIM "$N�ݵ۬��k�ϧζ}�l���W�F�A�إ����ĤġA���X�{�T�����N�C\n"NOR, me);
			write(HIR"�A�w�O�����A�o�˪��ϵe�٬O�֬ݬ����C\n"NOR);
			message_vision(HIR"$N���M�n�̰_�ӡA�Z�a�Q�X�f�A��C\n"NOR, me);
			me->receive_wound("qi", 10);
			me->unconcious();
			return 1;
		}
		if ((int)me->query_skill("unarmed", 1) < 30 )
			return notify_fail("�A���७�߼f���o�ǻr�k�ϡA�o���Ѩ䤤�����Ҧb�C\n");
		if (me->query_skill("meinv-quan", 1) >= 1)
			return notify_fail("�A�w�Ƿ|�F���k���A�n��W�@�B�A�u��a�ۤv�ԥ[�m�ߡC\n");
		write(HIY"�A�R�߬�߳��W�����k���ΡA�⮩��j�Ӭ����k���k������Ҧb�A�y�ɭT��y�}�C\n"NOR);
		me->improve_skill("meinv-quan", 10);
		write(HIR "���ߡA�o��" + RANK_D->query_respect(me)+"�A�A�w�g�Ƿ|���k���k�F�C\n"NOR);
		return 1;
	}
	if (arg == "wall")
	{
		c_skill=(int)me->query_skill("force", 1);
		if (c_skill > 50)
            return notify_fail("�۾��ҭz�ɦb�A�ߡA�A�L�k�A���X����s�F��C\n");
		if ((int)me->query("jing") < 20 )
			return notify_fail("�Aı�o�n�֡A�n�Q��ı�C\n");
		me->receive_damage("jing", 5 + random(15));
        write("�A�R�߬�ߥ۾������y�A�鷺�\\�ߪk���ǻ⮩�C\n");
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("force", random(me->query("int")));
		return 1;
	}
	if ( arg =="ground" )
	{
		c_skill=(int)me->query_skill("parry", 1);
		if (c_skill > 50)
			return notify_fail("�A��ۦa�W��ߤ@�|�A�uı�ҭz���w���ä߯ݡC\n");
		if ((int)me->query("jing") < 20)
			return notify_fail("�A�@�}�w�ۡA�Q�O�θ��L�סA�ӥ𮧤@�|�F�C\n");
		me->receive_damage("jing",5 + random(15));
		write("�A�ҥ�a�W���ϧΤW���U�a�A�ײߩ۬[�{���C\n");
		if (c_skill*c_skill*c_skill/10<c_exp)
			me->improve_skill("parry", random(me->query("int")));
		return 1;
	}
	return notify_fail("�A�L�k�ѷӨ����ӻ⮩�C\n");
}

