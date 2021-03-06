// Room: /u/a/alickyuen/area/dr17.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這�堿O三樓的東邊，一條寬闊的走廊。你看見經常有一些護士或醫生
在這走來走去，又或者是一些病人走了出來散步。另外你在這看到走廊的
二旁有一些門，是用來通往病房的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr16",
  "east" : __DIR__"dr18",
"north" : __DIR__"dr22",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "門" : "這是一道會自動開的門。\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" ) tell_object(me,"當你正想走去開那扇門時，門突然自動打開了，原來是一扇《自動門》。\n");
        return ::valid_leave(me, dir);
}

