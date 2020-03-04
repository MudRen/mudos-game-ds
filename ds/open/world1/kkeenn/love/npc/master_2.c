#include <ansi.h>
inherit NPC;
void auto_load();
void create()
{
        set_name(HIY"香香"NOR,({"master sen","master","sen"}));
        set("gender", "女性");
        set("long",@LONG
香香師尊為情城池的創派祖師，更是一個風華絕代，
容姿優雅至無以復加的清逸美女，身長玉立，弱質纖
纖中透出無比堅強的氣質。清澈的眸子閃動著深不可
測的智能
(情城池中人參加考驗請打exam。)
LONG
        );

          set("level",60);
        set("age",50);
        set("adv_class",2);
        set("attack_merits","bio");
        set("class1","情城池");
        set("class2","情城池");
        set("title","《情城池》開城祖師");
        set("nickname",HIM"蓮池仙尊"NOR);
        set("addition_damage",60);
        set("addition_armor",140);
        set("MKS",150);
        set_skill("seven-love", 100);
          set_skill("thousand-hair", 100);
        set_skill("masen_whip",100);
        set_skill("run_cloud",100);
        set_skill("force",100);
          set_skill("broken-hearted",100);
        map_skill("whip", "masen_whip");
        map_skill("dodge", "run_cloud");
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
    (:command("exert broken-hearted"):),
  (:command("exert masen_whip"):),
}));

        set("chat_chance", 40);
        set("chat_msg",({
               (:auto_load:), 
                (:command("hmm"):),
	(:command("wield whip") :),
        }) );
        set("guild_skills",([ 
            "force":({130,2,80}),
            "seven-love":({140,2,90}),
              "thousand-hair":({140,2,90}),

        ]) );
          set("guild_gifts",({4,6,3,7}));


        setup();
          carry_object(__DIR__"obj/dragon_whip")->wield();
              if(random(10)<2)
                carry_object(__DIR__"obj/moon-star_cloth")->wear();
            else
                carry_object(__DIR__"obj/moon-star_cloth2")->wear();
                carry_object(__DIR__"obj/silk-gloves")->wear();

            carry_object(__DIR__"obj/pill8");

    set_temp("apply/shield",180);
    set_temp("apply/armor",180);
    set_temp("apply/damage",100);
        add_money("coin",4000);
        set_temp("apply/bio",3);
}
void init()
{
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
        add_action("do_skill_list","list");
        add_action("do_exam","exam");
        add_action("do_skill_train","train");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
 }
void train_skill_cost(object me,string argx)
{
   me->add("popularity",-1);
   return;
}
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

        return;
}
}
int do_skill_list(string arg)
{
        if(this_player()->query("class2") != "情城池") 
           return notify_fail("你並不是情城池進階弟子哦。\n");
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); 
        write("\n");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class2") != "情城池") return notify_fail("你並不是情城池進階弟子哦。\n");
        if( this_player()->query("popularity") < 2 ) return notify_fail("你的聲望不夠，看來香香並不想教你。");
        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}
int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();
// if(me->query("race") != "human" ) return 0; 不限定 race , by whoami
if(me->query("class2") == "情城池" ) return notify_fail("你已經是情城池的進階弟子了吧？\n");
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
               case -1: notify_fail("你已是其他門派的徒弟了\n");break;
               case -2: notify_fail("你已是其他門派的徒弟了\n");break;
                case -8: notify_fail("沒有這個門派吧");break;
        }

if( me->query("class1")=="情城池" && me->query("level")==25)
         {       
            command("say 很好！很好！你是我徒弟的徒弟，算來也是我的徒孫。");
            command("say 以後有什麼武術不懂的，就來找我，我給你指點指點。");
            command("pat " + me->query("id") );
message("world:world1:vision",HIY "\n\t《情城快報》：蓮池仙尊 香香正式收了"+me->name(1)+HIY "為真傳弟子。\n"NOR,users() );
            me->set("class2","情城池");
            me->create_family("情城池",2,"弟子");
            me->set("guild_rank","情城池之進階弟子");
            me->set("adv_class",2);
         }
          else    
          {
            command("say 這位"+ RANK_D->query_respect(me) +"我並不想收你為徒。\n");
          }
        return 1;
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(me->query("class2") != "情城池") 
            return notify_fail("你並沒有入進階情城池。\n");
        if(me->query("popularity") < 3 ) 
            return notify_fail("你的聲望不夠，無法再升上去哦。\n");
        //新修正，adv level 扣聲望 (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("你的聲望不夠。\n");
        else return GUILDMASTER->do_advance(ob,me,arg);

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
                                // LV 1 ~ 9
                        case 0: rank = HIM"情城池之真傳弟子"NOR; break;
                                // LV 10 ~ 19
                        case 1: rank = HIM"情城池之真傳弟子"NOR; break;
                        case 2: rank = HIM"情城池之真傳弟子"NOR; break;
                                // LV 30 ~ 39
                        case 3: rank = HIC"蓮池再現鞭氣雙修"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIW"情城池之百年奇才"NOR; break;
                                // LV 50
                        default: rank = HIW"【"HIM"絕情 "HIC"•"HIR" 滅道"HIW"】"NOR;
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
message("world:world1:vision",HIW"\n  江湖上再傳震撼:"HIW"\n\n\t情城池之蓮池仙尊˙香香在"+ob->name(1)+"手上意外地敗北了！\n\n"+NOR,users());
         ob->add("popularity", 6); 
         tell_object(ob,HIW"(因為你殺死了蓮池仙尊，所以得到了 6 點聲望。)"NOR);
         "/open/world1/kkeenn/love/room30"->open_star(); // 自然奇觀
         ::die();

        return;
}
int do_exam(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class1") != "情城池") return notify_fail("你並不是情城池弟子哦。\n");
	if( !this_player()->query("class2") )
	{
		command("yawn "+this_player()->query("id"));
		return 1;
	}
         command("say 嗯，你真的確定要參加考驗嗎？[你已經通過"+ me->query("quest/win")+"次][answer yes/no]");
       add_action("do_answer", "answer");
        return 1;
}
int do_answer(string arg)
{
        object me,b;
        me=this_player();
  if(!arg) return notify_fail("你到底來這裡要幹麻阿 ?\n");
 if(arg=="yes")
 {
//mark by -Acme- message("world:world1:vision",HIM"\n《情城快報》：\n\t"HIW"情城池弟子"HIW+me->name()+HIM"，參加了情城池出師大考驗，請各位幫他加油！\n"NOR,users() );
 write("香香師祖偷偷塞了一枚丹藥給你，望你好好利用。\n");
 new(__DIR__"obj/pill10.c")->move(me);
            me->set_temp("kill_love",1);  
      me->move(__DIR__"../room1.c"); 
if( sizeof(filter_array( children(__DIR__"killer"), (: clonep :) )) < 2 )
{
     b = new(__DIR__"killer")->move(__DIR__"../room8");
     b = new(__DIR__"killer")->move(__DIR__"../room9");
}
 message_vision(HIR+me->query("name")+"滿臉殺氣的衝進來！\n"NOR,me); 
              return 1;
 }
 if(arg=="no")
 {             
        return notify_fail(HIW"〈你放棄參加測驗的機會。〉\n"NOR);
 }
 return notify_fail("你到底要不要參加阿(yes),(no) ?\n");
}
void auto_load()
{
        object me=this_object();
        if(me->query("auto") > 0)
        {
 message_vision(HIG+me->query("name")+HIG"輕輕的拍拍"HIW"天山雪"HIG"的頭。\n"NOR,me); 
 message_vision(HIG+me->query("name")+HIG"慢慢的向上一縱，消失在眾人的眼前。\n"NOR,me); 
        me->move(__DIR__"../room30");
    me->delete("auto");
        }        
        return;
}
