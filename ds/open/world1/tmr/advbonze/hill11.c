// Room: /open/world1/tmr/advbonze/hill11.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A���G��
���@�q���������o���A���F�_����V�����B�����p���a�A���G�i
�ѤW�s���H�p�ͤ@�U�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hill12",
  "southdown" : __DIR__"hill10",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
