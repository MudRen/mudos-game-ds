inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A���B�b���D�W�A�ﭱ�]�O�@�������ж��A���G�o�̬O�@�Ӥj�J��
�H�o�̦��\�h���q�D�A���ǥs�H����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path2",
  "west" : __DIR__"house2",
  "north" : __DIR__"path4",
  "south" : __DIR__"path6",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
