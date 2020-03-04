inherit ROOM;

void create()
{
        set("short", "小徑");
        set("long", @LONG
這裡路愈走愈小，周圍的野草；幾近將小路給淹沒了，這到處都是
高高大大的樹，顯然是人煙稀少，隱約可見東邊和北邊有一條小徑。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pathway4",
  "north" : __DIR__"pathway6",
  "east" : __DIR__"pathway7",
]));
        set("objects",([
        __DIR__"npc/dog.c" : 2,
]) );
        set("no_clean_up", 0);
         set("outdoors","land");

        setup();
        replace_program(ROOM);
}
