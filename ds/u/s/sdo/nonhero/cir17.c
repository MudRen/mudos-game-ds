inherit ROOM;

void create()
{
	set("short", "�L�۪k���q�D");
	set("long", @LONG
�ݵ���W�h�S�K���g��A�A���߸̶}�l�Pı��@�Ǥ��ӹ�l�A��
����h���g��s���O���F����H�ר��H���]�H�٬O�b�O�@�Ǥ���F��
�H�A�h�ۤ@�������w���߱��~�򩹫e���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"south" : __DIR__"cir21",
  		"north" : __DIR__"cir12",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
