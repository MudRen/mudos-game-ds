// Room: /u/t/tmr/area/round4.c

inherit ROOM;

void create()
{
	set("short", "�ʪ��O");
	set("long", @LONG
�o�O����Һة�¤Ѵ�`�����O���A�s�F�ʤءA���ٵ����A�M�ӦW��
�_�c�C���вM���A���u�ժڡF���e�����A���¿@���C���b���B�A����Y��
�F���P�B�٥ɰ��A�d�����ѭ��A�ɾ�F�F����A�����T�T����F���Ī�
���֤�A�ۺh����L���C�����ƭ���]�A�ܻT�v�v�H���F�������Y�A��p
���A�F¸�A�����A�I�󭷥��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"round1",
  "north" : __DIR__"round1",
  "west" : __DIR__"round1",
  "east" : __DIR__"round1",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int k=1;

int do_search(string arg)
{
	object me,ob;
	me=this_player();
	if (arg!="�ʪ��O") return 0;
	if(k==1)
	{
	message_vision("$N�����b�ʪ��O�����M�F�X�M�A���G��줰��F�_�Ყ�c�I\n",me);
	ob=new(__DIR__"npc/obj/flower");
	ob->move(me);
	k=0;
	}
	else
	{
	message_vision("$N�����b�ʪ��O�F½½�B����A���F�@�Y�j���C\n",me);
	}
	return 1;
}