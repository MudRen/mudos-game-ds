/*  advanced thief master
 *
 *  By Tmr 2002/04/04
 */
#include <ansi.h>
#include <guild_mark.h>

inherit NPC;
varargs int receive_damage(string type, int damage, object who);

void combat_ai();

void create()
{
         set_name("賊帥", ({ "zei shuai master", "zei", "shuai", "master"}) );
        set("title", "飄渺九千里");
        set("gender", "男性");
        set("age", 40);
        set("long",@long
    賊帥是江湖上成名已久的盜中之王，妙手空空之技已達出神入化的
境界，探囊取物宛如吃飯一樣簡單，而他的暗殺技巧更是深不可測，在
千軍萬馬之中取人首級，易如反掌。賊帥俊偉的臉龐，帶著一絲蒼桑的
眼神，更添增他幾分魅力。
long
        );
        set("attitude", "peaceful");
        set("level",60);
        set("evil",50);
        set("race","evil");
        
        set_skill("unarmed", 95);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("dagger",100);
        set_skill("perception",100);
         set_skill("constant-virtue",50);
          set_skill("free_action",100);

        set_skill("aerial-dagger", 100);
        map_skill("dagger","aerial-dagger");
            set_skill("nine-waterfall", 100);
          set_skill("reachcloud-steps", 100);
          map_skill("dodge","reachcloud-steps");

        
        set_temp("apply/armor",150);
        set_temp("apply/dodge",50);
            
        set("chat_chance", 10);
        set("chat_msg", ({
                   (: command("wield dagger") :),
           }));

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ( {
                   (: combat_ai :),
                } ));

        //公會設定
        
        set("adv_class",2);
        set("class2","thief");
          set("class1","thief");
          set("guild_gifts",({3,7,0,10}));

        set("guild_skills",([
              "nine-waterfall":     ({100, 3, 30}),
              "stillhunt":     ({110,4,60}),
              "aerial-dagger":     ({110,4,90}),
              "reachcloud-steps":     ({110,3,80}),
              "free_action":     ({100,3,100}),
               "pick_lock":     ({100,3,100}),
                "perception":     ({100,3,100}),
        ])  );

        setup();
      carry_object(__DIR__"wp/cloud-together-dagger")->wield();
          carry_object(__DIR__"eq/dragon-shield")->wear();
    receive_money(5000);
}

void combat_ai() {
        // 生命不足，準備逃命.
        if( query("hp") < query("max_hp") /3 
           && !is_busy() && random(100) > 70 ) {
                this_object()->remove_all_killer();
                message("world:world1:vision",
        HIY"\n\n\t飄渺九千里 賊帥提氣縱聲長笑後，說道：「小子厲害，恕本賊帥不陪了。」\n\n"NOR
          HIG"\t賊帥輕巧巧地躍上數十丈高的半空，一個移形換位後，消失在遠方的天際。\n\n"NOR

                ,users());

                destruct(this_object());
        } else {
                command("wield dagger");
                command("exert nine-waterfall");
        }
}


// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

       if(random(100)<40)
        {
                damage/=3;
                message_vision(HIM "\n幾枚不知從何疾飛而來的銅幣擋住這次攻擊了！！" NOR,this_object());
        }


        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);


        return damage;
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_check_mark","apply");
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost=0;
        switch(argx)
        {
        // 特殊技能 cost 3
                case "aerial-dagger":
                case "reachcloud-steps":
                case "stillhunt":
                case "nine-waterfall":
                case "free_action":
                case "pick_lock":
                case "perception":

                cost=3;
                me->add("popularity",-cost);
        break;
        }
        return;
}

// advance  成功後 GUILDMASTER會自動呼叫
void advance_cost(object me,string arg)
{
        int cost;
        /* 提升等級(level)的聲望計算 */
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

int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class2")!="thief")
                return notify_fail("你並不在賊帥的門下。\n");
        if(mark=present("advanced thief dagger",me))
                return notify_fail("你已經有「盜賊的極致」了。\n");

        ob=new("/open/always/thief_adv_mark");

        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("你必須丟掉一些東西才拿的動本公會信物。\n");
        }
        ob->move(me);
        message_vision("$N拿了一"+ob->query("unit")+ob->name()+"給$n。\n",this_object(),me);
        me->save();
        return 1;
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);     
}

int do_skill_train(string arg)
{
         int j, cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(me->query("class2") != "thief" )
                return notify_fail("你並不在賊帥的門下。\n");
        switch(arg)
        {
                // 特殊技能 cost 3
              case "aerial-dagger":
              case "money-dart":
              case "reachcloud-steps":
              case "free_action":
              case "pick_lock":
              case "nine-waterfall":
                cost=3;
                // 一般技能 cost 0
                default:
                        cost=0;
        break;        
        } // end switch

        if( j < cost)
                return notify_fail("看來賊帥不想再指導你了。(除非你有"+cost+"點聲望)\n");
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        object ob, me,mark;
        int i;
  string guild_rank, title;

        ob = this_object();
        me = this_player();

        if(!arg) arg="thief";
        message_vision("$N想加入賊帥的門下。\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("你已經在賊帥的門下了。\n");break;
               case -2: notify_fail("你已經加入其他公會了。\n");break;
               case -8: notify_fail("此時此時並沒有這個門派。\n");break;
            }
        if(me->query("class2")=="thief")
                return notify_fail("你已在賊帥的門下了。\n");
        if( me->query("class1")=="thief" 
                        && me->query("level")==25 
                        && me->query("adv_class")==1 )
             {
                if( me->query_skill("stealing")<60 )
                        return notify_fail("由於你的偷盜能力不足，賊帥並不想收你。\n");
                if( me->query_skill("backstab")<60 )
                        return notify_fail("由於你的敵背突刺能力不足，賊帥並不想收你。\n");
                                
//        ob=new("/open/always/thief_adv_mark"); ob->mark by -alick
        mark = new("/open/always/thief_adv_mark");
                if(!mark->can_move(me))
                        return notify_fail("你必須丟掉一些東西才拿的動本公會信物。\n");
                if( !guild_rank = this_object()->guild_rank(me) || guild_rank=="")
                        guild_rank = "還很菜的新手小偷";
                me->set("guild_rank",guild_rank);
                if( !(title=me->query("title")) || title == "時空漂泊者" )
                        me->set("title", "傳說中的第三隻手"); // ps這是多加的, luky 記得要改成你要的喔！！
                mark->move(me);
                me->command("kneel shuai");
                message_vision(YEL "$N恭恭敬敬地向賊帥叩了幾個響頭，加入了他的門下。\n" NOR,me);
                tell_object(me,ob->name()+"從懷中拿出了一把"+mark->name()+"給你。\n");
                me->set("class2","thief");
                me->set("adv_class",2);
                return 1;
                }
        else return notify_fail("看起來賊帥並不想收你。\n");

        return 1;
}



int do_advance(string arg)
{
        object ob, me;
        int j,tot;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        //新修正，adv level 扣聲望 (lv-20)^2
        tot=(me->query("level")-20)*(me->query("level")-20);
        if( me->query("class2") != "thief") 
                return notify_fail("你並不在賊帥的門下。\n");
        if( (!arg || arg=="level")
            && j < tot )
                return notify_fail("你必須要有"+tot+"點聲望才能升級。\n");
        return GUILDMASTER->do_advance(ob,me,arg);

}
string guild_rank(object me)
{
        string rank;
        if( me->query("gender") == "女性" )
        {
                switch( me->query("level")/5 )
                {
                        case 0: rank = "笨手笨腳的小女賊"; break;
                        case 1: rank = "四處流竄的小女賊"; break;
                        case 2: rank = "技術純熟的女飛賊"; break;
                        case 3: rank = "難以捉摸的女盜賊"; break;
                        case 4: rank = "橫行霸道的女大盜"; break;
                        case 5: rank = "神出鬼沒的女神偷"; break;
                        default: rank = "神出鬼沒的女神偷";
                }
        }
        else
        {
                switch( me->query("level")/5 )
                {
                        case 0: rank = "笨手笨腳的笨小偷"; break;
                        case 1: rank = "動作靈活的小盜賊"; break;
                        case 2: rank = "技巧熟練的小飛賊"; break;
                        case 3: rank = "前科累累的老慣竊"; break;
                        case 4: rank = "橫行霸道的賊大哥"; break;
                        case 5: rank = "神出鬼沒神偷之王"; break;
                        default: rank = "神出鬼沒神偷之王";
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
        HIG"\t武林快報："HIW"飄渺九千里「賊帥」死在"+ob->name(1)+"的手中了！！\n"+NOR
        ,users());

        ob->add("popularity", 5); //聲望
        ::die();
        tell_object(ob,"  你得到五點聲望。\n");
        //destruct(this_object());
        return;
}

