// �����s�ĥ|�h

inherit ROOM;

void create()
{
	set("short", "�p�Ŧa�W");
	set("long", @LONG
�A�{�b�b�@�Ӥp�Ŧa�W�A�b�A�����e���@�Ӥp�}�A���G�i�H�i�h��
���h�����A�o�̦��I���m�A���ǳ��~�b�樫�A���O�Q�����w���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"4f2.c",
  "in" : __DIR__"hole2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
