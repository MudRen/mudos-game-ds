// 龍                         by Zorg
// 可以騎乘的範例
// 註: 不僅是活的生物可以騎乘, 就算是沒有生命的東西也可以, 例如 筋斗雲
//     只要加上 set("ridable",1); 就可以騎乘
inherit NPC;

void create()
{
        
        set_name("龍",({"dragon"}) );
        set("race", "野獸");
        set("level",50);
        set("str",100);
        set("con",100);
        set("int",100);
        set("dex",100);
        set("age",4000); 
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_spell("god-benison",100); 
        set("long", "這是一種非常罕見得品種,其成龍更是難得一見,
在生物界中他算是最強的生物,鬥爭能力'魔法力'生命力都是最強的。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部","翅膀"}));
        set("verbs", ({"bite"}));
        set("ridable",1);               // 設定為可騎乘的
        set("chat_chance", 9);      
        set("chat_msg", ({   
        (:command("defend zorg"):),
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("defend zorg"):), 
        (:command("cast god-benison"):),  
}) );
        setup();
}

int ride_before_action(object me)       // 騎乘之前會執行函式
{
        int s = me->query("str");
        if( s<10 || !s )
        {
                message_vision("由於$N的力量不夠，無法控制"+this_object()->name()+"，因而被"+this_object()->name()+"從龍背上摔了下來！\n",me);
                return 0;               // 回傳 0 就是代表不能騎乘
        }
        else 
        {
                message_vision("$N使出全身的蠻力準備征服這隻"+this_object()->name()+"。\n",me);
                return 1;               // 回傳 1 就是代表可以騎乘
        }
}

int ride_after_action(object me)        // 騎乘之後會執行函式
{
        message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
        return 1;                       // 必須要回傳 1
}


int ride_off_action(object me)          // 離開座騎之後會執行函式
{
        message_vision("$N已經離開"+this_object()->name()+"了。\n",me);
        return 1;                       // 必須要回傳 1
}


