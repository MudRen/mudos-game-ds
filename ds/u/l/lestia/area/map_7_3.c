// Room: /u/l/lestia/area/map_7_3.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�����j��");
	set("long", @LONG

�A�����b�@�Ӹ��C�i�P�W�¬Ӯc�������j�����W�A�a�W�Q�۬������j�a
��A���M�o�̨S���Ӯc�������Y�ª���^�A���]���ۤ@�ѥO�H�¿p���𮧡A
�j����讥�^�ۤ@�L�����W�������A�J�o�ݮݦp�͡A�ϩ����u�H�@�ˡA����
�U�誺�Ӯv�ȤW���ۤ@�쯫���Y�Ԫ��ѤH�A�ݰ_�ӻᦳ���Y�A���G�L�N�O�{
���F�۱Ъ��ХD�a�A��ǥi�H�q���ѱЮ{���������U�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_4",
  "north" : __DIR__"map_6_3",
  "west" : __DIR__"map_7_2",
  "south" : __DIR__"map_8_3",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
