// 古董商人 能學到 「變-線性念力」
// -Tmr 2003/08/18

#include <npc.h>
#include <ansi.h>
#define QUEST_STRING "down_cave/slovakia"

inherit F_VILLAGER;

void timeto_eat();

void create()
{
        set_name("斯洛伐克", ({ "slovakia"}) );
        set_race("human");
        set("age", 35);
        set("gender", "male");
        set("long",@long
斯洛伐克一個專門四處旅行，收集各種珍寶的古董商人，瞧他身上正
背著個頗大的背包，不知裡頭裝有多少珍奇古玩。
long
        );
                set("title","古董商");
        set("chat_chance", 5);
        set("chat_msg", ({
                "斯洛伐克正躲躲藏藏地的縮在一旁，但又賊頭賊腦望著走道的另一端\n",
                "斯洛伐克望了你一眼，就不再瞧你了.....\n",
                "斯洛伐克嘴裡唸唸有辭，好像在說什麼貪婪之島...\n",
        }));
        setup();
}

void exchange(object player,object ob)
{
    object ring;
        if(ob->id("_QUEST_ITEM_SLOVAKIA_1_") && player->query_temp(QUEST_STRING)==1 ) {
                // card 1
                command("say 哇！！謝謝你了，但記憶卡要湊齊三塊耶...");
                        player->set_temp( QUEST_STRING , 2 );
        } 
        else if(ob->id("_QUEST_ITEM_SLOVAKIA_2_") && player->query_temp(QUEST_STRING)==2 ) {
                // card 2
                command("say 呵呵...真有你的，看能不能再麻煩你再幫我找到第三塊吧。");
                        player->set_temp( QUEST_STRING , 3 );
        }
        else if(ob->id("_QUEST_ITEM_SLOVAKIA_3_") && player->query_temp(QUEST_STRING)==3 ) {
                // card 3
                command("ya");
                command("say 太棒了，我可以趕快離開這個鬼地方，回家去試試這款遊戲了。");
                command("say 這個是我前陣子撿到的戒指，就送給你當做是謝禮了吧。");
                command("wave");
                player->delete_temp( QUEST_STRING);
                ring = new(__DIR__"obj/spider-ring.c");
                ring->move( player );
                destruct( this_object() );
        }
        else {
                command("say 謝謝你了，雖然不是我需要的東西。");
        }
        destruct(ob);
}

int accept_object(object me, object ob)
{
       if( (!ob->id("_QUEST_ITEM_SLOVAKIA_1_")
        && !ob->id("_QUEST_ITEM_SLOVAKIA_2_")
        && !ob->id("_QUEST_ITEM_SLOVAKIA_3_") )
        || is_fighting() )
           {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:可解到 +int 1 gloves */
void relay_say(object ob, string arg)
{
        if( ob->query_temp( QUEST_STRING ) ) return;
        if( strsrch(arg,"貪婪之島")!=-1  )  {
              command("say 噓....小聲點，莫要讓這邊的人聽到，免得被他們發現我來這兒的意圖。");
        }
        if( strsrch(arg,"意圖")!=-1  )  {
              command("say 我當然不會說出我的意圖是要來這兒找貪婪之島專用的記憶卡。");
              command("smirk");
              return ;
        }
        if( arg=="記憶卡" )  {
              command("say 咦....你怎地知道了？？");
              command("say 是啊，老實跟你說了，聽說硬幫幫中有人在前陣子撿到了，我聽到消息就來看看了..");
              command("say 不知你是否能幫我找找看看啊？");
              command("wink");
              return ;
        }
        if( arg=="可以" || arg=="好"  )  {
              command("say 好，真是謝謝您了，我就在這兒等著你吧。");
                  ob->set_temp( QUEST_STRING , 1 );
              return ;
        }
}
