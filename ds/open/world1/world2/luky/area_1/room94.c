// Modify with AreaMaker1.0
// Room94.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@����L���C�o�̦]���a��ҥH���Ǽ���C�A�ݨ����
���Ӥp�ӸO�A�W�����r�w�g�ҽk���M�F�A�u��j�j�ݨ�u�����S�s�v
�|�Ӧr�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room84",
		"west": __DIR__"room93",
		"northeast": __DIR__"room85",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider2" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

