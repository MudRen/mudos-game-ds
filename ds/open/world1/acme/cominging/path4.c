inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�o�̬O�@�������D�A�A�b���D������æ���a�a�A���Ǧa��񦳪�c
���A���Ǧu�íʾa������M�M���ڡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"path3",
  "west" : __DIR__"house3",
  "south" : __DIR__"path5",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
