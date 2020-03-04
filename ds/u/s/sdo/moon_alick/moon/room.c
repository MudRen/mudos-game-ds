/*	room.c					*
 *	write by alickyuen@ds 20-9-2001		*
 *	�޲z���� ����` ���D�����{��		*/

#include <ansi.h>
#define DATA_D __DIR__"data"
#define EXIT_D __DIR__"exit"
#define LOADED_DIR __DIR__"loaded/"

inherit ROOM;

string *id = ({ });

void renew();

void create()
{
	set("short", "��O�j�|");
	set("long", 
"�o�̥��O�@�~�@�ת�����`����O�j�|���a�A�o�̤H�s�H���A��\n"+
"���o�ܡC�A���Y�W���O�@��來�m�}�A����O�A�������񦳶��A�ڦ�\n"+
"�h�ӳзs�A�����ɦ��A���o����y�F�@�ӫܦn����^�C�o���٦��@��\n"+
"�S�O�j����O�A�W���٦��@�i�ȡA��ӬO�o�Ӫ�O�j�|���S�O������\n"+
"�y�O���v�v�z�C\n"+
"\n�ȤW�g�ۡG\n"+this_object()->show_question()
);

	set("no_recall", "�o�̤Ӧh�H�F�A�ѯ�ť����A���I�l�C\n");
	set("light", 1);

	setup();

	set("channel_id", "��j�|�O�u�@�H��(Officer)");
}

void init()
{
	object room = this_object();

	if( !room->query("question") ) 
	{
		DATA_D->show_question(room);
		renew();
	}

	if( !room->query("exits") ) EXIT_D->show_exit(room);

	add_action("do_answer", "answer");
	add_action("no_ask", ({ "say", "tell" }) );
}

int do_answer(string ans)
{
	object me, file;
	
	me = this_player();
	file = load_object(LOADED_DIR+this_object()->query("question"));

	if( wizardp(me) && me->query("id") != "release" )
		return notify_fail("�Ův����ѻP�O�����ʡC\n");
	if( !this_object()->query("question") )
		return notify_fail("�o�̳��S�����D�A�A��˥h���r�I\n");

	if( member_array(me->query("id") , id) != -1 ) return notify_fail("�u�@�H�����D�G�A�b�o�q���D�ɶ��w�g���L���D�F�A�е���U�@�����D�ɶ��C\n");

	id += ({ me->query("id") });

	message_vision(HIY"$N�⵪�סy"+ans+"�z�g�b���D�ȤW�A�M��浹�u�@�H���C\n"NOR, me);
	message_vision("\n�u�@�H�����W��$N�ֹﵪ��......\n\n", me);

	if( ans != file->query_answer() )
	{
		message_vision(HIR"�u�@�H�����D�G$N�����׬O�����I\n"NOR, me);
		return 1;
	} else {
		if( DATA_D->delete_question(this_object()->query("question")) == 1)
		{
			message_vision(HIY"�u�@�H�����D�G���ߡA����F�I$N�o��F�@���C\n"NOR, me);
			me->add("game/moon_question", 1);
			CHANNEL_D->do_channel(this_object(), "rumor", "���� "+me->name()+" �����O���D�ءC");
		} else {
			message_vision(HIR"�u�@�H�����D�G�o�D�w���H�����F�A�o�ӵ��פ���p��C\n"NOR, me);
		}

		this_object()->delete("question");
		DATA_D->show_question(this_object());
//		write("\n�s���D�ج��G\n\n"+this_object()->show_question()+"\n");
		create();
		renew();
		return 1;
	}

	return 1;
}

string show_question()
{
	object file;
	object room = this_object();

	if( !room->query("question") )
	{
		DATA_D->show_question(room);
		if( !room->query("question") )
                        return HIW"�D�w�w�S�D�ءA�h�¤j�a�ѥ[�O���C���C\n"NOR;
	}

	file = load_object(LOADED_DIR+room->query("question"));

	return HIW""+file->query_question()+"\n"NOR;
}

void reset()
{
	return;
}

int no_ask(string arg)
{
	return notify_fail("���T��@�����ΥX�{�A�o�̸T�� Tell �P say �C\n");
}

void renew()
{
	remove_call_out("renew");

	if( !this_object()->query("question") ) return;

	id = ({ });
	CHANNEL_D->do_channel(this_object(), "rumor", "�s���O���D�ج��G"+this_object()->show_question()+"");
	CHANNEL_D->do_channel(this_object(), "rumor", "�o�`���D�ɶ��{�b�}�l�A��������A�Фj�a�֨ӿ��D�ѻP�C");

	call_out("renew", 300);
	return;
}
