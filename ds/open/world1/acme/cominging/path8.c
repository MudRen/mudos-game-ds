inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A�����b���D�W�A�b�o�䦳�\�\�h�h���H�s�A���G�O���Ǫ��Ʊ��A
�F��O��W�r���n�Ҧb�A��F�СA�b�����@�ӷG�䪺��F�x�b���ԡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"house5",
  "west" : __DIR__"path2",
  "north" : __DIR__"path7",
  "south" : __DIR__"path9",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
