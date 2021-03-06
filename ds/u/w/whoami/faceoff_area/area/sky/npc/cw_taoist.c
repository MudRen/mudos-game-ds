#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":              "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIY+"伏魔訣"+NOR+""+CYN+"】"+NOR+"一道金光閃過$n的$l!",

                "attact_type":  "sou",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+MAG+"天罡\訣"+NOR+""+CYN+"】"+NOR+"一道紫光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
        ([      "action":               "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIR+"破邪訣"+NOR+""+CYN+"】"+NOR+"一道紅光閃過$n的$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIC+"凍妖訣"+NOR+""+CYN+"】"+NOR+"一道藍光閃過$n的$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIM+"詠日訣"+NOR+""+CYN+"】"+NOR+"一道橙光閃過$n 的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":       "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+GRN+"劍氣訣"+NOR+""+CYN+"】"+NOR+"一道綠光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+HIW+"滅殺訣"+NOR+""+CYN+"】"+NOR+"一道白光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+WHT+"四傲訣"+NOR+""+CYN+"】"+NOR+"一道灰光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
    ([  "action":      "$N口中喃喃自語,九重天咒之 "+CYN+"【"+NOR+""+YEL+"地土訣"+NOR+""+CYN+"】"+NOR+"一道褐光閃過$n的$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "灼傷",
        ]),
});

void do_clean();

void create()
{
        set_name(WHT"雲風聖道"NOR,({"cloudwind taoist", "cloudwind","taoist" }) );
        set("long",@LONG
他是守護這個神殿的主持道人, 傳說他從神廟創始就在
了, 而神廟是在一千兩百年前創建的, 那他難道已經....?
不過從他慈祥的態度來看, 真是和藹可親啊!....
LONG
);
        set("title",MAG"「詠頌者」"NOR);
        set("age",1200+random(50));
        set("level",50);
        set("gender","男性");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "風雲聖道慈祥的呵呵笑了起來...。\n",
        "風雲聖道和藹的望著你....。\n",
        }));
        set_skill("unarmed", 100);
      set("Merits/sou",6);
      set("int",175);
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
    carry_object(__DIR__"eq/wind_leg")->wear();
        set("actions", (: call_other, __FILE__, "query_action" :));
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 {
 command("smile "+me->query("id") );
        command("say 我是這個神廟的住持，這個神殿並沒有什麼值得一看的地方...");
        command("say 如果你是虔誠的教徒，就去膜拜(pray)那個銅環吧~");
}
 return 1;
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIR"\n【十萬大山】"+MAG"亙古的雲風聖道竟然被"+ob->name(1)+"摧毀了, 莫非十萬大山的封印...?\n\n"+NOR,users());
            ob->add("popularity",5+random(2)); //聲望
        ::die();
        return;
}


