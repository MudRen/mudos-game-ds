#include <ansi.h>
inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void special();
void create()
{
        set_name(HIW"天山雪"NOR,({"master tain","tain","master"}));
        set("long" ,
"情城池的第二代城主，其之震城絕技[滅神鞭法]已再武林中排名前十，絲毫\n"
"不輸給鬚眉，有著雙重的性個，無論是武功\或是智慧，均已達至化境，是一\n"
"名深不可測的女鞭手。\n");
        set("nickname", HIR"滅情絕道"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","女性");
        set("combat_exp", 100000);
        set("level", 50);
        set("title","《情城池》第二代城主" );
        set("max_ap",3000);
        set("MKS",150);
        set("class1","情城池");
        create_family("情城池",15,"第二代城主");
        set_temp("apply/armor",30);
        set_skill("seven-love",100);
        set_skill("masen_whip",80);
        set_skill("force",100);
        set_skill("run_cloud",75);
        map_skill("whip","masen_whip");
        map_skill("dodge","run_cloud");
        set("guild_gifts",({ 4,6,4,6 }));
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "whip" : ({ 110,3,80 }),
  "parry":({ 130,2,60 }),
 "masen_whip" : ({ 150,3,80 }),
  "force" : ({ 135,3,85 }),
  "unarmed" : ({ 100,3,80 }),
"run_cloud" : ({ 140,3,80 }),
]));
        set("no_check_class",1);
        set("adv_class",1);
        set("chat_chance",8);
        set("chat_msg", ({
  "天山雪望著窗外，似乎在思念著某人。\n",
  (:command("sigh"):),
	(:command("wield whip") :),
  
}));
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
                          (:special:), 
  (:command("exert masen_whip"):),
        (:command("wield whip") :),
        (:command("wield whip") :),
  (:command("exert masen_whip"):),
}));
        set("inquiry/某人","我正在思念我師祖(妙法仙尊)，你有看到她嗎？\n");
        set("inquiry/妙法仙尊","她老人家好像一直躲在這城中的某一處吧？\n");
        setup();
  carry_object("/open/world1/kkeenn/love/npc/obj/blood_whip")->wield();
  carry_object("/open/world1/kkeenn/love/npc/obj/ten_pearl")->wear();
  add_money("coin",3000);
        }

void init()
{
        object me=this_player();
        object ob=this_object();
   object npc,room;
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
        room=load_object(environment(this_object())->query("exits/up"));
 if( room && objectp(npc = present("sen",room)))
    {
tell_object(me,HIG"樓上嬌喝一聲，一道急速無比的黑影向你衝來！\n"NOR);     
tell_object(me,npc->name()+HIG"說道：山雪，莫驚！為師來助你一臂之力！\n"NOR);     
tell_object(me,npc->name()+HIG"大聲喝道：惡賊！死來吧！\n"NOR);     
   npc->set("auto",1);
	npc->move(environment(this_object()));
    }
                        return;
        }
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
//        add_action("do_guard","go");
        add_action("do_advance","advance");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
        object ob=this_object() , me=this_player();
        string gender;

        if( !arg && !me->query_temp("join_l") )
                return notify_fail("你想要加入什麼門派呀？(join 情城池)\n");
        if( me->query("gender") == "男性" )
                return notify_fail("天山雪說: 很是抱歉，本城是不接受男性的。\n");

        if( me->query_temp("join_l") && !arg ) arg = "情城池";
        if( strsrch(arg, "情城池") == -1 || strsrch(arg, "不") > -1)
                return notify_fail("你想要加入什麼門派呀？(join 情城池)�)\n");
        if( me->query("gender") == "女性" ) gender="姑娘";
        else gender = "兄弟";
    message_vision("$N想加入「"+ HIM"" + arg + ""NOR+ "」。\n",me); 

        if( me->query("class1") )
                return notify_fail("你已是"+me->query("class1")+"的弟子了。\n");
        if( me->query("family/family_name")=="情城池" )
                return notify_fail("你已是天山雪的徒弟了。\n");
        if( !me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say 這位"+gender+"可否幫我完成一件事？");
                tell_object(me, ob->name()+HIG"在你耳邊說道："+gender+"可否幫我幫我留意一下敝師祖最近的狀況？\n"NOR);
                tell_object(me, ob->name()+HIG"在你耳邊說道：只要跟她老人家說一聲[您最近好嗎?]，這樣我就滿足了。\n"NOR);
                me->set_temp("ljoin",1);
                return 1;
        }
        else if( me->query_temp("ljoin") && !me->query_temp("join_l") ) {
                command("say "+gender+"見到我師祖了嗎？");
                return 1;
        }
        else {
                command("bow "+me->query("id"));
                me->set("guild_rank","情城池之入門學徒");
message("world:world1:vision",
HIM"\n\t《情城消息》："HIR"滅情絕道 "HIW"天山雪"HIM" 收了"+me->name(1)+HIM"為情城池入室弟子。\n"NOR,users() );

                message_vision("$N成為情城池的弟子。\n",me);
                me->set("class1","情城池");
                me->create_family("情城池",3,"弟子");
                me->set("adv_class",1);
                return 1;
        }
//      return 1;
}

int do_advance(string arg)
{
//        if (this_player()->query("family/family_name")=="情城池") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        if (this_player()->query("class1")=="情城池" && !this_player()->query("class2") ) return GUILDMASTER->do_advance(this_object(),this_player(),arg);
        else return notify_fail(this_object()->query("name")+"並沒有理會你。\n");
}

int accept_object(object me, object ob)
{
        object tob, herb,a;
        tob = this_object();
        if( ob->query("id")!="ron letter" ) return 0;
        if( me->query("gender")!="女性" ) 
               return notify_fail("天山雪說: 很是抱歉，本城是不接受男性的。\n");
        else {
                command("thank "+me->query("id"));
command("say "+RANK_D->query_respect(me)+"既助山雪消除疑惑，就讓山雪收"+RANK_D->query_respect(me)+"為徒吧！\n");
                message_vision("$N將$n在掌心中一揉，$n就化為片片的紙蝴蝶飛去，煞是好看。\n", this_object(), ob);
                tell_object(me,HIR"請在打一次("HIY"Join 情城池"HIR")以便山雪收你為徒。\n"NOR);
                me->delete_temp("ljoin");
                me->set_temp("join_l",1);
                destruct(ob);
        }
        return 1;
}

string guild_rank(object me)
{
        string rank;
        int lv,steps,whip;
        steps = me->query_skill("dodge");
        whip = me->query_skill("whip");
        lv = me->query("level");
        lv = lv/6; 
        if ( whip > 35 && whip > steps - lv*4 )
        {
                if ( whip > 99 ) rank = HIM"情城池之鞭法仙子"NOR;
                else if ( whip > 70 ) rank = HIW"情城池的鞭法教練"NOR;
                else if ( whip > 35 ) rank = HIC"情城池的鞭法學徒"NOR;
        }
        else if ( steps > 40 )
        {
                if ( steps > 99 ) rank = HIC"日行萬里追雲流步"NOR;
                else if ( steps > 75 ) rank = HIW"情城池之千里報馬"NOR;
                else if ( steps > 40 ) rank = HIM"情城池的步法學徒"NOR;
        }
        else
        {       switch( lv )
                {
                        case 0: rank = HIR"情城池之紅衣弟子"NOR; break;
                        case 1: rank = HIB"情城池之藍衣弟子"NOR; break;
                        case 2: rank = HIW"情城池之白衣弟子"NOR; break;
                        case 3: rank = HIY"情城池之黃衣弟子"NOR; break;
                        case 4: rank = MAG"情城池之紫衣弟子"NOR; break;
                        default: rank = HIC"情城池下任八仙子"NOR;
                }
        }
        return rank;
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

	if( this_object()->query_temp("flee") )
	{
		this_object()->set("hp", this_object()->query("max_hp") );
		call_out( (:destruct(this_object()) :), 1);
			return;
	}

        if( !ob ) 
        {
                ::die();
                return;
        }
        if( ob->query_temp("kill_love") ) 
        {
        if( ob->query("class1") == "情城池" ) 
        {
message("world:world1:vision",
HIY"\n\n《大放異彩》"HIM":\n\n\t情城池弟子 "+ob->name()+HIM"通過情城池的大考驗！\n\n"+NOR
        ,users());
     ob->add("quest/win",1);
if ( ob->query("quest/win") < 10 )
      {  
          ob->set("title","情城池之出師弟子"); 
      } 
if ( ob->query("quest/win") > 10 )
      {  
          ob->set("title","情城池第四代仙子");
      }
if ( ob->query("quest/win") > 20 )
      {  
          ob->set("title","情城池第四代殺手");
      }
 if ( ob->query("quest/win") > 50 )
      {  
          ob->set("title","情城池第四代護法");
      }
 if ( ob->query("quest/win") > 100 )
      {  
          ob->set("title","《情城池》副城主");
      }
 if ( ob->query("quest/win") > 500 )
      {  
          ob->set("title","情城池第四代城主");
      }  
if ( ob->query("quest/win") > 1000 )
      {  
          ob->set("title","情城池之方外長老");
      } 
        ob->delete_temp("kill_love");
	ob->add("popularity", 7); 
        ob->set("guild_rank",HIW"【"HIR"血手情"HIC"冰心城"HIW"】"NOR);
        message_vision(HIW"$N因為通過情城池的考驗，所以獲得7點聲望\n"NOR,ob);
                ::die();
                return;
        }
message("world:world1:vision",
HIR"\n  《武林紅帖》"HIM":\n\n\t情城池一派被"+ob->name()+HIM"擊敗，在江湖上被除名了！\n\n"+NOR
        ,users());
	ob->add("popularity", 7); 
        ob->delete_temp("kill_love");
        ob->set("guild_rank",HIW" 【"HIC"徒手"HIR"滅"HIM"情城"HIW"】 "NOR);
        message_vision(HIW"$N因為滅了情城池一派，所以獲得7點聲望\n"NOR,ob);
                ::die();
                return;
        }

        message("world:world1:vision",
HIR"\n  《情城慘劇》:\n\n\t"HIM"情城池第二代城主 "HIW"天山雪"HIM"慘遭"+ob->name(1)+"的魔爪！\n\n"+NOR
        ,users());
        ob->add("popularity", 3); 
        ::die();
        return;
}
int do_guard(string arg)
{
        if( this_player()->query("class2") == "情城池") return 0;
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("sorry");
           say(HIW"天山雪"NOR"說道："HIG"對不起，上面是本派的重地。\n"NOR);
        return 1;
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;
       object targets;
        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(150)<30)
                {
                        damage/=2;
                        message_vision(HIM "\n$N將手中鞭子轉出九九八十一個圈子，化去了強大的攻勢。\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
 if(query("hp")<query("max_hp")/8 && !is_busy() && !this_object()->query_temp("flee") && random(100) > 80 ) 
           {
	object *go;
//        if( !go = query_temp("last_damage_from") )
//        go = this_player(1);
	go = this_object()->query_enemy();
                this_object()->remove_all_killer();
           command("hehe");
           this_object()->set_temp("flee", 1);
           command("bye");
  message("world:world1:vision",HIM "\n天山雪清笑一聲，回身飛上屋簷說道：\n\n\t\t\t此次雖敗，下次定是取你們狗命時，高山流水...再會啦~~哈~~哈~~。\n" NOR,users());
        if(go) 
	{
		foreach(object each in go)
	{
		if( !query_temp("added") )
		{
                each->add("popularity" ,1);
		each->delete_temp("kill_love");
		this_object()->set_temp("added", 1);
		}
	}
	}
     this_object()->move(__DIR__"../room30");  
	this_object()->set("hp", this_object()->query("max_hp") );
                call_out( (:destruct($1):),1,this_object() );
           }

                return damage;
}

void special()
{
        object me=this_object();
        object* target; 
        int dam = 400 + random(me->query_skill("unarmed"));   
        if(me->is_busy() ) return;
        target=query_enemy();
      message_vision(HIW"\n$N將手中的鞭子交至左手，運起自創著神秘絕招\n\t\t【"HIR"絕情滅道"HIW"】！！\n一股不失強大又兼有無比悲傷的真氣迎面向$n席捲而去，$n在措手不及的情況之下\n那股真氣直接命中$n的胸腔，$n突然變的雪白，似乎是受到十分嚴重的內傷！",me,target);
        target->receive_damage("hp",dam,me);
        message_vision("造成$N" +dam+ "點的傷害。\n",target);
    return;
}
