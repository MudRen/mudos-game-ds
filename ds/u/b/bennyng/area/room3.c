// Room: /u/b/bennyng/area/room3.c

inherit ROOM;

void create()
{
	set("short", "���Y�q�D");
	set("long", @LONG
�M�|�Ӧu�äj�Ԥ@������A�A����ӳo�@�����Y�̡C�A�ݪ�����䪺
��W�����Q�G�Ӷ������h���e���C���A�oı��@��ܩ_�Ǫ��ơA�C�j�T�T
�e���A�����N���ۤ@�T�ܩ�H���o�e�A�쩳���O�N��ۤ���O�H
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room2",
  "south" : __DIR__"room4",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
