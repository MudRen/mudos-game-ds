#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("旅店老闆" , ({ "boss" }));
        set("long",
        "他是這一家店的老闆，他正忙著幫忙照顧客人。\n"
        "你可以用登記(register)來向他登記房間．\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say 您好阿∼" :),
  (: command,"say 請不要在此大聲喧嘩..." :),
}));
        set("inquiry",([
   "住宿" : "住宿一次共要400枚電子幣歐喔∼！\n",
]));
        set("no_fight",1);
        setup();
}

void init()
{
    add_action("do_register","register");
}

int do_register(string arg) //  sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("你要跟老闆登記什麼呢？( register for sleep)\n");
        switch(c) {
        case "sleep":
                if( me->query("bank/future") < 400 )
                        return notify_fail("你的錢不夠。(400)\n");
                me->add_temp("sleep",1);
                me->add("bank/future",-400);
                message_vision("$N付給了$n住宿的費用，總共400塊。\n",me,ob);
                command("nod "+me->query("id"));
                me->move(__DIR__"../waiter2.c");
        break;

        default:
                write("你要住宿(sleep)嗎？\n");
        break;
        }
        return 1;
}

