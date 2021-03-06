// Room: /u/s/suez/tsing-yu/map_6_7.c

inherit ROOM;

void create()
{
	set("short", "廣場東北角");
	set("long", @LONG
    或許是因為接近衙門，這裡比起東北方的巷子內平靜了許多，偶而有
些乞丐在這裡乞討，但是多半沒什麼人理會。幾個官兵正在處理一旁凍死
的屍體，而南方依稀聽見那些玩樂未盡的公子摟著青樓女子嘻笑的聲音。
一位商人在錢莊領了錢後，拿了一些給官兵請他們好好將屍體埋了，幾個
婦人則是帶著小孩匆匆走過，像是害怕什麼似的。只有一個不知誰家的小
女孩，拉脫母親的手，走了過來，將手上的鮮花輕輕的放在屍體的身上，
為這異鄉孤魂留下最後的慰藉。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"map_7_6",
  "west" : __DIR__"map_6_6",
  "south" : __DIR__"map_7_7",
  "northeast" : __DIR__"map_5_8",
]));

	setup();
	replace_program(ROOM);
}
