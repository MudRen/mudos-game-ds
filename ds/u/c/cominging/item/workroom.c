#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", " -= Use you brain in PROGRAMMING =- ");
        set("long", @long

這些年, 這些日子, 數數, 至少也快三年了, 記得當初被 Jack 拉進
DS時, 還是一個何謂 LPC 為何物的菜鳥.. 到現在勉勉強強算是一個
.. 還能夠 Coding 的 Wizard, DS 的巫師群.. 一個接著一個的有一
點的人口流失..不是忙 new Mud 就是學業的問題, But I still
believe that.. Our DS won't be ruined !
               We're the Best !

long    );
        set("exits", ([
  "baal": "/u/b/baal/workroom.c",
  "wiz": "/d/wiz/hall1.c",
  "c_hotel": "/open/world1/tmr/area/hotel.c",
  "q": "/u/u/uchimaha/workroom.c",
  "luky": "/u/l/luky/workroom.c",
  "alick": "/u/a/alickyuen/workroom.c",
]));
        setup();
        call_other("/obj/board/coming_b.c", "???");
}

void init()
{
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
}

void delay(object me)
{
        string str;
        if( str = read_file(__DIR__"qlist") )
                write(HIG"\t:::: Incoming "HIY"Quest List "HIG"::::\n\n"NOR+
                        str+ NOR +"\n");
}
