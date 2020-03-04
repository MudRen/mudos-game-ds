// File: /d/duli_village/sea_room6.c
// Updated by tmr (Wed May  8 22:47:19 2002)

inherit ROOM;

void create()
{
	  set("short", "大海洋底下");
	  set("long", @LONG
你正潛游在一片水藍藍的海洋底下，微微波動的海流正輕拂過你的身
體，一道明亮的光芒透過海面直射下來，讓你勉強能瞧見四周環境，一群
群不知名的魚兒正在海底另一角覓食、游動。
LONG
	  );
	  set("exits", ([ /* 1 element(s) */
	"east" : __DIR__"sea_room4",
]));

	setup();
	  replace_program(ROOM);
}
