// Modify with AreaMaker1.0
// Room61.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","��`");
	set("long", @LONG
�@�Ө�F�o�̡A�A���W�N�Q���R���̲����`�`���l�ަ�F�C�M
�����򭱦p��l�@��L�X�Ѧ�A����W���ӷ|������Z�y��b�䤤�C
�A�٬ݨ�a�W���\�h�~��Q�����ƪ��Z�Z�ۡA�u�Q�a�^�h������C
LONG
	);
	set("exits", ([
		"east": __DIR__"room62",
		"west": SHENGSAN2"aovandis/out046",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

