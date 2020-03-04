#include <ansi.h>
inherit ROOM;

#define TARGET_ROOM __DIR__"book_hole.c"

void create()
{
	set("short", "�¥۰}�k");
	set("long", @LONG
�o�̫D�`���_�ǡA�|�P�⭱�O�j�F�z�A�@���L�h�O���j���s�A����o
�O�j���C�P��äC�K�V�����X�ʭӦǽŦ⪺����(stone)�A���O�۵M�Φ���
�S���O���H�h�Ӫ��C
LONG);

	set("exits", ([
//	    "west" : __DIR__"plane00",
	]));
	set("item_desc", ([
		"stone" : "�o�̦��@���S�O�j�����Y�A���᭱�٦����۸O�A\n"+
			  "���Q�o���j�۾פF�A�ݤ����W�����Ǥ���F��C\n",
	]));

	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_look", "look");
}

int do_push(string arg)
{
	object me, room;

	me = this_player();
	room = this_object();
	if( !arg ) return 0;
	if( (int)room->query_temp("stone_pushed") )
		return notify_fail("�A���o����w�S�Ʊ����Y�H\n");
	if (arg == "stone" ){
	if ( me->query("class1") != "�ѱ���" ){
		me->add("hp", -500);
		message_vision(HIR "$N�B��r�O�V���ۤ@���A���G�����S���}���A�ϦӾ_�ˤF�ۤv�C\n" NOR, me);
		me->unconcious();
		return 1;
	}
	if (me->query("ap") < 100 || me->query_str() < 20 ){
		message_vision("$N�B�_�����g �ϫl���F�����ۡA�L�`�O�q�����A�u�n���}�C\n", me);
		me->add("ap", -100);
		return 1;
	}
	else{
	     me->add("ap", -100);
	       message_vision(HIG "$N�餺�u��Ӧ^�B��A�f���@�s�A���x���X�C\n\n"+
				  "�uť�F���@�n�A���۳��M�Q$N���}�F�A�S�X�F�᭱���۸O�C\n" NOR, me);
	       room->set_temp("stone_pushed", 1);
	       call_out("stone_push", 10);
	    }
	}
	return 1;
}

int do_look(string arg)
{
	object me, room;
	me = this_player();
	room = this_object();
	if( !arg ) return 0;
	if( !(int)room->query_temp("stone_pushed") )
		return notify_fail("�j�۶����Y���ݱo���H\n");
		
	if ( me->query("class1") != "�ѱ���" )
		return notify_fail("�A�ݤF�b�ѡA�٬O�����ը��W���g�F�Ǥ���F��C\n");

	tell_object(me, HIB "\n �C�C�C�C�C�C\n"+
			    "���B�D�J�øg�s�}�����D�A���J�M�i�H���}���ۡA\n"+
			    "��w���@�w�άr�\\���A�i��^���ǤH���H�C�i���p\n"+
			    "�����k�i�J�øg�B�C�C�C\n\n"+
			    "                      �r���r�d��\n\n" NOR);	message_vision("$N�n�ۥ۸O�ݤF�b�ѡA�y�W�S�X�Y�������A���$N�}�B��F�X��A���i�å۰�̤����F�C\n", me);
        me->move(TARGET_ROOM);
	tell_object(me, "�A�°����ਫ�F�b�ѡA�o�{�ۤv�w�g���b�s�}���C\n");
	return 1;
}

int stone_push()
{
       object room = this_object();
       if(objectp(room)){
		message("vision", "�F���@�n�A���ۤS�u�^�Ӿצ�F�۸O�C\n", this_object());
		room->delete_temp("stone_pushed");
       }
}
