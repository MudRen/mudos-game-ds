#include <room.h>
inherit ROOM;
void create()
{
 set("short","���s�y�����W");
 set("long",@LONG
�o�䦳�@���p���], �δ׬[�f��, �γ\�A�i�H�i�h�ݬ�,
�𮧥�. ���䦳�Ǧ���H�h, �]�\�A�i�H�M�L�̥�ť�@�U
�ݳo�O����? �p�G�A���O���n, �K��ݨ�s�����G���@�ɫ�
�v��.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown2",
                "south":__DIR__"mountdown4",
                "southeast":__DIR__"mountdown5",
		"northeast":__DIR__"jungle1",]));
 set("no_clean_up", 0);
 setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me;
	me=this_player();
	if (arg != "���]" && arg != "�p���]") tell_object(me,"�A�n�i�h����?\n");
	else 
	{
		message_vision("$N�ȶ}�F���]������, ���i���]���𮧡C\n",me);
		me->move(__DIR__"rest_tea");
		return 1;
	}
}
