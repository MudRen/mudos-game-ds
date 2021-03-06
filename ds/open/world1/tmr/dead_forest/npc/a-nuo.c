// 具-鎖鍊(lock-chain) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
    set_name( "麥克阿諾" , ({ "maike a-nuo","nuo","maike" }) );
    set("long",@long
    麥克阿諾是強獸人軍團中退伍的老軍人，渾身深綠色的粗糙皮膚
上佈滿大大小小的彈孔、刀燙傷等不同的傷口，看的出來身經百戰，
只是年歲已高而退伍養老。
long
);
    set_race("strength");
    set("title", "強獸人少將" );
    set("age", 70 );

    set("chat_chance", 5 );
    set("chat_msg", ({
        "麥克阿諾望著前方，臉上表情顯得不是很高興...\n",
        "麥克阿諾自言自語道：「這半獸人們最近似乎在計畫什麼戰事，可真讓人摸不透...」\n",
        "麥克阿諾自言自語道：「在這兒也只能乾瞪眼，真是不知半獸人們在玩些什麼花樣...」\n",
    }));

    setup();
    set_level( 5 );
}

int accept_object(object me, object ob)
{
       if( ob->query_learn("lock-chain") ) return 0;
        if( is_fighting() ) {
               do_chat((: command, "say 你給我這個幹嘛？" :));
              return 0;
       }

       if( ob->id("_CRUSH_BONE_WAR_PLAN_") && me->query_temp("quest-lock-chain")==1 ) {
                do_chat( ({
                        "麥克阿諾細細地閱讀起作戰計畫，臉上神色卻是越來越難看...\n" ,
                        "麥克阿諾仰天長嘆一聲：「這可是天要亡我一族啊，這場戰計畫的如此周詳，根本找不出任何破綻...」\n" ,
                        (:command("cry"):) ,
                        "麥克阿諾又嘆道：「除非能殺死碎骨寨的統紿者，要不然無從打贏這場戰鬥。」\n" ,
                        "(你心中開始衡量自已的能力，不知是否要幫這個忙。)\n" ,
                        ( : destruct , ob : ),
                }) );
                me->set_temp( "quest-lock-chain" , 2 );
                return 1;
        }

       if( ob->id("_CRUSH_BONE_BLOOD_") && me->query_temp("quest-lock-chain")==2 ) 
        {
                // 血液
                do_chat( ({
                                        (:command("wacow"):) ,
                        "麥克阿諾仔細端詳了這瓶血液，似乎正在確定它的來源...\n" ,
                        "麥克阿諾大笑起來：「哈!!謝謝你幫我們族一個大忙，將那個狗皇帝給宰了。」\n" ,
                        "麥克阿諾神色和悅地望著你道：「看你資質其佳，不如由我來傳你一招防身的功夫吧，不知你意下如何？」\n" ,
                        ( : destruct , ob : ),
                }) );
                me->set_temp( "quest-lock-chain" , 3 );
                return 1;
       }
        
        do_chat((: command, "say 你給我這個幹嘛？" :));
        return 0;
}

void relay_say(object ob, string arg)
{
          // 已學得鎖鍊的人，則不必再解了
        if( ob->query_learn("lock-chain") ) return;
        if( arg=="半獸人")  {
                do_chat(
                        ({
                            "麥克阿諾對著你大罵起來：半獸人是我族的死敵，有不同戴天之仇，你最好不要再提到牠們了...\n",
                        "麥克阿諾氣呼呼地一點也不像是老人...\n",
                    })
            );
            return ;
        }
        if( arg=="戰事")  {
                do_chat( ({
                  "麥克阿諾說道：「我們兩族已經發生大大小小的戰爭不下數百次了，但誰也都沒有真正滅掉對方。」\n",
                  "麥克阿諾說道：「只是近年來半獸人擁立的新皇帝有德有才，將整座碎骨寨經營的有聲有色...」\n",
                  "麥克阿諾頓了頓，又繼續說道：「最近傳言碎骨寨正祕密計畫一項大戰爭，但我們族人卻渾然不知頭緒，真是讓人擔憂啊...」\n",
                  "(你心想或許去碎骨寨走一趟，或許能拿到什麼計畫書之類的也說不定)\n",
                    }) );
            ob->set_temp("quest-lock-chain" , 1);
            return ;
        }
        if( ob->query_learn("lock-chain") ) return;
        if( ob->query_temp("quest-lock-chain") == 3 ) {
        
                           if( arg=="好") {
                                        message_vision( CYN "麥克阿諾長吸了口氣，臉上神色肅容起來，接著開始比劃起一長串的手勢...\n"  NOR , ob);
                                        if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                                                tell_object( ob , CYN "(但是你完全看不懂他所比劃的意義...)\n" NOR );
                                        }
                                        else {
                                                        tell_object( ob , CYN "\n(你似乎對於「具-鎖鍊」這個技能有個初步的認識了...)\n" NOR );
                                                        tell_object( ob , HIY "\n(你的技能點數減少三點了。)\n" NOR );
                                                        ob->improve_skill( "lock-chain" , ob->query_attr("cps") );
                                                        ob->add("skills_point" , 3 );
                                        }
                                        ob->delete_temp( "quest-lock-chain" );
                                        return;
                                }
                                if( arg=="不好") {
                                                do_chat( ({ "麥克阿諾道：「那好，我會回去我們族裡宣揚你的事蹟的。」\n" }) );
                                                ob->delete_temp( "quest-lock-chain" );
                                                return;
                                }
                }
}


