#include <ansi.h>
inherit NPC;

void create() {
    set_name(HIY "楊過" NOR,({"Yang goo","goo"}) );
    set
        ("title",HIC "古墓" NOR);
    set
        ("long",
                "「楊過」是終南山活死人墓主人之一，生性平淡，因早期的兒女恩怨，\n"
                "使得他少了右臂。但此後連逢奇遇，反而武功\大進，為武林中一等一高手。\n"
                "目前與亦師亦妻的小龍女一起同住，也有幾位僕人，生活十分安逸。\n"
        );
    set
        ("race", "human");
    set
        ("unit","隻");
    set
        ("age", 38);
    set
        ("level", 45);
    set
        ("max_ap",6000);
    set
        ("max_hp",12000);
    set
        ("combat_exp",540000);
    set
        ("limbs", ( { "頭部", "腹部","胸部","手部","腳部"
                    }
                  ) );
    set
        ("chat_chance", 30);
    set
        ("chat_msg", ( {
                   (: command("exert ninning-force") :),
                               }
                             ));
    set
        ("chat_chance_combat", 50);
    set
        ("chat_msg_combat", ( {
                          (: command("exert heavy-sword") :),
                                          (: command("exert heavy-sword") :),
                                          (: command("exert heavy-sword") :),
                                          (: command("wield sword" ):),
                                          (: command("exert ninning-force heal") :),
                                          (: command("exert ninning-force heal") :),
                                      }
                                    ));

    set_skill("heavy-sword",100);
    set_skill("ninning-force",100);
    set_skill("anlan-fist",100);
    set_skill("force",100);
    setup();
    carry_object(__DIR__"sword")->wield();
      carry_object("/open/world1/moonhide/area/under/npc/obj/fire-fruit.c");
    carry_object(__DIR__"key");
	set_temp("apply/armor", 300);
	set_temp("apply/damage", 200);
}
int special_attack(object me,object target,int hitchance) {
    int tdex;
    if(!me || !target)
        return 0;
    // 30%機率發動特攻
    if( random(100) < 70 )
        return 0;

    //tdex = target->query_dex();
    //tcon = target->query_con();

    //if(random(hitchance*20) > tdex+tcon) {
        message_vision(HIY"\n$N"+HIW"臉色陰情不定，竟然使出"HIB"黯然銷魂掌"HIW"之「行屍走肉」\n"
                        +HIW"$n霋時間感受到數道雄厚的掌勁，一道竟是比一道還強！\n"
                       +HIR"$n被震退數十步，嘴巴胸口滿是自已的鮮血...\n\n"NOR, me, target);
         target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
        return 1;
	/*
    } else {
        message_vision(HIY"\n$N"+HIW"以極快的步調，以快打慢....\n"
                       +HIG"出招！一式"+HIC"千斤墜"+HIW"擊向$n..\n"
                       +HIW"$n有如被排山倒海的力量隨擊！\n"
                       +HIR"雙眼瞪大，充滿血絲，形成重創！\n\n"+NOR,me,target);
        target->receive_damage("hp",uery_damage()*3 + random(query_damage()), this_object());
        return 1;
    }
	*/
}
void die() {
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    
if( !ob ) {
        ::die();
        return;
    }

    message("world:world1:vision",
              HIR"\n\n【活死人墓】"+HIY " 西狂「神鵰俠」 楊過 竟然被"+ob->name(1)+"殺掉了！！\n\n"+NOR
            ,users());
    ob->add("popularity",3);
    // 仙人劍舞
    if(ob->query_temp("gumu_sword")==2) {
        "/open/world1/tmr/gumu/xuanya.c"->open_sword();
        ob->delete_temp("gumu_sword");
        message_vision("你好像覺得將有什麼奇妙的事情要發生了。\n",ob);
    } else {
        ob->set_temp("gumu_sword", 1);
        }
//    message_vision( "$N"+HIR  "猛吐了一口鮮血，兩眼直視遠方"+HIW"，接著 . . . . 就不支倒地了 . . "NOR ,this_object() );
    ::die();
    return;
}

