// Modify with AreaMaker1.0
// Room87.c

inherit ROOM;

void create()
{
	set("short","��L��");
	set("long", @LONG
�o�̦��ǰʪ�������  ���G�����ֳ��~�X�S�󦹡C�]���ǡA�]��
�_�䦳�Ӥp����A�F��O�ӯ��A����S�O��L�A�U�إͺA�귽�״I
�A�ʪ��̦۵M�|�I�B�ަ�e�Ӧ��B�V���F�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room88",
		"west": __DIR__"room86",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

