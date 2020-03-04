// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "秋水");
	set("long",@LONG 
秋水時至，百川灌河，你一踏入這裡，就聽到潺潺水聲，除了遠方白
練般的瀑布，窗外也以竹管引水入室，涓涓細流就在你的腳下，一個小水
車在你身邊轉個不停，而床邊燃燒的香，使濕氣不會那麼的重，也使你覺
得舒適典雅。
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "south" : __DIR__"hotel_two",

              ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}