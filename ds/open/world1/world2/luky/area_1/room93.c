// Modify with AreaMaker1.0
// Room93.c

inherit ROOM;

void create()
{
	set("short","��`");
	set("long", @LONG
�A����o�̤@���p�ߤF�@���C�o�̥|�B���O�d�סA��M�]�֤��F
�H�����S���ЩU��  �a�W�]�����㦳�I�ơA�A�̦n�٬O���C�@�I�a�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room83",
		"east": __DIR__"room94",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

