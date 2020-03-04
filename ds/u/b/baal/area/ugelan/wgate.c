#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"幽遮蘭城─城西大門"NOR);
        set("long", @LONG
高聳的城牆圍繞這座諸神眷屬的城市，城牆厚達近十公
尺，是從鬼雪山脈下以魔法巨力開採自厚達兩公里的冰層之
下的岩石所砌成，城門則是以熔岩山脈附近開採而來的卡特
姆普巨石(Giant Stone of Kartermoop)所製成，據說關上
後連魔法師們的法術都無法輕易穿透。
LONG
        );
        set("exits", ([ 
            "east": __DIR__"wgate2",
            ]));
        set("light",1);
                        set("objects", ([
  __DIR__"npc/gguard" : 8,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

