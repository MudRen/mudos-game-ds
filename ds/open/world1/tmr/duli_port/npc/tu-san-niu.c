#include <npc.h>
inherit F_VILLAGER;
void create()
{
        set_name("屠三牛", ({ "tu san-niu","tu","niu" }) );
        set_race("human");
        set("title","杜尼旅店大廚" );
        set("age", 60);
        set("long",@LONG
屠三牛是杜尼港有名的廚師，廚藝精湛，塊頭也比一般人來的孔武有
力，你可以看見他的雙手滿是刀傷燙傷的，可想而知是每天都沉溺在廚事
當中。
LONG
);
        set("chat_chance", 5);
        set("chat_msg", ({
                "屠三牛嘴裡喃喃自語道：「這種料理不算難做，但就是材料麻煩了點...」\n",
                (: command("sigh") :),
                "屠三牛不停地踱來踱去，好像在煩惱什麼...\n",
        }));
        setup();
        set_level(10);
        carry_object(__DIR__"obj/butcher-knife.c")->wield();
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        object gloves;
        destruct(ob);
        if(player->query_temp("duli_port/bear_paw")==1) 
                command("say 可是我還少兩份熊掌，能否再麻煩您呢？");
        else if(player->query_temp("duli_port/bear_paw")==2) 
                command("say 可是我還少一份熊掌，能否再麻煩您一次呢？");
        else {
                command("say 真是太感謝了，我可以回去旅店中做這份黑暗料理了。");
                command("say 這兒有雙我做工常用的手套，不彷送給你了吧。");
                command("say 就此再見了....");
                command("wave");
                player->delete_temp( "duli_port/bear_paw" );
                gloves = new(__DIR__"obj/skin-gloves.c");
                gloves->move( player );
                destruct( this_object() );
        }
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_QUEST_ITEM_BEAR_PAW_")
                || is_fighting() )
           {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
       command("say 謝謝你了。");
       me->add_temp( "duli_port/bear_paw" , 1 );
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:可解到 +int 1 gloves */
void relay_say(object ob, string arg)
{
        if( ob->query_temp("duli_port/bear_paw") ) return;
        if( strsrch(arg,"材料")!=-1  )  {
              command("say 喔...是啊，九種材料已齊了八樣，就少一樣熊掌。");
        }
        if( strsrch(arg,"熊掌")!=-1  )  {
              command("say 聽說這兒往北過去的沙地中，常有灰熊出沒，但是兇暴異常，不是好惹的。");
              command("say 但我又走不開身，不知你是否可以幫我去取得？");
              return ;
        }
        if( arg=="可以" || arg=="好"  )  {
              command("say 好，真是謝謝您了，我就在這兒等著你吧。");
              return ;
        }
}

