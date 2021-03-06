/* kate.c
 * 卡特 獵人
 *
 * Quest：新手學習到念技
 *
 *  -Tmr 2002/02/25
 */

#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_FIGHTER;
// 戰鬥中的特攻-刀氣
int dead_god = 0;

void die()
{
        object ob ;
    ob = last_damage_giver();
    if( !ob || ob==this_object() )

        {
                ::die();
                return;
        }
        
      message("system",
           HIG "【獵人新聞】" HIW "舉世聞名的卡特獵人死在"+ob->name(1)+"(" + ob->query_id() + ")手上了！！\n"+NOR
        ,users() );

        ::die();
        return;
}
void do_dead_god()
{
        object ob , *enemy;
        int i;
    ob = this_object();
        if( !dead_god ) return;
        dead_god = 0;
        if( !ob->is_fighting() ) {
                // 非戰鬥中
                message_vision(HIW "$N手中的鐮刀發出一陣咯咯的笑聲，之後就消失了....\n"NOR , ob);
                return; 
        }
        enemy = ob->query_enemy();
        message_vision( HIR "\n$N一句「死神的圓舞曲」，手中的鐮刀劃破空氣似的掃過四週的一切生物....\n\n"NOR , ob);
        for( i = 0 ;i < sizeof(enemy) ; i++) {
                        message_vision( "$N" NOR "身上被鐮刀輕輕劃出一道傷口。\n"NOR , enemy[i] );
                        if( enemy[i]->query_stat("hp") > 1 ) {
                                enemy[i]->set_temp("damage_shield" , 0 );
                                enemy[i]->damage_stat( "hp", enemy[i]->query_stat("hp") - 1 );
                    COMBAT_D->report_status( enemy[i] );
                        } else
                                enemy[i]->damage_stat( "hp", 2 );
        }
        message_vision( "\n", ob );
        return ;
}

void do_combat_attack() 
{
        object me,ob;
        ob = this_object();
        if( ob->is_busy() ) return;
        me = ob->query_opponent();
        if(!objectp(me)) return;
                if(!dead_god && ob->query_stat("hp") <  ob->query_stat_maximum("hp")/2 && random(3) ) {
                        // 死神的圓舞曲
                        dead_god = 1;   // 發動
                        message_vision(HIW"\n$N手中忽然出現一把巨大的鐮刀，刀柄刻著血紅色的「2」，四週開始瀰漫起濃冽殺氣...\n\n"NOR,ob,me);
                        call_out( (: do_dead_god :) , 3 ); // 3秒後開斬..
                } else {
                        message_vision(HIW"$N左手虛空一劈，隨即發出一道疾如星火的刀氣直射向$n！！\n"NOR,ob,me);
                        if( random(100) > me->query_stat("nina")/15 ) {
                message_vision(HIR"刀氣狠狠劈在$n" HIR "身上，逼得$n" HIR"倒退三步，臉上神色難看..\n"NOR,ob,me);
                me->receive_damage( 50 + random(10) , ob , ob);
                        } else
                message_vision(CYN"但是並沒有對$n" CYN"造成影響。\n"NOR,ob,me);
        }
}

void create()
{
        set_name("卡特獵人", ({ "kate hunter", "kate", "hunter" }) );
        set_race("operation");          // 操作系
        set_class("hunter");            // 獵人職業
        set_skill("dodge", 150 );
        set_skill("unarmed", 150 );
        set_skill("blade", 150 );
        set_skill("finger-guessing fist", 150 );
        map_skill("unarmed","finger-guessing fist");     
        set_skill("psychical", 200);

    set("forect_ratio",100);
        set("title","金•富力士的弟子");

        set("gender", "male");
        set("age", 28);
        set("long",@long
在你眼前是一位身材瘦長，戴著一頂鴨舌鴨的男子，身上背著一個小旅
行包，看起來就不是鯨魚島上的居民。瞧他四處查看的樣子，似乎正在找尋
什麼東西或是線索。
long            
                );

        set("chat_chance", 8);
        set("chat_msg", ({
                 "卡特嘆口氣說道：「想說來到他的故鄉，看能不能找到一點線索，怎知乃沒有頭緒...」\n(你心中暗想難道他是在找「金•富力士」這名近年來最偉大的獵人？？)\n",
                (: command("sigh") :),
                "卡特對著你喝道：「快離開這裡！！這附近可是狐熊的勢力範圍！！」\n",
                  "卡特留神搜了搜四週的小東西，似乎在找什麼物品...\n",
                (: random_move :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "卡特神色自若，但全身已漸漸凝聚起高度的纏....\n",
                (: do_combat_attack :),
                (: do_combat_attack :),
        }) );

        set_temp("apply/armor" , 80);
        setup();
        set_level( 80 );
        //carry_object(__DIR__"obj/wushi-blade.c")->wield();
        carry_object(__DIR__"obj/wushi-blade.c");
        carry_object(__DIR__"obj/blue-jeans.c")->wear();
        carry_object(__DIR__"obj/ancient-belt.c")->wear();
        carry_object(__DIR__"obj/ancient-necklace.c")->wear();
        carry_object(__DIR__"obj/peaked-cap.c")->wear();
         carry_object("/d/cards/card-17")->wear();
}

int accept_fight()
{
        do_chat((: command, "?" :));
        return notify_fail("卡特對你的行為視若無睹 ...。\n");
}

void init()
{
        if( this_player()->query_learn("psychical") )
        {
                command("smile "+ this_player()->query("id"));
        }
}
int accept_object(object me, object ob)
{
        if( me->query_skill("blue-power") ) return 0;
       if( !ob->id("_BLUE_POWER_CARD_") || is_fighting() || me->query_temp("the-blue-power-quest")!=2 ) {
              do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }
          me->set_temp( "the-blue-power-quest" , 3 );
                do_chat( ({
                        "卡特不禁大吃一驚，不停地把玩這張卡片...\n" ,
                        "卡特說道：「這是張很珍貴的卡片，多謝您送給我，這張卡片有段很動聽的故事...」\n" ,
                        "卡特沉默了一下，似乎在回憶什麼事情...\n" ,
                        "卡特回過神來說道：「啊哈...我終於想起是怎樣的一個故事，不知你想不想聽呢？」\n" ,
                        ( : destruct , ob : ),
                }) );
       return 1;
}
void relay_say(object ob, string arg)
{
            if( !ob->query_skill("blue-power")  ) {
                if( !ob->query_temp("the-blue-power-quest") && arg=="物品" ) {
                        do_chat( ({
                          "卡特說道：「是啊，我除了來這島上找人之餘，也想順道找找一張卡片。」\n",
                          "只見卡特嘆了口氣，不知是否久尋未獲而來的感嘆..\n",
                          }) );
                        ob->set_temp("the-blue-power-quest",1);
                        return ;
                }
                if( ob->query_temp("the-blue-power-quest")==1 && arg=="一張卡片" ) {
                        do_chat( ({
                          "卡特說道：「我在找尋一張名叫「藍色行星」，編號81號的卡片，如果你有空的話，希望你能幫我找找」\n",
                          "卡特又低聲自言自語了幾句話，你隱隱約約聽到大湖區北邊的樣子...\n",
                          }) );
                        ob->set_temp("the-blue-power-quest",2);
                        return ;
                }
                 if( ob->query_temp("the-blue-power-quest")==2 && arg=="大湖區北邊" ) {
                          do_chat( ({
                            "卡特說道：「我之前有聽說過這卡片有在這座森林西邊的大湖區出現過，只是不知在什麼地方了...」\n",
                            "你暗自想著該不會是小時候釣魚常去的地方呢...\n",
                            }) );
                }

        }
        //////////////////////////////////////////////////////////////////////////////////////////////////
        // 藍色之力
              if( !ob->query_learn("blue-power") && ob->query_temp("the-blue-power-quest")==3 ) {

                if( arg=="想" ) {
                         message_vision( CYN "卡特拉著$N的手到一旁坐下，花了好些時間才將故事講完...\n" NOR , ob );
                    if(ob->query("skills_point") + 1 >  SKILL_MAX_POINT )  {
                        // 技能點數不足
                                        tell_object( ob , CYN "(你聽完之後沒有任何特殊的感覺，或許這故事並不那麼吸引你吧...)\n" NOR );
                                }
                                else {
                                        tell_object( ob , CYN "\n(你聽完故事之後，覺得身體起了點微樣的變化...)\n" NOR );
                                        tell_object( ob , HIY "\n(你的技能點數減少一點了。)\n" NOR );
                                        ob->set_skill( "blue-power" , 30 );
                                        ob->add("skills_point" , 1 );
                                        ob->improved_skill( "blue-power" , 10000 );

                                }
                                ob->delete_temp( "the-blue-power-quest" );
                                return;
                        }
                        if( arg=="不想" ) {
                                do_chat( ({ "卡特說道：「那好，謝謝你的卡片了...」\n" }) );
                                ob->delete_temp( "the-blue-power-quest" );
                                return;
                        }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // 念技
          if( ob->query_learn("psychical") || ob->query_skill("psychical",1) ) return;
        if( arg=="金•富力士" && ob->query_temp("island_forest/kate_quest")!=1 ) {
                do_chat( ({
                "卡特獵人驚道：「喔？？你認識他嗎？？」\n",
                "你細細地將所知道的一些事情，跟卡特獵人聊了起來......\n",
                  "(看樣子卡特獵人跟你聊的很高興，你心中起了個念頭，是否可以他指導你「念技」呢？)\n",
                }) );

                ob->set_temp("island_forest/kate_quest",1);
                return ;
        }
        if( arg=="念技" && ob->query_temp("island_forest/kate_quest") )
        {
                do_chat((: command, "say 嗯...看在你給我一些線索，我就指導一下你好了。" :));
        message_vision("$N教導了$n有關「鍊」的技巧。\n", this_object(),ob );
                do_chat((: command, "say 我也只能幫你起個頭，剩下的就靠你自已修練(forge)了。" :));
                ob->improve_skill("psychical",50);
                ob->delete_temp("island_forest/kate_quest");    
        }

        return ;
}


