inherit ROOM;
void create()
{
	set("short", "�¦�p�ж�");
	set("long", @LONG

�@�Ӥ����W���ж��A�̭��R���F�����W���𮧡A�O�H����ı�o�i��
�A���~�O�@���¦⪺�p���A�o�̦��@�ǤH�s���ӡA�b�o���@�Ӥp�c�b�c
�檫�~�C
LONG
	);
	set("exits", ([
  "out"   : __DIR__"outroad4.c",
  "north" : __DIR__"temproom1.c",
]));
	set("objects",([
  __DIR__"npc/shopman.c": 1,
]));
	set("no_fight",1);
	set("no_cast",1);
	set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
