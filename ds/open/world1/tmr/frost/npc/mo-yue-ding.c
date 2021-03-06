#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("莫月鼎" , ({ "mo yue-ding master", "mo", "yue","ding", "master" }) );
        set("long",@long
莫月鼎是寒澈派第二代掌門人，長的方面大耳，身材矮短，
可是瞧他整日笑容滿面，非常滿意自已的生活。
long
);
        create_family( "寒澈派", 2, "道長");
        set("level", 40);
	set("race","celestial");
        set("age",45);
        set("class1","寒澈派");
        set("gender","男性");
        set("adv_class",1);
          set("guild_gifts",({0,5,9,6}));
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("fall-thunder",100);
          set_skill("swallow-flying",100);
         map_skill("dodge","swallow-flying");

        set("guild_skills",([
               "dodge" : ({120,3,70}),
               "parry" : ({130,2,60}),
               "unarmed" : ({130,3,70}),
               "pick-plumblossom" : ({130,3,70}),
                 "swallow-flying" : ({130,3,80}),
                 "meditate" : ({130,3,80}),
        ])  );
        set("guild_spells",([
               "freeze-ball" : ({130,3,90}),
               "fall-thunder" : ({130,3,90}),
                 "life-death-symbol" : ({130,3,50}),
                   "ice-puppet" : ({130,3, 80}),
        ]) );
        
                set("chat_chance", 20);
        set("chat_msg",({
                (: command("smile") :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-60);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                carry_object(__DIR__"wp/taoism-claw")->wield();
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
                carry_object(__DIR__"eq/frosthands")->wear();
                carry_object(__DIR__"eq/frosthead")->wear();
                carry_object(__DIR__"eq/frostlegging")->wear();
                carry_object(__DIR__"eq/frostmask")->wear();
                carry_object(__DIR__"eq/frostneck")->wear();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
           carry_object("/daemon/spell/frost-obj/ice-puppet")->set("hp",4000);
        apply_condition("frost_harvest",100);
        apply_condition("frost_dust",100);
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");

        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
}

void combat_ai()
{
        int i;
        object *target;
        object liu=this_object();

        target = all_inventory(environment(liu));

        /* 武器被打掉，則裝回去 */
        if( !liu->query_temp("weapon") ) 
                command("wield fist");

        i = sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( !target[i]->is_busy() ) continue;
                        if( userp(target[i]) )
                                 command("cast fall-thunder on " + getuid(target[i]) );
                        else
                                command("cast fall-thunder on " + target[i]->query("id") );
                            return;
                }
        }
        // 找不到busy的敵人，就發封寒球
        command("cast freeze-ball");
        return;
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
        if( me->query("class1") == "寒澈派") return notify_fail("你已是寒澈派弟子了。\n");
        if( me->query("adv_class") ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "frost") return notify_fail("你要拜入那一個門派?\n");
        command("say 想要加入寒澈派修行啊？那你可清楚修鍊的最終目標嗎？");
        message_vision(YEL"$N跪下來大聲說道：召雷雨、破鬼神、功\與天合！！\n"NOR,me);
        command("say 好好好！！你就加入我們寒澈派好好潛心修練吧。");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","寒澈派");
        me->create_family("寒澈派",3,"道僮");
        me->set("guild_rank","寒澈派第三代道僮");
    me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="寒澈派") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是寒澈派弟子。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = "寒澈派第三代道僮"; break;
                        case 1: rank = "寒澈派第三代道姑"; break;
                        case 2: rank = "寒澈派之以心契道"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "寒澈派第三代道僮"; break;
                        case 1: rank = "寒澈派第三代道士"; break;
                        case 2: rank = "寒澈派之以心契道"; break;
                }
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
        message("world:world1:vision",
                HIG"\n【道派消息】"HIM"功\與天合的寒澈派觀主「莫月鼎」道長敗在" +ob->name(1)+"的手中了！！\n"+NOR,users());
        ob->add("popularity", 3); //聲望
          if( objectp(present("ice-puppet", this_object() ))) destruct(present("ice-puppet", this_object() ) );
        tell_object(ob,HIW"(你得到了3點聲望。)"NOR);
        ::die();
        return;
}

