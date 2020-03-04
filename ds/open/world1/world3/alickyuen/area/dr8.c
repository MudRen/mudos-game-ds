// Room: /u/a/alickyuen/area/dr8.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Lift");
	set("long", @LONG
你走到來這�堙A只發現除了一些按鈕外便沒有其他東東了。這�媕雩�
就是這間醫院的傳送機，能夠來往醫院各層。
　　你現在在醫院的一樓。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
    "按鈕" : "你看見按鈕上有2和3兩個字。\n",  //錯字 是字不是制 by acme
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr7",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
 add_action("typepush","push");
}
int typepush(string arg)
{
        object me;
        me=this_player();
if(!arg) return notify_fail("你等了一會後，什麼也沒有發生過．\n");
 if(arg=="2")
 {
         message_vision("突然一陣強光，$N在這房間消失了。\n", me);
         me->move(__DIR__"dr9");
         return 1;
 }
 if(arg=="3")
 {
         message_vision("突然一陣強光，$N在這房間消失了。\n", me);
         me->move(__DIR__"dr10");
         return 1;
 }
}
