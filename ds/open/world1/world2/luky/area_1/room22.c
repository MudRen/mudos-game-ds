// Modify with AreaMaker1.0
// Room22.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L�̡A�o�̪����������C�@�ǡC�L�����j�A�𸭵o
�X�@�}�F�F�F���n���C�o�̪��۵M���[�Q���״I�A�{�b�w�g�����ݨ�
�o��۵M������F�C
LONG
	);
	set("exits", ([
	        "south": __DIR__"room32",
		"north": __DIR__"room12",
		"east": __DIR__"room23",
		"west": __DIR__"room21",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

