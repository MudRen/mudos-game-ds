inherit ROOM;

void create()
{
        set("short", "固山寨");
        set("long", @LONG
看到營中士兵那鮮明的盔甲和手上閃著寒光的刀劍，你不由
心中暗嘆：如此鐵軍，難怪能縱橫無敵。再想到久經安逸的天朝
軍，你不由搖了搖頭。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"camp020",
  "south" : __DIR__"camp022",
  "west" : __DIR__"camp017",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

