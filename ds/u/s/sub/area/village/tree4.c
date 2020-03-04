// Room: /u/s/sub/area/village/tree4.c

inherit ROOM;

void create()
{
	set("short", "�k��");
	set("long", @LONG
���F�X��ﭷ�ӭ˪��p��~�A�o�̹�b�O�F�L�;��C���r�r�����ۤW
���۷�h�������A���G�D���ۥ��̳Q���I�k���G�P���ΡC�F�_�誺���O��
���@���p���A�n��i�H�쯫�쪺��K�W�C
LONG
	);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"vi01",
  "south" : __DIR__"tree3",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
