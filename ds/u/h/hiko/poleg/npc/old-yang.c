#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("老楊" , ({ "old yang","yang" }));
        set("long",
        "他是這一家店的店主，他十分勤勞的招呼著客人，\n"
        "這家店他已經營業很多年，算是老口碑了，而且價\n"           "格低廉，因此來此的熟客絡繹不絕。\n"
        "若你不滿意可以用訂(bespeak)來去使用廚房自製料理\n"        
        "不過記得準備好材料．\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "店小二對你說: 客倌請進請進 !\n",
  (: command,"smile" :),
  (: command,"bow" :),
  (: command,"say 客倌您好∼" :),
  (: command,"say 請問要點些什麼嗎？" :),
}));
        set("inquiry",([
  "自製料理" : "自製料理(bespeak)一次3000文錢∼！\n",
  "cook" : "自製料理(bespeak)一次3000文錢∼！\n",
  "軒轅烈" : "你說軒轅大俠呀，它昔日也是我店裡的常客。",
  "縣老爺" : "天城縣老爺也很喜歡派人像我們訂料理唷∼∼",]));
        set("sell_list",([
  __DIR__"item/food/wealfish-soup": 6,
  __DIR__"item/food/freshsha-soup": 6,
]));
        set("no_fight",1);
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
 if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "老楊笑笑對你說: 客倌請進請進  !\n");
                        break;
                case 1:
                        say( "老楊向你介紹說：本店的料理是全村有名的。\n");
                        break;
        }
}

int do_bespeak(string arg) // cook
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || arg!="cook" )
                return notify_fail("你要訂什麼呢？(cook)\n");
        if( !me->can_afford(3000) )
                return notify_fail("你身上的錢不夠。(3000文錢)\n");
                me->add_temp("cook",1);
                me->receive_money(-3000);
                message_vision("$N付給了$n使用廚房的費用，總共約三千多文錢。\n",me,ob);
                command("nod "+me->query("id"));
                return 1;
}






