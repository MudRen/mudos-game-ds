// Room: /u/a/acme/area/plaza3.c

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是天城的東邊廣場，你可以看到許多小孩在此嘻戲，這裡相當
的寬廣，讓人能在此放開心胸，在路旁有個長凳，上面放了個茶壺，茶
壺上貼了一張紅紙，上面寫著「奉茶」，應是給趕路的人解渴的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"plaza1",
  "east" : __DIR__"street3",
]));
    set("objects",([
       __DIR__"npc/child" : 3,
          __DIR__"obj/teapot" : 1,
    ]));
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
	replace_program(ROOM);
}
