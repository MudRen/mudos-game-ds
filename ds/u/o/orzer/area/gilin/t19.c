inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你在這裡感覺被盯著感覺更加強烈，也因此更加的心情浮動，這樣
下去你覺得不太妙，卻又不知道該怎麼辦才好，也只好勉力壓下不安的
情緒，森林中的寒氣讓人不太舒服。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t18",
  "south" : __DIR__"t21",
  "southeast" : __DIR__"t20",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








