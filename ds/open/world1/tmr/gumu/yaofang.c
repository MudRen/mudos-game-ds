// Roo: /d/guu/yaofang.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�ĩ�"NOR);
	set("long", @LONG
�o���O�@���۫ǡA�P�򪺤���N�۫ǷӪ��O���q���A�۫Ǩ����\��
�F�ܦh�~�~�����A�W�����K�n�F��ñ�A�@�~�~�ɸ��߳Q�j�ӧ̤l��Z
��b���B�C�A��ݨ��X�ӥj�ӧ̤l���b���L���z���C
LONG	);
	set("exits", ([
		"north" : __DIR__"mudao10",
	]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice2" : 3,
        ]));      

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

void init()
{
//	add_action("do_make","make");
//	add_action("do_make","huo");
}

int do_make(string arg)
{
	object ob, name1, me = this_player();
	int exp,pot,score;

	ob= present("feng mi", me);
	name1= me->query("id");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("�A�����۩O�C\n");	
	if ( arg =="jiang")
	{
		if ( ! me->query_temp("gm_job1"))
            return notify_fail("�A�٨S�h�Ļe�O�A�L�k�s�y�ɸ��ߡC\n");
		if (!objectp(present("feng mi", me)))
            return notify_fail("�A�Τ���Ө�ɸ��ߡH\n");
		if ( ob->query_temp("gm/make") != name1 )
			return notify_fail("�o���e�n�H���O�A���Ӫ��a�H\n");	
		message_vision(HIY"$N�J�Ӧa�N���e�թM���áA��ɸ��ߡA��b�[�W�C\n"NOR,me);
		me->delete_temp("gm_job1");
		exp=40+random(20);
		me->add("combat_exp",exp);
		pot= 10+random(10);
		me->add("potential",pot); 
		score=2+random(5);
		me->add("score",score);
		call_out("destroying", 1, ob);
//        tell_object(me,HIW"�]���ҧ@�A�A�W���F�G" + chinese_number(exp) + "�I��Ըg��" + chinese_number(pot) + "�I���" + chinese_number(score) + "�I����\���C\n"NOR); 
		return 1;
	}
    return notify_fail("�A�Q����e�s������H\n");
}

void destroying(object ob)
{
	destruct(ob);
	return;
}

