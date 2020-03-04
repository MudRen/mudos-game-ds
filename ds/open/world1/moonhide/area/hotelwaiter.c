#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name("店小二" , ({ "waiter" }));
        set("long",
        "他是這家店的店小二，看它沒什麼事做的樣子。\n"
        "你可以用(bespeak for qk)來向他訂房\n"
        );
        set("chat_chance",9);
        set("chat_msg",({
  "店小二對你說: 客倌請進請進 !\n",
  (: command,"tsk" :),
  (: command,"好累ㄛ ~ ~" :),
  (: command,"say 客倌您安安ㄚ∼" :),
  (: command,"say 請問要休息嗎？" :),
}));
        set("inquiry",([
  "休息" : "休息(qk)一次 300 文錢∼！\n",
]));
        set("sell_list",([
  "/obj/example/dumpling" : 6,
  __DIR__"obj/bag": 6,
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
        add_action("do_buy","buy");
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二哈腰對你說: 客倌請進請坐  !\n");
                        break;
                case 1:
                        say( "店小二向你介紹說：本店的寒冰床是最有名的。\n");
                        break;
        }
}

int do_bespeak(string arg) // qk
{
        object me,ob;
        string c;
        me = this_player();
        ob = this_object();

        if( !arg || sscanf(arg,"for %s",c)!=1 )
                return notify_fail("你要跟小二訂房嗎呢？(bespeak for qk})\n");

        switch(c) {
        case "qk":
                if( !me->can_afford(300) )
                        return notify_fail("你身上的錢不夠喔。(300文錢)\n");
                me->receive_money(-300);
                me->add_temp("qk",1);
                message_vision("$N給了$n休息的錢，三百錢。\n",me,ob);
                command("ok "+me->query("id"));
        break;

        default:
                write("你要休息(qk)嗎？\n");
        break;
        }
        return 1;
}

