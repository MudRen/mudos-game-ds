#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("江小草", ({ "jiang grass","grass" }) );
        set_race("human");
        set("age", 10);
        set("long", "一個年幼的稚童，臉上似乎留著兩條淚痕，似乎剛哭過，不知他發生了什麼事。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "江小草伸袖擦了臉上的淚滴。\n",
                (: command("sigh") :),
                (: command("cry") :),
        }));

        setup();
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        destruct(ob);
        command("say 真是謝謝你，那我可以放心回家了。");
        command("wave");
        player->set_temp("duli_village/lost_child",1);
        destruct( this_object() );
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_OBJ_ID_QUEST_JAWEI_")
                || is_fighting()
                || me->query_temp("duli_village/lost_child")
                || me->query_learn("isolate sword")  )
           {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
       command("smile");
       command("say 啊....你幫我找到了？？你真是厲害耶！！");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:可學到 歸隱、征戰 劍法 */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("isolate sword") ) return;
        if( ob->query_temp("duli_village/lost_child") ) return;
        if( strsrch(arg,"哭")!=-1
        || strsrch(arg,"什麼事")!=-1
        )  {
              command("say 嗚.....我不敢回家了，我把的爺爺的東西用不見了...嗚嗚");
              return ;
        }
        if( arg=="爺爺的東西"  )  {
              command("say 嗚..嗚...我昨天下午帶去海邊玩時，不小心掉在海裡了..");
              command("sigh grass");
              return ;
        }
}

