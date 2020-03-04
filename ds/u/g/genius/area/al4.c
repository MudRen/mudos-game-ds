#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"愛門村廣場"NOR);
        set("long", @LONG
這裡就是愛門村村長家的門口了，因為這裡的地方較為寬闊，離農地又
近，成為村民們休憩的場所。這裡的景緻不同於村口那一排排的桃樹。這裡
種了許多的杏樹，白色的杏花和紅色的桃花形成很完美的對比。杏樹是這個
村子的寶物，這裡的杏仁比其他地方大了許多，味道也不同於其他，這裡的
杏仁吃起來具有一股獨特的甜位，令人意猶未盡。還據說具有神奇的療效，
甚至能夠醫治某些魔法所造成的傷害。
LONG
        );
        set("exits", ([
     "north":__DIR__"al3",
     "south":__DIR__"al5",
     "east":__DIR__"r2",
     "west":__DIR__"r3",
]));
        set("objects", ([
        __DIR__"npc/villager1" :5,
]));


        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
