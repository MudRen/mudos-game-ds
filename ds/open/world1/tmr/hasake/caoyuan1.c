// Room: /open/world1/tmr/hasake/caoyuan1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C�n��M���䳣���n�h�b�O�A��
�F�i�H�ݨ��F�z����t�C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sheep" : 2,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan",
  "east" : __DIR__"caoyuan2",
]));

	setup();
	replace_program(ROOM);
}
