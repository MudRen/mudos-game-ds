#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name("阿凸", ({ "a-too","too" }) );
        set("title", "人力車伕");
        set("gender", "男性" );
        set("long",@long
阿凸為一個往返天城、滄縣的人力車伕，看起來就是一臉老實樣。
long
        );      
        set("age",20);
        set("level",5);
        set("race","human");
        set("chat_chance", 10);
        set("chat_msg", ({
             "阿凸說道：到天城的天香客棧，只要一百文錢就成了。\n",
             "阿凸望地遠方的天空，征征地發起呆來。\n",
             "阿凸說道：到滄縣聞名的朝天湖，只要五十文錢就行了。\n",
        }));


        set("chat_chance_combat", 50 );        
        set("chat_msg_combat", ({
                "阿凸叫道﹕殺人哪﹗殺人哪﹗\n",
         }) );
  
        setup();
}

int accept_object(object who,object ob)
{
        
        if(ob->query("id")!="coin" ) return 0;
        if (ob->query_amount() == 50)
        {
                command("smile");
                message_vision(HIY "$N給了阿凸五十文錢，隨既坐上了人力車往滄縣的方向奔去。\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                  who->move(TMR_PAST+"area/square");
                  this_object()->move(TMR_PAST+"area/square");
                return 1;
        }
        if (ob->query_amount() == 100)
        {
                command("smile");
                message_vision(HIY "$N給了阿凸一百文錢，隨既坐上了人力車往天城的方向奔去。\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                who->move(ACME_PAST+"area/st");
                this_object()->move(ACME_PAST+"area/st");
                return 1;
        }
        command("say 這位官倌，你要到那呢？？\n");
        return 1;
}


