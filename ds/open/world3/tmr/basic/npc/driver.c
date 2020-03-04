#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
        set_name( "車長" , ({ "trainman","man" }) );
        set("long",@long
他是一個駕駛連接主城到礦區的地下鐵的列車長。看來約五十歲上下
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
        object me;
        me=this_player();
        if(!arg )
                return notify_fail("你想買車票(ticket)嗎？\n");
        if(arg!="ticket" )
                return notify_fail("車長只有販買車票(ticket)。\n");
        if(me->query_temp("dinkey_ticket") )
                return notify_fail("你已經買過車票了。\n");
return notify_fail("鐵路施工中，現在暫停售票。\n");
          message_vision("$N花了３００電子幣向車長登記了電子車票。\n",me);
      me->receive_money(-300);
        me->set_temp("dinkey_ticket",1);
        return 1;
}

