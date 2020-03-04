#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",MAG"禰影神廟"NOR);
 set("long",@LONG
你已經走到了神廟的盡頭，眼前的景象讓你感到十分的
驚訝，神龕完全佔據了一面牆壁！而神龕上應有盡有，什麼
燭臺啦，供生燈啦， ...自然是一樣不缺，但是在神龕的中
心卻留出了一個菱形的空格，看起來格外不搭.....
LONG
    );
 set("exits",([   "west":__DIR__"ten43",
    ]));
 set("objects", ([__DIR__"npc/cw_taoist" : 1,
    ]));
set("item_desc",([
        "菱形空格" : CYN"你發現在空格之中有一枚銅環....?!\n"NOR,
      "銅環" : CYN"這個銅環是連在神龕之上的, 你沒有辦法把它拿下, 不過銅環的用處究竟是...?\n"NOR,
]));
set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_pray","pray");
}

int do_pray(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten45");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要膜拜什麼?\n");
        if( a!="銅環" )
                return notify_fail("有這種東西嗎?\n");
      if (me->query("level") > 25)
     {
        message_vision(HIW"$N誠心的跪下膜拜銅環, 忽然一陣煙霧飄過, $N失去了蹤影! \n"NOR,me);
          me->move(where1);
        return 1;
     }
     else 
     {
        message_vision(HIW"$N誠心的跪下膜拜銅環.... \n"NOR,me);
        return 1;
     }

}


