inherit ROOM;
void create()
{
        set("short", "扶桑浪人營入口");
        set("light",1);
        set("long", @LONG
這裡是扶桑浪人營的入口，平時都會有兩三個守衛在這裡守護以防萬一
，你往裡面瞄了一下，發現裡面到處都是帳篷，顯然是武士們棲息之地
你也聽到了刀劍摩擦的聲音！可見這裡不是一個普通的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_2",
  ]));
    set("objects",([
       __DIR__"npc/ching" : 1,
       __DIR__"npc/guard" : 2,
    ]) );
         set("outdoors","land");
         set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
