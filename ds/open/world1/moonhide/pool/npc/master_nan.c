#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":               "$N手拿"HIR"魔神兵"NOR"踏站八卦五行之後，使出一式「"HIG"盤古開天"NOR"」煞那間此領域物轉星移，$n頓時暈眩，不支倒地",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage" : 200,
                "damage_type":  "暈眩傷",
        ]),
        ([      "action":               "$N魔刀一攤，使出一式「"HIM"女媧降世"HIY"※"NOR""MAG"紫氣東來"NOR"」，迅速的走位，便適時的揮出一掌，$n像稻草人般似的，飛出十里外!!",
                "attact_type":  "bar",
            "damage" : 300,
                "damage_type":  "創傷",
        ]),
        ([      "action":               "$N喃喃自語後，使出一幻術「"HIY"渺巫乍天開"NOR"」道道龍炎，燒至$n全身!!",
                "attact_type":  "int",
            "damage" : 400,
                "damage_type":  "燒傷",
        ]),
    ([  "action":       "$N突然奔走向$n，用力的推擊$n!!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "內傷",
        ]),
    ([  "action":       "$N揮灑自如，操縱手裡心刀，便化內力為刀、心刀為心，頓時間數道刀影，殺向$n!!",
                "attact_type":  "sou",
            "damage" : 600,
                "damage_type":  "多處內傷",
        ]),
   
   
});

void do_clean();

void create() 
{ 
  set_name(HIW"南宮無雙"NOR,({"master nan","nan"}));
  set("race", "human");
  set("level",77);
  set("max_hp",12000); 
  set("age",27);     
  set("title",HIG"南宮世家");
  set("nickname",HIC"世家心刀傳人"NOR);
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set_skill("sword",100);
  set_skill("blade",100);
  set_skill("block",100);
  set_skill("dodge",100);
  set_skill("blade",100);
  set_skill("whip",100);
  set_skill("axe",100);
  set_skill("force",100);
  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("anti_poison",100);
  set_skill("chess",100);
  set_skill("literate",100);
  set_skill("swim",100);
  set_skill("gun",100);
  set_skill("hammer",100);
  set_skill("bow",100);
  set_skill("throwing",100);
  set("devil",40000); 
  set("long",@LONG        
南宮問天的表弟，但一生作惡多端，最後被南宮鐵心、南宮問天
等人，施展封印術，封印在水星寒洞裡。
LONG); 
  setup(); 
  set_living_name("pool_npc");
  carry_object(__DIR__"obj/mie-blade")->wield();
  carry_object(__DIR__"obj/sky-pearl")->wear();
  carry_object(__DIR__"obj/dragon-boots")->wear();
  carry_object(__DIR__"obj/tiger-mask")->wear();
  carry_object(__DIR__"obj/purple-kasaya")->wear();
  set("actions", (: call_other, __FILE__, "query_action" :));

}
 mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
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
        message_vision(HIR"\n\t$N"HIR"在臨死之前，終於使出自我絕學─「"HIW"天外消遙篇"HIR"」！！"NOR,this_object());
        message_vision(HIY"\n\t$N"HIY"迅速反覆天外消遙篇心法，並將此絕學融會貫通！！"NOR,this_object(),ob);
        message_vision(HIG"\n\t熊熊真氣環繞在$N"HIG"周圍，頃刻間$N"HIG"使出天外消遙篇所有招式！！\n\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙"HIW"使出"HIG"天外逍遙篇"HIR"第一章"HIY"《"HIC"氣遊天地"HIY"》"HIW"熊熊靈氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙使出"HIG"天外逍遙篇"HIR"第二章"HIY"《"HIG"意守乾坤"HIY"》"HIW"熊熊霸氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙使出"HIG"天外逍遙篇"HIR"第三章"HIY"《"HIM"神馳物外"HIY"》"HIW"熊熊殺氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙使出"HIG"天外逍遙篇"HIR"第四章"HIY"《"HIC"逍遙無極"HIY"》"HIW"熊熊真氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙使出"HIG"天外逍遙篇"HIR"第五章"HIY"《"HIC""BLK"魔亟天下"HIY"》"HIW"熊熊滅氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIW"南宮無雙使出"HIG"天外逍遙篇"HIR"最終章"HIY"《"HIW"九"HIG"轉"HIY"邪"HIW"元"HIY"》"HIW"熊熊灰氣，包圍"HIR"$N"HIW"，然後猛力一擊向"+ob->name(1)+HIW"！！\n"NOR,this_object());
        message_vision(HIY"\t($n來不及閃躲，遭到$N"HIY"的猛烈攻擊)\n"NOR,this_object(),ob);
        message_vision(HIR"\n"+ob->name(1)+HIR"照單全收了$N"HIR"的天外逍遙篇攻擊，受到無比的創傷，身心俱疲！！\n"NOR,this_object());
        ob->receive_damage("hp",ob->query("hp")*19/20);
        COMBAT_D->report_status(ob);
        message("world:world1:vision",
                HIW"\n\t【"HIG"武林神話"HIW"】 "HIR"懷有一身武學南宮無雙，終究不敵"HIG+ob->name(1)+HIR"之力，敗戰了下來！！\n
                "HIM"\n\t屬於南宮無雙"HIM"的本命星頓時消逝無終！！\n\n"+NOR,users());
        ob->add("popularity", 5); //聲望
        tell_object(ob,HIG"(因為你殺死了南宮無雙，所以得到了 5 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}
