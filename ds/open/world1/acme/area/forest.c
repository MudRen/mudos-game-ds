// Room: /u/a/acme/area/forest.c

inherit ROOM;

void create()
{
	set("short", "�˪L");
	set("long", @LONG
�A�����b��������A�|�P���j��A���q�J���A���ѽ��šA�����Ӯg��
�i�ӡA���U�@���A�uı�����t�t���A�O�Hı�o���Ѳ��W�����O�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"forest1",
]));
        set("objects",([
           __DIR__"npc/sbear" : 3,
        ]) );
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
