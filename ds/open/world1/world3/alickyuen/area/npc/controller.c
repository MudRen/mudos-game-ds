#include <ansi.h>
#include <path.h>
inherit NPC;
// int sort_user(object ob1, object ob2);
void create()
{
        set_name("動物管理人員",({"animal controller","controller"}) );
        set("long",@LONG
一個負責管理動物園內的動物的工作人員，他開來滿目憂仇，滿煩惱似的。
LONG
);
        set("age",50);
        set("level",1);
        set("attitude", "peaceful");
        set("race","人類");
        set("gender", "男性" );
        set("chat_chance",10);
        set("chat_msg",({
        (:command("sigh"):),
      //  (:command("say ooxx？"):),
        }) );
                set("talk_reply","你能幫我一點小忙(help)嗎？\n");
                set("inquiry/help","這幾天有一些動物自己溜了出來，你可以幫我捉回它們嗎？\n");
        setup();
       set_living_name("reward-war-animal");
}
void init()
{
        ::init();
        add_action("do_reward","reward");
add_action("do_nod","nod");
 //     add_action("do_gamelist","gamelist");
}
int do_nod(string arg)
{
      object me, net;
      me=this_player();
       say("你就拿這個去幫我找回那些小動物吧。\n");
       say("幫我找到後，我會給你報酬(reward)的。\n");
message_vision("動物管理人員給了$N一個電子捕捉球。\n",me);
        net=new(__DIR__"obj/net");
        net->move(me);
}
int do_reward(string arg)
{
        int i;
        object me,p;

        me=this_player();
        i=me->query("Find_An/animal");

        if(!arg) return notify_fail("你想要什麼報酬？(exp)(popularity)\n");
        switch (arg)
        {
        case "exp":
        message_vision("$N想要經驗值。\n",me);
        if (i<5) return notify_fail("你又沒幫我找夠數目的動物．．．－ˍ－\n");
        message_vision(HIY "$n得到了1000點經驗值。\n" NOR ,this_object(),me );
        me->add("exp",1000);
        me->add("Find_An/animal",-5);       
        break;

        case "popularity":
        message_vision("$N想要聲望。\n",me);
        if (i<100) return notify_fail("你又沒幫我找夠數目的動物．．．－ˍ－\n");
        message_vision(HIY "$n得到了一點聲望。\n" NOR ,this_object(),me );
        me->add("popularity",1);
        me->add("Find_An/animal",-100);
        break;

        default:
        return notify_fail("沒有這種報酬說。\n");
        break;
        }
        return 1;
}
/*
int do_gamelist()
{
        string str, *option;
        object *list,me;
        int i, j, ppl_cnt,opt_id;
        me=this_player();
        str = HIW "◎  為動物園貢獻最多的線上排名 \n" NOR;
        str += "─────────────────────────────────────\n";
        list = users();
        list = sort_array(users(), "sort_user", this_object());
                ppl_cnt = 1;
                j = sizeof(list);
                while( j-- ) {
                        if( !environment(list[j]) ) continue;
                        if(!list[j]->query("Find_An/animal") ) continue;
                        if( me && !list[j]->visible(me) ) continue;             
          str = sprintf("%s%-30s%s",
           str,
              "第"+(string)ppl_cnt+"名："+list[j]->query("name"),
              (string)list[j]->query("Find_An/animal")+"隻。\n",
           );
                        ppl_cnt++;
                }
                
        str += "─────────────────────────────────────\n";
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        int ord;

        ord = ob1->query("Find_An/animal")-ob2->query("Find_An/animal");
        if( ord==0 )
                ord = (int)ob1->query_level() - (int)ob2->query_level();
        return ord;
}
*/


