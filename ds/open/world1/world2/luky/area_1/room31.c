// Modify with AreaMaker1.0
// Room31.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@�K����L�̡A�o�̪������A�����\�o�򰪡C�n�観
�ʥ��j���_��A�٫��U�F�\�h�S���S�K����ڡA�L�����ɶǨӳ��~�D
���ҵo�X���������n���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room21",
		"east": __DIR__"room32",
		"southeast": __DIR__"room42",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider0" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

