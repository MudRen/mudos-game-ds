// Room: /u/s/superbug/train/a-24.c

inherit ROOM;

void create()
{
	set("short", "�G���A����");
	set("long", @LONG
�o�O�@���H��G���A���X�W�����A�h���ϸ̤j�������H���O��o�̨�
�R��A�A�ѩ�~�N�[���A���Ӫ����W�w�g�Q�v����ѡA�C�C���j�a���ߺD
�H�u�G���v�Ӻ٩I���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"a-10.c",
]));
set("objects", ([
__DIR__"npc/seller3.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
