#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("厲若海" , ({ "li ruo-hai master", "li", "ruo","hai", "master" }) );
        set("long",@long
厲若海，黃易《覆雨翻雲》一成功人物，書中所寫不多，但人物的性格已經十分突
出。一看厲若海出場，就有如看一名騎戰馬的勇武將軍一樣，令人感到哪種肅殺豪
情，厲若海天生是眾人的焦點，但不是因為他武功極高，而是他哪種專心對武道的
追求，即使是敗在龐斑之下，但無人敢譏笑他不自量力挑戰龐斑，因為膽敢挑戰龐
斑的人已經不多了。
如果你有意加入邪極宗，可以跟他要求加入(join ancestor)。
long
);
        create_family( "邪極宗", 15, "宗主");
        set("level", 50);
        set("race","tiger");
        set("title", HIR"邪靈"NOR);
        set("age", 48);
        set("class1","邪極宗");
        set("gender","男性");
        set("adv_class",1);
          set("guild_gifts",({7,4,7,2}));

        set_skill("unarmed",100);
        set_skill("fork",100);
        set_skill("ablaze-pike",100);
        set_skill("unscar-steps",100);
        map_skill("dodge","unscar-steps");
         map_skill("fork","ablaze-pike");

        set("guild_skills",([
                "ablaze-pike" : ({130,3, 60}),
               "unscar-steps" : ({130,3, 60}),
               "dodge" : ({120,3,70}),
               "fork" : ({120,3,70}),
               "parry" : ({130,2,70}),
               "unarmed" : ({130,3,70}),
        ])  );

        set("guild_spells",([
               "freely-vigor" : ({130,3, 60}),
               "sorcery-lock" : ({130,3, 60}),
        ]) );


        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
        carry_object(__DIR__"wp/red-pike")->wield();
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
        if( me->query("class1") == "邪極宗") return notify_fail("你已是邪極宗弟子了。\n");
        if( me->query("adv_class") ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "ancestor") return notify_fail("你要拜入那一個門派?\n");
         if(me->query("evil")< 10) {
                command("shake");
                command("say 你本性太過善良，不適合加入邪極宗。");
                return 0;
        }
        command("spank");
        command("say 本派槍法魔功\並重，你可要好好用心習武，可別丟了本派的臉。");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","邪極宗");
        me->create_family("邪極宗",2,"弟子");
        me->set("guild_rank","邪極宗之魔心乍現");
        me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="邪極宗") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是邪極宗弟子。\n");
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

        }
        return rank;
}

