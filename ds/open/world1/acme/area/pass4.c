// Room: /u/a/acme/area/pass4.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�@���T�򤣥����s���A���ӥO�H�}���o�n�A�_��O�@��L�ڪ�
�j���A�����۪F�@�h�A�����i���ѫ��������A��n��i���}�Ѥs�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lea14",
  "east" : __DIR__"pass3",
  "southwest" : __DIR__"pass5",
]));
      set("objects",([
         __DIR__"npc/traveler2.c" : 3,
      ]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
