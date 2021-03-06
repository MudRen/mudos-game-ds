#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("雲中子" , ({ "yun zhong-zi master", "yun", "zhong","zi", "master" }) );
        set("long",@long
雲中子是寒澈派的創立始祖，仙風道骨，有如山澗之明月，
林間之朝露，清奇脫俗，遺世而獨立。雲中子可說是道教中近百
年來的第一人，修為已近乎天道。
long
);
        create_family( "寒澈派", 1, "真人");
          set("level", 55);
        set("race","celestial");
        set("age", 120);
        set("class1","寒澈派");
        set("class2","寒澈派");
        set("gender","男性");
        set("adv_class", 2);
       set("guild_gifts",({0,5,9,6}));
        set_skill("unarmed",100);
        set_skill("pick-plumblossom",100);
        set_spell("freeze-ball",100);
        set_spell("sevenfold-freeze",100);
        set_spell("thunder-doom",100);
        set_spell("fall-thunder",100);
          set_skill("constant-virtue",50);
        set_skill("swallow-flying",100);
        map_skill("dodge","swallow-flying");

        set("guild_skills",([
                 "meditate" : ({130,3,100}),
                 "pure-energy" : ({130,3, 60}),
                  "force" : ({130,3, 80}),
        ])  );
        set("guild_spells",([
               "life-death-symbol" : ({130,3, 90}),
               "ice-puppet" : ({130,3, 90}),
               "thunder-doom" : ({180,3, 40}),
               "sevenfold-freeze" : ({180,3, 40}),
        ]) );
        
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil",-180);
        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
                carry_object(__DIR__"eq/frostarmor")->wear();
                carry_object(__DIR__"eq/frostboots")->wear();
                carry_object(__DIR__"eq/frostcloth")->wear();
                carry_object(__DIR__"eq/frosthands")->wear();
                carry_object(__DIR__"eq/frosthead")->wear();
                carry_object(__DIR__"eq/frostlegging")->wear();
                carry_object(__DIR__"eq/frostmask")->wear();
                carry_object(__DIR__"eq/frostneck")->wear();
                  carry_object(__DIR__"wp/break-hell-claw")->wield();
        carry_object("/daemon/spell/frost-obj/ice-puppet")->set("hp", 40000);
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
        object target;

        // non-fight
        if(!is_fighting()) return; 

        target = select_opponent();
        /* 武器被打掉，則裝回去 */
        if( !query_temp("weapon") ) 
                command("wield fist");

        if(! target) return;

        if( target->is_busy() )
                command("cast thunder-doom");
        else 
                command("cast sevenfold-freeze");
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

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "寒澈派") return notify_fail("這兒不是你該來的地方。\n");
        if( me->query("class2") == "寒澈派") return notify_fail("你已是寒澈派弟子了。\n");
        if( me->query("adv_class") == 2 ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "frost") return notify_fail("你要拜入那一個門派?\n");

        if( me->query("level") < 25 
        || me->query_spell("fall-thunder") < 75
        || me->query_spell("freeze-ball") < 75
        || me->query_spell("life-death-symbol") < 50
        ) {
                command("shake");
                command("say 你再多去練練吧");
        return 0;
        }

        command("say 好好好！！我瞧你刻苦修練也到一定程度了，你就加入我的門下吧。");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","寒澈派");
        me->create_family("寒澈派", 2,"道人");
        me->set("guild_rank","寒澈派第二代道人");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "寒澈派") return notify_fail("這裡不是你該來的地方。\n");
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

        if(this_player()->query("class2") != "寒澈派")
               return notify_fail("你並不是寒澈派弟子。\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("看來雲中子並不想教你更深一層。(除非你有"+cost+"點聲望)\n");

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

int do_spell_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "寒澈派")
               return notify_fail("你並不是寒澈派弟子。\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("看來雲中子並不想教你更深一層。(除非你有"+cost+"點聲望)\n");

        return  GUILDMASTER->do_spell_train(ob,me,arg);
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
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
                        case 0: rank = "寒澈派第三代道僮"; break;
                        case 1: rank = "寒澈派第三代道姑"; break;
                        case 2: rank = "寒澈派之以心契道"; break;
                        case 3: rank = "寒澈派之羽化成仙"; break;
                        case 4: rank = "寒澈派之功\與天合"; break;
                        case 5: rank = "寒澈派之仙風道骨"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "寒澈派第三代道僮"; break;
                        case 1: rank = "寒澈派第三代道士"; break;
                        case 2: rank = "寒澈派之以心契道"; break;
                        case 3: rank = "寒澈派之羽化成仙"; break;
                        case 4: rank = "寒澈派之功\與天合"; break;
                        case 5: rank = "寒澈派之仙風道骨"; break;
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
                HIG"\n【道派消息】"HIM"仙風道骨的寒澈派始祖「雲中子」真人竟敗在" +ob->name(1)+"的手上了！！\n"+NOR,users());
        ob->add("popularity", 3); //聲望
          if( objectp(present("ice-puppet", this_object() ))) destruct(present("ice-puppet", this_object() ) );
        tell_object(ob,HIW"(你得到了3點聲望。)"NOR);
        ::die();
        return;
}

