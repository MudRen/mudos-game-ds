#include <ansi.h>
inherit NPC;
void do_ship(string arg,int flag);

void create()
{

        set_name( "售票員" , ({ "trainman","man" }) );
        set("long",@long
他是一個駕駛連接地下城到主城的地下鐵的售票員。看來約五十歲上下
，滿臉滄桑的樣子。如果你想坐電車的話，請務必向他購買車票。
long
);

        set("age", 50);
        set("level", 5);
        set("gender","男性");
        set("race","human");
        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object me , ticket;
        me=this_player();
        if(!arg )
                return notify_fail("你想買車票(ticket)嗎？\n");
        if(arg!="ticket" )
                return notify_fail("售票員只有販買車票(ticket)。\n");
          message_vision("$N花了３００電子幣向售票員登記了電子車票。\n",me);
        me->add("bank/future",-300);
          message_vision(MAG"$N緩緩的向登車處走去....\n"NOR,me);
        me->move(__DIR__"../boot2.c");
        ticket=new(__DIR__"obj/ticket");
        ticket->move(me);
         me->start_busy(7);
        return 1;
}

