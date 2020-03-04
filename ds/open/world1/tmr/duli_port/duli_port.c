// File: /d/duli_port/duli_port.c
// Updated by tmr (Wed Feb 27 21:10:52 2002)

inherit ROOM;

void create()
{
	  set("short", "杜尼港-登船處");
	  set("long", @LONG
你正站在杜尼港口的出海碼頭，一眼望去，滿滿都是人潮，一波一波
地想要擠上下一班船，空氣夾雜著吵鬧、大聲交談和海風襲來的一股海洋
的味道。一條往東的道路，通往杜尼港較繁盛的地段。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"east" : __DIR__"map_6_1",
]));
        set("objects",([
               "/d/batogiya_dtl/npc/ha-biao" : 1,
        ]));
           set("outdoors","land");
           set("no_fight",1);
               set("where","duli_port");

	setup();
	  replace_program(ROOM);
}
