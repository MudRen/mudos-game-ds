// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "客棧二樓");
	set("long",@LONG 
這裡是個「回」字型的走廊，往下看可以看到客棧的大廳，一個水缸
放在樓梯旁，是給客人洗手洗臉用的。而每個客房的門口都有兩三株玉蘭
，發出淡淡的香味飄滿了四周，可以看出這裡的主人十分細心打理客棧的
事情。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "eastdown" : __DIR__"hotel_step",
               "west": __DIR__"hotel_room1",
            "south": __DIR__"hotel_room2",
            "north": __DIR__"hotel_room3",

              ]));
        set("objects",([
              __DIR__"npc/drooler_wm" : 1,
              ]) );

         set("item_desc",([
        "水缸":"一個素燒的大水缸，裡面裝滿了水。水缸旁掛了一個勺子。\n",
        "玉蘭":"白色的玉蘭，是作者亂想出來的東西，不一定存在。\n",
         ]));

	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}