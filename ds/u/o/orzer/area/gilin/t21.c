inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你來到了森林的內側，這裡再往前進似乎更加陰寒，也讓你不太有
辦法平靜的前進，卻又不知道該怎麼辦才好，也只好勉力壓下不安的情
緒，這裡的涼氣不斷傳來。
LONG
        );
        set("exits", ([
  "west" : __DIR__"t22",
  "north" : __DIR__"t19",
   ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









