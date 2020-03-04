#include <ansi.h>
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance"

inherit ROOM;

int doll_check(object me);
int delete_record(object me);
int record(object me);
int check(object me);
int announce(object me);

void create()
{
	set("short", "��Z���X�f");
	set("long", @long
�o�̬O��Z�����X�f�A�Ҧ����ɪ̳��|�ѳo�̥X�ӡA��M�禳�j
�媺��Z���a�ʷ��H���b�o�ˬd�U���ɪ̦��S�a��Z�������������}�C
���ɪ̽Х�"out"���h�C
long);
	set("light", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_cast", 1);
	set("no_recall", 1);
	set("objects", ([
		__DIR__"npc/checker" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();

	if( !me ) return;

	add_action("doll_check", "out");

	if( !me->query_temp("match_player") )
		return;

	if( !me->query_temp("match_winner") )	announce(me);

	if( me->query_temp("match_winner") )	record(me);

//	doll_check(me);
	delete_record(me);
	check(me);
}

int doll_check(object me)
{
	object doll;
	me = this_player();
        message_vision(HIW"��Z���ʹ�H�����b�ˬd$N���W���S���⦳��Z��������......\n"NOR, me);

	if( objectp(doll = present("match doll", me) ) )
	{
		message_vision(HIW"��Z���ʹ�H����A���W��"NOR+doll->query("name")+HIW"�����F�C\n"NOR, me);
		destruct(doll);
	}
	me->move(ENTER_ROOM);

	return 1;
}

int delete_record(object me)
{
	me->remove_all_killer();

	return 1;
}

int record(object me)
{
	MATCH_D->record(me);
	return 1;
}

int check(object me)
{
	MATCH_D->check(me);
	return 1;
}

int announce(object me)
{
        message("system", HIW"�i"HIG"��Z�q�i"HIW"�j"HIG""+me->query("name")+NOR HIG"("+me->query("id")+HIG")�b�o����Z�����ѤF�C\n\n"NOR, users());

	return 1;
}
