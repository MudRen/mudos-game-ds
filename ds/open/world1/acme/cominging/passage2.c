inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�j���~�����Y�A��e�F��V�A���Y���\��F�G�Ƭ֮�A�@��
�˹��A�_�����ߵ۸Ū����j���A�Q�������Y�B�����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"passage3",
  "west" : __DIR__"passage1",
  "north" : __DIR__"bigdoor",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
