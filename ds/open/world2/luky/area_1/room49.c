// Modify with AreaMaker1.0
// Room49.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̪���L�㪺����}���A���G�A�w����F��L����t�C�A�i�H
�ܲM���ݨ�b�A�����䦳�@�����Z���p�|�C�A�]�i�H�ݨ��ƾ����
��ݥߦb�p�|��ǡC�F�䪺��줴�M���o�ܭZ���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room39",
		"south": __DIR__"room59",
		"southeast": __DIR__"room60",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

