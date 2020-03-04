inherit ROOM;

void create()
{
	set("short", "無相法環正中央");
	set("long", @LONG
你現在正站在一朵巨大蓮花圖案的中央，而這個圖案被畫在一個
圓形的平台之上。這個平台離地不高，看來依大俠你的能力，輕輕鬆
鬆就能安全的躍下。你看了看四周圍，發現兩旁的牆壁是弧形的，上
頭刻滿了佛經，充滿了莊嚴感。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"cir7",
  		"south" : __DIR__"cir17",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
