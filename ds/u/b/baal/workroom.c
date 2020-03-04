#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"索思受詛咒的城堡入口"NOR);

 set("long",@LONG
這裡是索思受詛咒的城堡入口, 你前面豎立著一扇鐵門, 鐵門上刻著
黑暗之后塔克西絲的印記, 大開的鐵門不停的洩出噬骨的寒氣, 幾個信奉
黑暗之后塔克西絲的司祭才準配戴的五頭龍護身符被零亂的丟在地上, 地
上到處是火燒過的焦黑痕跡, 一股陰暗的氣息罩著這座城堡, 令人不寒而
慄...
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "enter":"/u/b/baal/workroom2",
                "ptstart":"/open/world1/tmr/area/hotel",
    ]));
        set("no_fight", 1);
        set("objects", ([ 
          __DIR__"weapon/darkamulet" : 5,
        ]));
        set("outdoors","land");
        set("light",1);
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

