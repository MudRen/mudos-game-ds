#include <path.h>
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("葉樺", ({ "yip hua","hua" }) );
        set("gender", "女性" );
        set("long",
            "她是一個中年婦人，雖然說是中年，但是講其美貌，就連少女\n"
            "也比不上，但是她神色是分焦急，不知有何事情。\n"
           );
        set("age",30);
        set("level",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                  (:command("sigh"):),
        }));
        set("talk_reply","嗯，這裡沒你的事，快快走吧！");
        setup();
}
int accept_object(object who, object ob)
{
           int i;
           object me,obj,book;
           me=this_player();
           obj=this_object();
           i=me->query_temp("quest/wine");
           if( ob->name() != "絹布")
           {
             command("say 我不需要這個東西。");
             command("sigh");
             return 0;
           } 
           else {
             if(me->query_temp("quest/wine") < 7)
             {
message_vision("$N給了葉樺一個"+ob->query("name")+"。\n",me);
destruct(ob);
               call_out("drop",2,obj);
               return 1;
             }
             else {
               destruct(ob);
               say("葉樺嘆了口氣說道：好吧，我就看看吧...\n");
               say("葉樺看完了之後，眼眶似乎有點紅了。\n");
               say("葉樺別過頭去冷冷的說：這位大俠，麻煩你回去轉告他，要他死心吧。\n");
               say("說完，葉樺掉頭就走了...\n");
               me->set_temp("quest/wine",i+1);
               if(book=me->query_temp("notebook"))
               book->add_quests_note("SadSworder","葉樺請我轉告笑紅塵死了這條心。");
               destruct(obj);
               return 1;
             }
           }
}
void drop()
{
int i;
     object me,shawl;
    me=this_player();
i=me->query_temp("quest/wine");
    shawl=new(ACME_PAST+"area/npc/obj/shawl.c");
    say("葉樺看也不看的就把它丟在地上。\n");
    shawl->move( environment( this_object() ) );
    if(me->query_temp("quest/wine")>4)
    {
      me->set_temp("quest/wine",i+1);
    }

}
