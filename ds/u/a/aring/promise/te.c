#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name("夢幻般的新手導師", ({"smaster"}) );
    set("gender", "男性");
    set("combat_exp", 100000);
    set("long",
    "他是諸位新手的指導教師，提供基本的技巧訓練。你可以\n"
    "使用"HIY"slist"NOR"來看看有什麼技巧可以提供學習(train)。也可\n"
    "以用advance <level或屬性> 來升級, 升級前建議先使用\n"
    "level 指令來查閱\所需要的經驗值。\n"
    );
        set("no_join", 1);
        set("level", 200);
        set("age", 50);
    set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
 setup();
         }
void die()
{
    object ob,scr;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        
        message("world:world1:vision",
HIC"夢幻般的新手導師，被默默無名"HIW"【"+ob->name(1)+"】"HIC"殺死了。\n"+NOR
        ,users());
          ob->add("popularity",5);

                 tell_object(ob,HIG "(你的聲望增加五點了。)\n" NOR );

        ::die();
        return;
}

