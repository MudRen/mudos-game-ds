// Room: /u/a/acme/test/stone2.c

inherit ROOM;

void create()
{
	set("short", "���a");
	set("long", @LONG
�o���a���s�A�ȤT�V�����ؼe���@�����_�C�ѥ͸U���A�y�Ƥ��_
�A���B�i���@�G�C
LONG
	);
	set("no_clean_up", 0);
  set("exits", ([ /* sizeof() == 1 */
      "down" : __DIR__"swirl2",
  ]));
       set("objects",([
          __DIR__"npc/stone" : 1,
       ]) );

	setup();
	replace_program(ROOM);
}
