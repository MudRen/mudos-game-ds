// Room3.c

inherit ROOM;

void create()
{
	set("short","��L��");
	set("long", @LONG
�o�̤]�O�@�j������L�A����X�G��A�����\�ٰ��C�_��M�F��
���O�~�k���s���A�H�ܩ�A�L�k�~��e�i�C�L�L�����}�}���j�ۡA�O
�H�P��D�`�ΪA�C
LONG
	);
	set("exits", ([
		"south": __DIR__"room13",
		"west": __DIR__"room2",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

