// Room: /u/b/bennyng/area/room50.c

inherit ROOM;

void create()
{
	set("short", "�g��c�~");
	set("long", @LONG
�o�N�O�g��c�᪺���A�|�B��@���A�o�̤@���S���H���z�D�ܩ_
�ǭC�I�I������|�o�ˡH�H�۫H�o�Ӱg�s�Ův�̳������D�A�]���s�ڶ���
�������D�r�I�I�H�H�I�I
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room49",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
