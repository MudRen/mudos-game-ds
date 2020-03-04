// Room: /u/a/acme/area/passage3.c

inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�j���~�����Y�A��e�F��V�A���Y���\��F�G�Ƭ֮�A�@��
�˹��A��W�ٱ��F�X�T�W�a�e�@�A���H�@�صΪA���Pı�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room2",
  "west" : __DIR__"passage2",
  "south" : __DIR__"door2",
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
