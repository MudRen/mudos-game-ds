#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":       "$N張大嘴巴朝著$n的$l一陣猛咬",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "咬傷",
        ]),
        ([      "action": "$N突然往$n的方向撞了過去",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        ([      "action": "$N一張嘴，對著$n的$l吐出一道火球",
                "attact_type":  "bio",
                "damage_type":  "燒傷",
        ]),
        ([      "action": "$N突然全身化做一團火球猛然往$n的撞去",
                "attact_type":  "bio",
                "damage_type":  "燒傷",
        ]),
        ([  "action":       "$N憤怒的舞動利爪狂掃$n的$l",
                "attact_type":  "bar",
                "damage_type":  "抓傷",
        ]),
});

void create()
{
        set_name(HIY"寒日"NOR,({"freeze sun monster", "monster" }) );
        set("long",@LONG
寒日獸渾身長滿了金黃色的長毛，火紅的雙眼正凝視著你，長二尺有
餘的尾巴似乎帶著火花正在微微晃動，炎熱而燥悶的火氣正從寒日獸身上
不停的散發出來，四周圍的氣溫似乎也越趨沸騰的程度。
LONG
);
        set("limbs", ({
                "頭部", "頸部", "胸口", "背後","腰間","腹部","前爪","後腿","尾巴",
        }) );
        set("title","魔獸");
        set("age",500+random(99));
        set("level",66);
        set("gender","雄性");
         set("race","beast");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
                "一股燥熱的蒸氣從寒日獸身上持續著散發出來....\n",
        }));
        //set_skill("mob_bite", 84);
        set("addition_damage",120);
        set("addition_armor",120);
        set("Merits/wit",3);
        add("apply/hit",60);
        set("chat_chance_combat", 42);
        set("chat_msg_combat", ({
        }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
         carry_object(__DIR__"eq/mask")->wear();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        object body; // 假人身軀
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
        HIG"\n【武林消息】"HIW"八極禁地的守護獸-寒日 竟然被"+ob->name(1)+HIW"殺死了！！\n\n"+NOR,users());

        ob->add("popularity",3); //聲望
        if( random(100)<30 )
                body=new("open/world1/tmr/bagi/npc/obj/doll_body");
        else  if( random(100)<30 )
                body=new("open/world1/tmr/bagi/npc/obj/left-leg");
        else
                body=new("open/world1/tmr/bagi/npc/obj/left-arm");

        body->move( this_object() );
        ::die();
        return;
}

