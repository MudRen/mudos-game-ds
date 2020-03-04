// Room: /open/world1/acme/area/f4.c

inherit ROOM;

void create()
{
	set("short", "��a");
	set("long", @LONG
�b�o���L���A���X�{�F�o�B�@�𥼥ͤ��a�A�b�_�䦳�Ӥs�}�A��
�G�O���~���_�ޡA�M�Ӧa�W�o�������A��^�Q�����ԡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"f3",
  "north" : __DIR__"f5",
]));
     set("outdoors","land");
set("objects", ([ 
  __DIR__"npc/bandit" : 3,
  __DIR__"npc/k_bandit" : 1,
]) );

	setup();
	replace_program(ROOM);
}
