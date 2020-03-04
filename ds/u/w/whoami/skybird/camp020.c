#include <ansi.h>
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
  "north" : __DIR__"camp019",
  "south" : __DIR__"camp021",
  "east" : __DIR__"camp024",
]));
 set("objects", ([
       __DIR__"mob/general_guard" : 2+random(3),
                ]));

        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("general guard",environment(me)) &&  ( (dir=="east") ))
       {
        message_vision(YEL"將軍護衛說﹕元帥大帳豈是$N能進去的！\n"NOR,me);
       } 
    else return ::valid_leave(me,dir);

}

