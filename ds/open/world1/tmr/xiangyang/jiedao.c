// Room: /d/xiangyang/jiedao.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̬O�������������H���~��ϡC��D��ǬO�@�ǻ��ت�
��v�A���M�������g�ԶáA���٦��\�h�����H�S�h���A����u
�������X���X�O�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"minju1",
		"west"  : __DIR__"minju2",
		"north" : __DIR__"eastjie2",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 2,
	]));
	set("coor/x", -480);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

