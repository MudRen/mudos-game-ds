// Room: /u/d/donhow/workroom.c

inherit ROOM;

void create()
{
	set("short", "夢殿學園");
	set("long", @LONG
這裡正是頂頂有名的夢殿的校門口，一個傳說的起源之地。校門
口是歐式的古代建築，整座夢殿似乎是有著女神守護著般的閃閃發光
，門口上掛著學園的門牌(table)，發著耀眼且奪目的白光。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "longya" : "/u/l/longya/workroom",
  "north" : __DIR__"area/a3",
  "future" : "/open/world3/meetroom",
  "wiz" : "/d/wiz/hall1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "table" : "這是夢殿學園的門牌，由一塊銀色的石頭所刻製而成上面寫了幾個古文(words)",
  "words" : "你試著去讀出這行古文字，上面寫著'  夢   殿  '，'柔光提筆'....這幾個字",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
