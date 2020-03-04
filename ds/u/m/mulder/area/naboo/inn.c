// Room: /u/m/mulder/area/naboo/inn.c

inherit ROOM;

void create()
{
	set("short", "���]");
	set("long", @LONG
�o�̬O�@�����P�Ū����]�A�O�η�M�O������Q�A�٤�@��
��Ϋ~���ѵ���ȡC�q�o�̪��˭׬ݨӡA�A���D�o�̪��]�p�v�@
�w�O�b�t�z�ܦ��W�𪺡C
LONG
	);
    set("no_kill",1);
   set("no_shoot",1);
   set("no_cast",1);
   set("no_exert",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/keeper" : 1,
]));
	set("room_type", "hotel");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road3",
  "enter" : __DIR__"inn2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
