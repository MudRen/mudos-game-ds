// Room: /d/xiangyang/walls8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�n���Y");
	set("long", @LONG
�o�̬O�������n���Y�C�@�ǧ��L���b���Y���ޡA�@�Ӥ��N
���b�o��t�d�����U�ئu�����ơA�@�Ǥ}�b�⥿���}�f�b��n
�۫��U�����R�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northeast" : __DIR__"walle7",
		"westdown"  : __DIR__"walls6",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -460);
	set("coor/y", -550);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}