// Room: /u/s/superbug/train/5.c

inherit ROOM;

void create()
{
	set("short", "管理處");
	set("long", @LONG
這裡是管理處的大門，裡面的員工都早已不在，從門上的灰塵來看已
有一陣子沒有人開啟過了，從窗戶望進去，裡面的機器似乎還在運作著，
當你想進去看看時，才發現門被鎖了起來。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "大門" : "一扇佈滿灰塵並且被鎖起來的門，你需要一把鑰匙來開啟。\n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"3.c",
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
