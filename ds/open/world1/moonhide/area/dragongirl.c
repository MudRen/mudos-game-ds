#include <ansi.h>

inherit NPC;

void create()
{
    set_name(HIY "小龍女" NOR,({"dragon girl","girl"}) );
    set
        ("title",HIC "古墓" NOR);
    set
        ("long",
                "小龍女是終南山活死人墓主人之一，長的有如仙女下凡，儀態優雅。\n"
                "年輕時就與楊過連逢許\多苦難，卻加深她們彼此的情意依舊，自與楊過結為\n"
                "夫妻之後，即深居古墓至今。"
        );
    set
        ("race", "human");
    set
        ("unit","隻");
    set
        ("age",45);
    set
        ("level",40);
    set
        ("gender","女性");
    set
        ("max_ap",4100);
    set
        ("combat_exp", 500000);
    set
        ("attitude", "heroism");
    set
        ("limbs", (
                    { "頭部", "腹部","胸部","手部","腳部"
                    }
                ) );
    add
        ("addition_armor",250);
    add
        ("addition_damage",200);
    set
        ("chat_chance_combat", 50);
    set
        ("chat_msg_combat", (
                    {
		                (: command("exert girl-sword") :),
		                (: command("exert girl-sword") :),
                                (: command("exert girl-sword") :),
                                (: command("wield sword") :),
                            }
                        ));
    set_skill("girl-sword",100);

    setup();
    carry_object(__DIR__"sword3")->wield();
      carry_object("/open/world1/moonhide/area/under/npc/obj/fire-fruit.c");
    carry_object(__DIR__"key2");
}

int special_attack(object me,object target,int hitchance)
{
    int tdex, dmg;
    if(!me || !target)
        return 0;
    if(random(10)<6)
        return 0;
    tdex = target->query_dex();
    if(random(hitchance*20) > tdex )
    {
        dmg=query_damage()/2 + random(query_damage());
        message_vision(HIW"\n$N"+HIW"拿出玉蜂漿，運起內力逼出陣陣香味，伸手向天空比劃了數下。\n"
                       +HIY"突然數十隻玉蜂從遠方嗡嗡飛來！！\n"
                       +HIM"$n摀著頭躲不開玉蜂的攻擊，發出一陣慘叫聲，滿頭都是包，性命堪憂！！！("+ dmg +")\n" NOR,me,target);
        
          target->receive_damage("hp", dmg, this_object());
        return 1;
    }
    return 0;
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
    message("world:world1:vision",
              HIR"\n【活死人墓】"HIY "「啊∼∼∼」小龍女在臨死之前對"+ob->name(1)+HIY"發出了幾聲哀嚎。\n\n"+NOR
            ,users());
    ob->add
    ("popularity",2); //聲望
    // 仙人劍舞
    if(ob->query_temp("gumu_sword")==1) {
        "/open/world1/tmr/gumu/xuanya.c"->open_sword();
        ob->delete_temp("gumu_sword");
        message_vision("你好像覺得將有什麼奇妙的事情要發生了。\n",ob);
    } else {
        ob->set_temp("gumu_sword", 2);
        }
    ::die();
    return;
}

