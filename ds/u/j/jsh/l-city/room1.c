inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room2",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/guard-lv25" : 4,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

