// Room: /d/xiangyang/wallw7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�諰�Y");
	set("long", @LONG
�o�̬O�������諰�Y�C�@�ǧ��L���b���Y���ޡA�@�Ӥ��N
���b�o��t�d�����U�ئu�����ơA�@�Ǥ}�b�⥿���}�f�b��n
�۫��U�����R�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northeast" : __DIR__"walln8",
		"southdown" : __DIR__"wallw5",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -550);
	set("coor/y", -460);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}