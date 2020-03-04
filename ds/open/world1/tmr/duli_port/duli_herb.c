// File: /d/duli_port/duli_herb.c
// Updated by tmr (Sat Mar  9 06:48:57 2002)

inherit ROOM;

void create()
{
	  set("short", "藥草專賣店");
	  set("long", @LONG
這裡是一間頗為擁擠的藥草店，屋子裡雜七雜八的放滿了藥物，隨便
走動都會踢到東西，店內藥櫃子上的抽屜也有好幾個是開著，似乎是店主
人忙到忘記關起起了。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"west" : __DIR__"map_18_16",
]));
        set("objects",([
        __DIR__"npc/seller":1,
        ]));


	setup();
	  replace_program(ROOM);
}
