inherit ROOM;
void create()
{
	set("short", "小村入口");
	set("long", @LONG
這裡是一個寧靜小村的入口，這裡有一些蟲鳥的鳴叫聲，令你有點
感覺清靜，而且這裡有著帝王後花園般的小河和流水經過，豈不令人樂
乎？西邊是森林你所來到的地方，而往東方則是往修德村裡面走去，這
裡似乎有一些草叢。
LONG
	);
	set("exits", ([
  "west" : __DIR__"forest4",
  "east" : __DIR__"village",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
