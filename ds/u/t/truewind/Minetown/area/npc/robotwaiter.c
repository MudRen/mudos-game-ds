inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("維達二號" , ({ "robot waiter","robot","waiter" }));
        set("long",
        "它站在電子帳棚前，銀色的眼睛望著你...。\n"
        "你可以用訂(book)來向他訂帳棚休息．\n"
        );
        set("title","機器人");
        set("chat_chance",9);
        set("chat_msg",({
  "(喀喀...喀喀...)\n",
  (: command,"stare" :),
  (: command,"bow" :),
  (: command,"say (喀喀...)有什麼需要呢...要休息請先繳費..." :),
}));
        set("inquiry",([
  "休息" : "休息一次共要 200 電子幣(喀喀...)。\n",
]));
        set("no_fight",1);
        setup();
}

void init()
{
        object ob=this_player();
        ::init();
        if( userp(ob) && this_object()->visible(ob) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_pay","pay");
        return;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        command("say (喀喀)有什麼需要嗎??");
                        break;
                case 1:
                        command("pat $N");
                        break;
        }
        return;
}

int do_pay(string arg) // rest & sleep
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( arg )
                return 0;
        if( !me->can_afford(200) ) return notify_fail("你身上的錢不夠。(200電子幣)\n");
        if( me->query_temp("mine/tent")) return notify_fail("(喀喀)你已經付過錢了，請進去休息。\n");
        me->set_temp("mine/tent",1);
        me->receive_money(-200);
        message_vision("$N付給了$n帳棚費用兩百元。\n",me,ob);
        command("say 謝謝您的惠顧，請您自行進入休息吧。");
        return 1;
}
