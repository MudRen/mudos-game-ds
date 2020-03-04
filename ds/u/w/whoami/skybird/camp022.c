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
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp021",
  "south" : __DIR__"camp023",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

