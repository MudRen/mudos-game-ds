// Room: /u/l/lestia/area/map_7_6.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�۪O�D��");
	set("long", @LONG

�g�L�]�O�̻٤���A�w�g�i�J�F�۱Ъ��ϰ�F�A���W����H���ɪ��Ϊ�
�ê������ݧA�A���Aı�o���@�ػ�ǲ����Pı�A�A�Q�i��O�]���e��N�O�q
���F�۱Ъ��`�¤F�A�ҥH�~�|���\�h�H�n�ۧA�a�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_7",
  "north" : __DIR__"map_6_6",
  "west" : __DIR__"map_7_5",
  "south" : __DIR__"map_8_6",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
