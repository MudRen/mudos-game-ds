// Room: /u/b/bennyng/area/room29.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c�J�f");
	set("long", @LONG
�o�̳Q�@�h���ժ����ҥ]��A�|�B���I�@���A�u���@�Ǧu�æu�ۡA
�A�P��X�������Ʊ��o�͡A���A���N�����Y���A�ϩ��|���i�@�����k���D
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room30",
  "west" : __DIR__"room28",
]));
        set("objects", ([
  __DIR__"npc/guard.c":2,
]));
    set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
