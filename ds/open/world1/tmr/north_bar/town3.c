// Room: /open/world1/tmr/north_bar/town3.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
����A�L��A�o�̶��}�ɡA�o�{�\�h�s�_�����N�A���䪺��
�l�B�ؿv���Q���S�O�A���ǩЫάݰ_�ӫܷs�A�����Ǭݰ_�ӫo�Q
���}�¡A�s�Τ��Y����������Q�γE���F�C����]�\�h���񪺤p
�Ĥl�b�o�̪��A�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town2",
  "north" : __DIR__"town4",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
