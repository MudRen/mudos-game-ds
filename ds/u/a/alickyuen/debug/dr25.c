// Room: /u/a/alickyuen/area/dr25.c
// ��long and exits
inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IComputer-room");
	set("long", @LONG
�o���q���Ǧh�H���O�A�@���H�b�ƶ��A�Q�i���W�ǲ߯Z�A���{�b��n
�q���ǼW�K�F�@�Ƿs�]�Ʀӭ��s�}��A�ҥH�A�ݨ즳�@�ǤH���@�Цa���F�A
�������@�ǤH���ߤ����A�Ʊ�i���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dr16",
"enter" : __DIR__"dr26", //�[�X�f
]));
set("objects", ([
__DIR__"npc/wnurse" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
