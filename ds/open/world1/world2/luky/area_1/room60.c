// Modify with AreaMaker1.0
// Room60.c

inherit ROOM;

void create()
{
	set("short","�j���");
	set("long", @LONG
�o�̬O�@���j���C�o�̰��F�@�j������a���~�A�S������S�O
���F��C�D�n���L���q�|�P�j�ӡA���Aı�o�ΪA�����I�Q��ı�C
LONG
	);
	set("exits", ([
		"south": __DIR__"room70",
		"west": __DIR__"room59",
		"northwest": __DIR__"room49",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}

