// �����s�Ĥ@�h�˪L

inherit ROOM;

void create()
{
	set("short", "�����s�Ǥp�˪L");
	set("long", @LONG
�o�̬O�����s�U����@�Ӥp�˪L�A�A�q�s�W�a���U�ӡA���M���b�o
���d�פW�A�u���A���@�Ǫ��~�����b�a�W�A�٬O���I�߰_�Ӫ��n�A����
���@�Υհ��A�����D�O�֪��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"psin_forest2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("inquiry", ([
  "�հ�" : "�@�Υհ�, ������G���i�ȱ�. \n",
  "�ȱ�" : "�@�i�p�ȱ�, ���G���g�ۨǪF�F. \n",
]));
	setup();
}

void init()
{
//	add_action("do_get", "get");
}

int do_get(string arg)
{
	object me = this_player(), paper;
	if( arg == "�ȱ�" )
	{
		paper = new(__DIR__"npc/obj/easy_paper.c");
		paper->move(this_player());
		message_vision("$N�߰_�F�@�i��. \n", me);
		return 1;
	}
	else return 0;
}