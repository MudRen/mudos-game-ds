// Modify with AreaMaker1.0
// Room23.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����k�|�P�����F��������C�F��O�@�ʤj�_��A��F�W�٦�
�Ǥp���I�ʨӰʥh�A�A����@�ݡA�~�o�{�O�\�h�¿��ƥ��b���Ԫ��u
�@�ۡC
LONG
	);
	set("exits", ([
		"north": __DIR__"room13",
		"south": __DIR__"room33",
		"west": __DIR__"room22",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

