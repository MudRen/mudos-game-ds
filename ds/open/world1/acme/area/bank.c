// Room: /u/a/acme/area/bank.c

inherit ROOM;

void create()
{
	set("short", "萬金錢莊");
     set("light",1);
	set("long", @LONG
這裡是一間錢莊，門口懸著一個大匾額，門側站了護院武師，這間
錢莊就是天城首屈一指有信用的錢莊。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "匾額" : "匾額上面寫著『萬金錢莊』四個黑金大字。\n"]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"street5",
]));
    set("objects",([
        __DIR__"npc/wan" : 1,
             __DIR__"npc/guard" : 3,
    ]) );
          set("room_type","bank");        //銀行錢莊
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

