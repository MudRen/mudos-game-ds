// Room: /d/xiangyang/xuetang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ǰ�");
	set("long", @LONG
�o�̬O�������ǰ�A�����L�b�A�@�Ф��V�C�@������Y��
���ѥ��ͧ��b�Ӯv�ȤW���ǡC�b�L���ⰼ�����F�D�Ǫ��ǥ͡C
�@�i�j�N�s�M���Ѯש�b�ѥ��ͪ��e���A�פW�\�۴X��½�}�F
���u�ˮ��y�C
LONG );
	set("exits", ([
		"west" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/laoxiansheng" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}