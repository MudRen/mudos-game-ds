// Room: /u/a/acme/area/farm2.c

inherit ROOM;

void create()
{
	set("short", "�A��");
	set("long", @LONG
�A�����b�ж��p���A���U�|��A�ɬO������誺�A�a�A�Ф����ٴ���
�@�ӽ_��H�A�A�Ф��@����o�o�����]�A�ͮ𽴫k�A�Y�Y�V�a�A�O�A����
ı�o���U�}�B�A�Ӳӫ~���o�p�p���;��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"farm",
  "east" : __DIR__"farm1",
]));
       set("objects",([
             __DIR__"npc/farmer" : 2,
          __DIR__"npc/buffalo" : 2,
       ]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
