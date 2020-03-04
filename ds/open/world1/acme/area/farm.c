// Room: /u/a/acme/area/farm.c

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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pass3",
  "south" : __DIR__"farm1",
  "southwest" : __DIR__"farm2",
]));
         set("objects",([
            __DIR__"npc/buffalo" : 1,
            __DIR__"npc/sparrow" : 3,
         ]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
