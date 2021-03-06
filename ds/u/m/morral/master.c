#include <ansi.h>

inherit NPC;
//inherit GUILDMASTER;    // 新版的GUILDMASTER 可以不用繼承

void create()
{
	set_name("新手導師", ({"master"}) );
    set("gender", "男性");
    set("combat_exp", 100000);
    set("long",
    "他是諸位新手的指導教師，提供基本的技巧訓練。你可以\n"
    "使用"HIY"list"NOR"來看看有什麼技巧可以提供學習(train)。也可\n"
    "以用advance <level或屬性> 來升級, 升級前建議先使用\n"
    "level 指令來查閱\所需要的經驗值。\n"
    );
	set("no_join", 1);
	set("level", 200);
	set("age", 50);
    set_skill("unarmed", 100);
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

//  carry_object(__OBJ__"blade")->wield();
//  carry_object(__OBJ__"cloth")->wear();
//  carry_object(__OBJ__"boots")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("d_advance","advance");
        add_action("d_list","list");
        add_action("d_train","train");
}

int d_advance(string arg)
{
 return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int d_list(string arg)
{
 return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int d_train(string arg)
{
 return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
			say( "新手導師道:"HIC"歡迎各位時空旅行者在此學習基本的技巧。"NOR"\n");
                        break;
                case 1:
                        say( "新手導師道:"HIY"這裡將會提供各位免費的學習。"NOR"\n");
                        break;
               }
}
