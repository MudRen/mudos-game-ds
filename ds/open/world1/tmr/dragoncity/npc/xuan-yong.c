#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("宣永" , ({ "xuan yong master", "mo", "xuan","yong", "master" }) );
        set("long",@long
宣永是少帥軍的中堅份子，做人中肯有才氣，對少帥寇仲更鞠躬盡
瘁，死而後已。如今他擔任少帥軍新兵的招幕工作，如果你有意加入少
帥軍，可以跟他要求加入(join army)。
long
);
        create_family( "少帥軍", 2, "將軍");
        set("level", 40);
        set("race","human");
        set("age",45);
        set("class1","少帥軍");
        set("gender","男性");
        set("adv_class",1);
        set("guild_gifts",({8,8,0,4}));

        set_skill("unarmed",100);
        set_skill("blade",100);
        set_skill("bloodwar-blade",100);
        set_skill("flybird-steps",100);
         map_skill("dodge","flybird-steps");
         map_skill("blade","bloodwar-blade");

        set("guild_skills",([
               "bloodwar-blade" : ({130,3,70}),
               "flybird-steps" : ({130,3,80}),
               "nine-mystery" : ({130,3,50}),
               "dodge" : ({120,3,70}),
                 "blade" : ({120,3,70}),
               "parry" : ({130,2,70}),
               "unarmed" : ({130,3,70}),
                 "dragon-fist" : ({100,2,90}),
               "force" : ({130,3,50}),
        ])  );

                set("chat_chance", 5);
        set("chat_msg",({
                (: command("say 現在國家有難，是男子漢的就該立身報國！！") :),
                (: command("smile") :),
        }) );

        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
        carry_object(__DIR__"wp/steel-blade")->wield();
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
}


int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") == "少帥軍") return notify_fail("你已是少帥軍弟子了。\n");
        if( me->query("adv_class") ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "army") return notify_fail("你要拜入那一個門派?\n");
        if(me->query("gender")=="女性") {
                command("shake");
                command("say 妳一個女娃兒怎能上戰場殺敵呢。");
                return 0;
        }
        if(me->query_skill("blade")<5) {
                command("shake");
                command("say 我瞧你手無縛雞之力，怎能上戰場殺敵呢？去練練刀法吧");
                return 0;
        }
        command("say 好好好！！男子漢志在沙場。");
        command("say 你就加入少帥軍，替自已創立一翻大事業吧。");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","少帥軍");
        me->create_family("少帥軍",2,"軍人");
        me->set("guild_rank","少帥軍之用刀新手");
    me->set("guild_gifts", query("guild_gifts") );


        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="少帥軍") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是少帥軍子弟兵。\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        switch( lv )
        {
                case 0: rank = "少帥軍之用刀新手"; break;
                case 1: rank = "少帥軍之刀法高手"; break;
                  case 2: rank = "少帥軍之血戰沙場"; break;

        }
        return rank;
}

