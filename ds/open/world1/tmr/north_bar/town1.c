// Room: /open/world1/tmr/north_bar/town1.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-���f");
	set("long", @LONG
�Ө�o�̡A���e�@��A���@�Ӥj�j���Φˤl�����j���A�̭�
���G�O�ӳ����C��a�Фl���γ������Τj���f�ءA���]���u��
�ν_���f�������q���СC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/world1/whoami/birdarea/en76",
  "north" : __DIR__"town2",
]));
	set("outdoors", "land");
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
