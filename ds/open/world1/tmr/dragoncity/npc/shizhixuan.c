#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("石之軒" , ({ "shi zhi-xuan master", "shi", "zhi", "xuan", "master" }) );
        set("long",@long
石之軒，黃易《大唐雙龍傳》小說裡的蓋代魔王。曾偽裝成裴矩潛伏於大隋宮中。
有雙重人格，時而為殺人不眨眼的絕代高手，時而為愁懷滿襟的騷人墨客與慈父。
與曾為慈航靜齋掌門的碧秀心生下一女，也就是當代吹簫高手石青璇。武功天下第
一，也高居魔門榜八大高手(又名邪派八大高手)首位。與魔門第一大門派陰癸派掌
門祝玉妍也有一段情，並使祝後由愛生恨，使出玉石俱焚絕招攻擊但仍難傷石之軒
要害。老石也是魔門密派花間派的傳人，徒弟皆為出類拔萃的兩位人物，分別是多
情公子侯希白及影子劍客楊虛彥，兩人均是小說中重要角色。
long
);
        create_family( "邪極宗", 14, "宗主");
       set("title", HIR"邪王"NOR);
        set("level", 70);
        set("race","tiger");
        set("age", 28);
        set("class1","邪極宗");
        set("class2","邪極宗");
        set("gender","男性");
        set("adv_class", 2);
        set("guild_gifts",({7, 4, 7, 2}));

        set_skill("force",100);

        set_skill("unarmed",100);
        set_skill("fork",100);
        set_skill("ablaze-pike",100);
        set_skill("unscar-steps",100);
        map_skill("dodge","unscar-steps");
        map_skill("fork","ablaze-pike");
         set_skill("constant-virtue",50);

        set("guild_skills",([
               "force" : ({130,3, 60}),
                  "purple-blood" : ({130,3, 40}),
        ])  );

        set("guild_spells",([
               "freely-vigor" : ({130, 3, 60}),
               "sorcery-lock" : ({130, 3, 60}),
        ]) );

        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil", -200);
        setup();
        set_temp("apply/sou", 3);
        set_temp("apply/bar", 3);
        set_temp("apply/armor", 300);
        set_temp("apply/armor", 150);
        set_temp("apply/shield", 150);
}

void init()
{
    ::init();
    add_action("do_skill_list","list");
    add_action("do_skill_train","train");
    add_action("do_spell_train","learn");
    add_action("do_join","join");
    add_action("do_advance","advance");
}

void combat_ai()
{
        return;
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}


int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        return 1;
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "邪極宗") return notify_fail("這兒不是你該來的地方。\n");
        if( me->query("class2") == "邪極宗") return notify_fail("你已是邪極宗的弟子了。\n");
        if( me->query("adv_class") == 2 ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "ancestor") return notify_fail("你要拜入那一個門派?\n");

        if( me->query("level") < 25 
                || me->query_skill("ablaze-pike") < 50
                || me->query_skill("unscar-steps") < 50
                || me->query_spell("sorcery-lock") < 50
                || me->query_spell("freely-vigor") < 50
        ) {
                command("shake");
                command("say 你再多去練練吧。");
                 return 0;
        }

        if(me->query("evil") < 200 ) {
                command("shake");
                command("say 你性格太過良善，不適合入我的門下。");
        return 0;
        }

        command("say 好！！你就加入我鬼王的門下，修鍊道心種魔大法，將魔門發揚光大。");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","邪極宗");
        me->create_family("邪極宗", 15, "邪人");
        me->set("guild_rank","邪極宗之由道入魔");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "邪極宗") return notify_fail("這裡不是你該來的地方。\n");
       //新修正，adv level 扣聲望 (lv-20)^2
        j = me->query("popularity");
        if(j < 3 ) return notify_fail("你的聲望不夠。\n");
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("你的聲望不夠。\n");

        return GUILDMASTER->do_advance(ob,me,arg);
}

// advance  成功後 GUILDMASTER會自動呼叫
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "邪極宗")
               return notify_fail("你並不是邪極宗的弟子。\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("看來石之軒並不想教你更深一層。(除非你有"+cost+"點聲望)\n");

        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_spell_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        switch( lv )
        {
                case 0: rank = "邪極宗之魔心乍現"; break;
                case 1: rank = "邪極宗之魔功\大成"; break;
                case 2: rank = "邪極宗之天魔臨世"; break;
                case 3: rank = "邪極宗之由道入魔"; break;
                case 4: rank = "邪極宗之道心種魔"; break;
                case 5: rank = "邪極宗之天魔屠神"; break;
        }
        return rank;
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
/*
        message("world:world1:vision",
                 HIR"\n【奧特蘭克】"HIY"已達天刀身意的邪極宗大元帥「寇仲」竟然飲恨在" +ob->name(1)+HIY"手裡了！！！\n\n"+NOR,users());
        ob->add("popularity", 6); //聲望
        tell_object(ob,HIW"(你得到了六點聲望。)"NOR);
*/

        ::die();
        return;
}

