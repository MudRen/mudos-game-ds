inherit ROOM;
void create()
{
	set("short", "�¦�p�ж�");
	set("long", @LONG

�@�Ӥ����W���ж��A�̭��R���F�����W���𮧡A�O�H����ı�o�i��
�A���~�O�@���¦⪺�p���A�o�̦��@�ǤH�s���ӡA�A���M�ݨ�@�Ӽ��x
�����աA��ӬO�e�����������k�ϡC

LONG
	);
	set("exits", ([
  "out"   : __DIR__"wildroad4.c",
  "north" : __DIR__"temproom1.c",
]));
	set("objects",([
  __DIR__"npc/master.c": 1,
]));
	set("no_cast",1);
	set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
