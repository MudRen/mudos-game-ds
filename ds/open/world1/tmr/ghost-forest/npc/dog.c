#include <ansi.h>
inherit NPC;

void create()
{
        set_name(CYN "荒咬" NOR ,({"random-bite dog","dog"}) );
        set("long",@LONG
荒咬為由極邪極惡的妖氣所凝聚而成的鬼獸，其性殘惡兇暴嗜血，你
不經意地發現荒咬正在咀嚼著一塊血淋淋的肉塊，微一細看，赫然發現是
顆妙齡少女的頭！
LONG    
        );
          set("race","野獸");
        set("attitude", "aggressive");
        set("unit","隻");
        set("title","鬼獸");
        set("age",50);
        set("level",30);
        set("chat_chance",10);
        set("chat_msg",({
                  "荒咬正大口大口咬著一塊肉塊，搞的腥臭的血汁四濺...\n",
                "荒咬陡地發出一陣嘶吼聲....\n",
        }) );

        set("limbs", ({ "頭部", "腹部","胸部","尾巴","前腳" }) ); 
        set("verbs", ({ "bite" }) );
        set("addition_armor",50);
        add("apply/hit",60);
        setup();
    carry_object(__DIR__"eq/randombite-finger")->wear();
       set_living_name("ghost-forest-war-ghost");
}

void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }

         ob->add("ghost_forest_war",2);
         if(ob->query("ghost_forest_war") > 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("ghost_forest_war",0);
        }
        ::die();
        return;
}

