// Modify with AreaMaker1.0
// Room88.c

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�@���i�o�̧A�N�ݨ�o�̦��\�h�������J�C�����٦��@�ǥi�R��
�u��A�@�ݨ�A����K�p��F�a�}�̡C�F�䦳�@�y�p�s�C�A�s�C�W
���X�Ӥp�}�A�i��O�@�Ǥp�ʪ����ۡC
LONG
	);
	set("exits", ([
		"north": __DIR__"room78",
		"west": __DIR__"room87",
		"northeast": __DIR__"room79",
	]));
	set("hide_exits", ([
		"south": __DIR__"room98",
 	]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}

