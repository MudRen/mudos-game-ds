#include <ansi.h>
#include "/u/a/anfernee/anfernee.h"
inherit GUILDMASTER;    // 繼承 GUILDMASTER 並不需要再繼承 NPC

void create()
{
        set_name("新手導師", ({"master"}) );
    set("gender", "男性");
    set("combat_exp", 100000);
    set("long",
    "他是諸位新手的指導教師，提供基本的技巧訓練\n"
    "你可以使用"HIY"list"NOR"來看看有什麼技巧可以提供學習。\n");
        set("no_join", 1);
        set("level", 200);
        set("age", 50);
        set_skill("blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("guild_skills", ([  // // 難度, 等級1可學的上限, 上限
        "dodge":({30,5,40}),
        "blade":({50,5,35}),
        "sword":({50,5,35}),
        "parry":({30,5,40}),
        "unarmed":({40,5,40}),
        ]) );
        set("chat_chance", 5);
/*  set("chat_msg", ({
    "新手導師緩緩的道:"HIC"歡迎各位時空旅行者在這裡學習。"NOR"\n",
        "新手導師緩緩的在房間裡慢慢的走著。\n",
    }) ); */
        set("inquiry/master", "我就是新手導師\n");
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "新手導師道:"HIC"歡迎各位時空旅行者在此學習基本的�;
                        break;
                case 1:
                        break;
               }
}
