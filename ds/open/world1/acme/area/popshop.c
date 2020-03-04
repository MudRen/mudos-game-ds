// Room: /u/a/acme/area/popshop.c

inherit ROOM;

void create()
{
	set("short", "㊣當舖㊣");
     set("light",1);
	set("long", @LONG
這裡是一間當鋪，你可以看到在門口的兩側，寫著『公平交易，童
叟無欺』八個金漆大字，黑黝的櫃檯前放了個純金的算盤，只見掌櫃的
正細心的算著帳冊，嘴角猶自笑著。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wynd",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duan" : 1,
]));
       set("room_type","shop");        //當鋪.跳蚤市場(買賣皆可)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
