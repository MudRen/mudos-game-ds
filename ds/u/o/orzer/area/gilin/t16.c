inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經蠻接近森林的最東側，寒氣沒有絲毫的減弱，東邊似乎有
道小山澗的樣子，而西北則是可以繼續前進，感覺似乎有一道人影飄過
眼前，卻又很像是錯覺，讓你一時有些驚愕。
LONG
        );
        set("exits", ([
  "east" : __DIR__"t25",
  "northwest" : __DIR__"t17",
  "southwest" : __DIR__"t15",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











