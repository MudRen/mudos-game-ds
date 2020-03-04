inherit ROOM;

void create()
{
        set("short", "旅館");
        set("long", @LONG
這裡是一間豪華的旅館，雖然不是很大但是裝潢、設備都很不錯，如果你覺
得累了可以訂個房休息一下。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room8", 
  "west" : __DIR__"room2", 
  "south": __DIR__"room6",
  "north": __DIR__"room4",]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


