inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�o�̦��@�������ж��A�b�A��������G���Ǥj�x����B�A�ҥH�`�`��
�@�ǩx�L�b���޹���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"path1",
  "west" : __DIR__"house1",
  "north" : __DIR__"path5",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
