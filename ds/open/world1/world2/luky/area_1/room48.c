// Modify with AreaMaker1.0
// Room48.c

inherit ROOM;

void create()
{
	set("short","��L�p�|");
	set("long", @LONG
�A�����b��L�p�|�W, ��ǳ������F�����W����, ��ƪ���V��
��@���u�a�����C�A�i�H�ݨ�b�A���n�䦳�@�Ӥp����C�q�����W�j
�Ӱ}�}���D��, �ϧA�P��D�`�ξA�C
LONG
	);
	set("exits", ([
		"west": __DIR__"room47",
		"northeast": __DIR__"room39",
		"southeast": __DIR__"room59",
		"northwest": __DIR__"room37",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

