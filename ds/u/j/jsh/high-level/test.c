#include <ansi.h>
inherit NPC;  
mapping *combat_action = ({
        ([      "action":       "$N向上一跳，一劍往$n的$l定了下去！",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "劍傷",
        ]), 
        ([      "action":       "$N大邁橫步，隨及將手中之劍，往$n的$l劃了一個十字",
                "attact_type":  "tec",
                "damage_type":  "劃傷",  
        ]),
        ([      "action":       "$N閉眼以氣流感應$n的招式，$n不料被看破，被$N狠狠刺上一劍",
                "attact_type":  "bio",
                "damage_type":  "刺傷",
        ]),
});  
void heal(); 
//void let_delay();
void create()
{
        set_name(HIC"玄外老人"NOR,({"master shang-wai old-man","man","master","old","shang","wai"}));
        set("long" ,@LONG  
疾風門創始人軒轅烈的哥哥，在武學境界上，比軒轅烈更高一層
，只是玄外老人喜愛和平的環境，在休憩的空閒，會想想劍法的
招式，如今它獨創出疾風門所無法練就的劍法，如果你想拜他為
師，嗯..想想辦法吧，說不定他會收你。 
[PS:玄外老人喜歡聊有關於劍的東西，你可以跟它聊聊(cchat)，說不定會有些收穫。]
LONG
);
        set("nickname", HIC"天疾門"NOR );
        set("attitude", "friendly"); 
        set("age", 90); 
        set("no_fight",1);
        set("gender","男性");
        set("combat_exp", 450000);
        set("level", 60);
        set("title",HIR"神  技"NOR);
        set("max_ap",20000); 
        set("max_hp",10000);//老人..hp少一點
        set("max_mp",20000);
        set("class1","疾風門"); 
        set("class2","天疾門"); 
        set("flurrydodge",1);
        set_temp("apply/armor",200);
        set_skill("fogseven",100);
        set_temp("sorgitimes",20);
        set_skill("unarmed", 100);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",100); 
        set_skill("sevenstar-sword",100); 
        set_skill("star-sword",100);
        set_skill("sorsin-force",100);     
        map_skill("sword","star-sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 3,5,5,7}));   //總合=20
//      工會導師可以教授的技能列表
        set("guild_skills",([
  "sorsin-force" : ({ 175,5,100 }), 
]));

        set("no_check_class",1);
        set("adv_class",2);
        set("chat_chance",8);
        set_temp("class_wind/power",400);
        set("chat_msg", ({
  "天疾輕輕揮舞著手中的劍，慢慢提腿，劍氣快，出招慢。\n",  
  (:command("smile"):), 
  (:command("sigh"):),
  (:command("hmm"):), 
  (:heal:),  
  (:command("exert moon_force recover"):), 
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",33);
        set("chat_msg_combat",({
  (:command,"exert star-sword tian":),
  (:command,"exert star-sowrd nine":),
  (:command,"exert star-sword penuma-sword":),
  (:command,"exert sorsin-force":),
  (:command("exert moon_force moon-arc"):), 
  //(:let_delay:),
}));
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object("/u/j/jangshow/sword")->wield();
       // carry_object(__DIR__"eq/sandal")->wear();
} 
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];  
} 
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");      
        add_action("do_cchat","cchat");
        add_action("do_no","no");
        add_action("do_yes","yes");   
        add_action("do_thief","thief");
        add_action("do_nod","nod");
        add_action("do_give","give");
        if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        add_action("do_for","for");}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // 避免列出檢查職業的訊息
        write("\n");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}   
int do_thief(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!arg||arg!="thief")
      return notify_fail("什麼?\n");
    if(!me->query("class1")=="盜賊工會") return 0;
    {
    message_vision("玄外老人說：喔∼你是盜賊？\n",me);
    me->add_temp("tf",1);
    }
    return 1;
}
int do_nod(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!me->query_temp("tf")==1) return 0;
    if(arg!="master") return notify_fail("nod master即可.\n");
    message_vision("$N對玄外老人點了點頭。\n",me);
    {
    message_vision("玄外老人對$N說了一些悄悄話..\n",me);
    tell_object("你去幫我弄個東西好嘛..?去幫我搞一套靈魂甲..好後交給我就可以了...我會給你獎賞的。\n",me);
    me->delete_temp("tf");
    me->add_temp("soul_armpr",1);
    }
    return 1;
}
int do_give(string arg)
{
    object obj,me=this_player(),ob=this_object();
    if(!me->query_temp("soul_armor")==1) return 0;
    if(arg !="soul armor")return notify_fail("你要給什麼?\n");
      {
      message_vision("$N給玄外老人一件靈魂甲\n",me);
      ob->command(:wear armor:);
      obj=new(__DIR__"obj/perple-dagger");
      obj->move(ob);
      //ob->command(:give dagger to "+me->
      me->delete_temp("soul_armor");
      }
      return 1;
}
int do_cchat(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!arg ||arg!="劍") 
      return notify_fail("你要聊什麼?\n");
      {
      message_vision("$N說道：劍！\n"
                     "玄外老人說道：喔∼喉喉∼原來你也喜歡劍啊！\n"
                     "[yes or no,no的請打上你的興趣(限 拳法,法術,鞭法)]\n",me);
      ob->set_temp("yess",1); 
      ob->set_temp("noo",1);
      } 
    return 1;
} 
int do_yes(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!ob->query_temp("yess")==1) return 0;
    {
    message_vision("$N點點頭的說：是的！\n"
                   "玄外老人笑笑的說：唉呀呀∼那你跟我的興趣是一樣的...不錯不錯..呵呵呵..\n"
                   "玄外老人說：只是..老夫此生的心願，就是想收集十把我要的劍\n"
                   "玄外老人說：但..我年歲已過半百有餘，只怕心有餘力不足呀..不知道誰能幫我呢[for]？\n",me);
    } 
    ob->delete_temp("yess",1);
    ob->delete_temp("noo",1);
    me->add_temp("fortp",1);
    return 1;
} 
int do_no(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!ob->query_temp("noo")==1) return 0;   
    if(arg!="拳法" || arg!="法術" || arg!="鞭法") return 0;   
    {
    if(arg=="拳法"){
       me->add_temp("八極門",1);}
    else{
        if(arg=="法術"){
        me->add_temp("神武教",1);}
        else {
             if(arg=="鞭法"){
             me->add_temp("情城派",1);} 
             }  
        } 
    }
    message_vision("$N說：我的興趣是"+arg+"！\n"
                   "玄外老人說：原來你的興趣是"+arg+"呀..\n"
                   "玄外老人說：那..想不想比劃比劃..可別欺負老人家呀..呵呵呵..\n" 
                   "玄外老人說：那..我就先攻啦..只有一次機會唷..呵呵呵呵..\n",me);  
    {
    ob->kill_object(environment(this_player()));  
    ob->delete_temp("yess",1);
    ob->delete_temp("noo",1);   
    }
    return 1;
} 
void is_fighting()
{
     object me,ob;
     me=this_player();
     ob=this_object();
     if(ob->is_fighting() )
       return notify_fail("系統檢查中...\n"); 
     {
       if(me->query_temp("八極門") != me->query("class1")=="八極門")  
       {
       else if(me->query_temp("神武教") != me->query("class1")=="神武教")
            { 
            else if(me->query_temp("情城派") != me->query("class1")=="情城派")
            } 
        }
     message_vision("玄外老人說：依$N的招式，$N剛剛說的都是騙我的...那..就恕老夫不奉陪了..\n"
                    "玄外老人向上空一跳，瞬間不見人影..\n",me);
     destruct(ob); 
     }
     else{
     message_vision("玄外老人輕輕笑了幾聲：呵呵呵呵.....\n",me);
     }
}
int do_for(string arg)
{
        object me; 
        me=this_player(); 
        object obj; 
        if(!me->query_temp("fortp")==1) return 0;
        if(arg=="") return notify_fail("你要給什麼[劍,請打全名]?\n"); 
        {
        if(arg=="wooden sword")
        {
        if(!obj=present("wooden sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("wooden")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：木劍劍身輕，耍起來完成不費力氣，好..好好..\n"                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("wooden",1);
                return 1;
        }
///////////////////////////////////////////////////////////////////////// 隔起來比較好分...對我而言
        if(arg=="long sword" && arg=="longsword" ) //DS裡的長劍有兩種寫法.
        { 
      //if(!obj=present({"long sword","longsword"},me)); 
        if(!obj=present("long sword",me))   
        if(!obj=present("longsword",me)) 
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("long")==1)      
        {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：長劍乃武林人士的基本配器，在武林的地位，老夫深感肯定..\n"
                               "玄外老人「嗯」的一聲"\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("long",1); //兩種長劍的temp都用long
                return 1;
        }
///////////////////////////////////////////////////////////////////////////////
        if(arg=="sevenstar barb sword")
        {       
        if(!obj=present("sevenstar barb sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("seven")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：唉呀呀∼你把轅烈的劍都給我拿來啦...\n"
                               "玄外老人「嗯」的一聲...好吧..就算是跟他借的吧...呵呵呵\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("seven",1);
                return 1;
        }
///////////////////////////////////////////////////////////////////////////////////
        if(arg=="shang-ing sword")
        {
        if(!obj=present("shang-ing sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("shang")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：哇...這把劍的顏色真吸引我..@.@\n"
                               "玄外老人說：真是愈看愈喜歡....好..好好..\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("shang",1);
                return 1;
        }  
//////////////////////////////////////////////////////////////////////////////////////       
        if(arg=="god sword")
        {
        if(!obj=present("god sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("god")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("神武劍開始發出嗡嗡的聲音...似乎很認同現在把持它的人..\n"                               "玄外老人眼睛一亮，說道：嗚∼∼真是活潑的一把劍，好有靈性..\n"
                               "玄外老人說：好..好好..\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("god",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////////        
        if(arg=="old sword")
        {
        if(!obj=present(old sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("old")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：咦...這把...有種古舊的感覺..應該是古董..拿起來也蠻順手的..\n"
                               "玄外老人拿起【古劍】耍了兩招...行雲流水的招式，讓$N看的目瞪口呆..─口─||..\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("old",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////// 
        if(arg=="girl sword")
        {
        if(!obj=present("girl sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("girl")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：一看就知道是女性所用的劍...「嗯」...\n"
                               "玄外老人說：雖然不是很喜歡，但..卻讓我想到我的另一半....唉..\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("girl",1);
                return 1;
        } 
//////////////////////////////////////////////////////////////////////////////////////////////     
    if(arg=="xian-tia sword")
        {
        if(!obj=present("xian-tia sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("tia")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：唉呀∼好重的一把劍，而且也全無特色，$N是跟我開玩笑嘛？\n"
                               "$N說道：玄鐵重劍，大工不巧，重的是你舞劍的技巧。\n"                               "玄外老人說：說的好...你給了我滿意的答案...\n"
                               "玄外老人笑笑的，拍了拍$N的頭。\n",me);
                set_temp("tia",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////////////  
        if(arg=="se-ri sword")
        {
        if(!obj=present("se-ri sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("se")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：這把劍的光澤，就像初旭的日光，難道！這是..！\n" 
                               "$N說道：沒錯...這正是 攝日劍 。\n"                               "玄外老人說：沒想到..老夫此生..竟能看到這把劍..足夠了..足夠了..\n"
                               "玄外老人笑笑的，拍了拍$N的頭。\n",me);
                set_temp("se",1);
                return 1;
        } 
////////////////////////////////////////////////////////////////////////////////////      
        if(arg=="peach sword")
        {
        if(!obj=present("peach sword",me))
        {
        return notify_fail("玄外老人拿了起來，仔細給它瞧了瞧.....嘆了口氣，搖了搖頭。\n");
        }
        if(this_object()->query_temp("peach")==1)
                {
                tell_object("你給過玄外老人了。\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("玄外老人眼睛一亮，說道：唉呀呀∼這是把桃木劍耶...正好拿來避邪...\n"
                               "玄外老人輕輕笑了幾聲：呵呵呵...\n"
                               "玄外老人拍了拍$N的頭。\n",me);
                set_temp("peach",1);
                return 1; 
        }
        }
}

int do_guild_join(string str)
{  
        object me;
        me=this_player();
        if(me->query("level") < 50)
             return notify_fail("你的等級還不夠。\n");   
        if(me->query_dex() < 50)
             return notify_fail("你的敏捷不夠[50]。\n");
        if(!me->query("class1")=="疾風門")
             return notify_fail("你不是疾風門的。\n");  
        if(me->query("exp") < 10000000)
             return notify_fail("你的經驗值不夠[1000 萬]。\n"); 
        if(me->query("popularity") < 1000) 
             return notify_fail("你的聲望不夠[1000 點]。\n");
        if(me->query("class2") == "天疾門") return 0;
        if(!str=="天疾門") return notify_fail("你可以加入 天疾門 。\n")
        {
        message_vision("$N向玄外老人大喊了一聲：師傅！\n"
                       "玄外老人拍了拍$N的頭說道：好好.....呵呵呵....\n",me);
        if(this_object()->query_temp("wooden")==1 && this_object()->query_temp("long")==1 && 
           this_object()->query_temp("seven")==1 &&this_object()->query_temp("old")==1&&
           this_object()->query_temp("peach")==1&&this_object()->query_temp("shang")==1&&
           this_object()->query_temp("girl")==1&& this_object()->query_temp("god")==1&&
           this_object()->query_temp("se")==1&&this_object()->query_temp("tia")==1
          {
          message_vision(
          HIW"\n\t$N轉在"+HIG"【天疾門】玄外老人"+HIW"的門下，學習武藝。\n\n"NOR,me); 
          me->set("class2","天疾門"); 
          me->receive_damage("exp",10000000);
          me->receive_damage("popularity",2000); 
          delete_temp("wooden);
          delete_temp("long");
          delete_temp("seven");
          delete_temp("god"); 
          delete_temp("shang"); 
          delete_temp("tia");
          delete_temp("se");
          delete_temp("old");
          delete_temp("girl");
          delete_temp("peach");
          return 1;
          }
        else
          {
          message_vision(
          "玄外老人說道：$N還沒給我十把劍器喔∼∼呵呵呵呵∼∼\n",me); 
         }
        return 1;
        }
} 
void heal()
{ 
     object me=this_player();
     if(query("hp") > query("max_hp")) return; 
     {
     message_vision("玄外老人運起內功，身上的傷口，似乎比較好了。\n",me);
     add("hp",400); 
     }
     return;
}   
/*
void let_delay()
{
     object me=this_player(),ob=this_object();
*/
varargs int receive_damage(int damage)  //此行是參照吳鐘
{
        object me,ob;  
        me=this_player();
        ob=this_object(); 
       // int damage,c;  
       // c=me->query_armor();
        if(ob->is_fighting())  
        if(ob->query("hp")<5000)
        {
          if(random(60)<20)
          { 
         //damage=damage-c;
          damage/=2;
          message_vision(HIW"玄外老人大喝一聲，將手中之劍化為一百零八道劍氣，將$N的攻擊，消減了大半！\n"NOR,me,ob);
          else if(random(60)<20){ 
          damage/=2;
          message_vision(HIW"玄外老人大喝一聲，將手中之劍化為一百零八道劍氣，將$N的攻擊，盡數的反彈回去！\n"
                         +HIR"$N反應不及，被自己的招式打中！\n"+NOR,me,ob);
          me->receive_damage("hp",200);}
          }
          return damage; 
        }
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1); 
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIG"\n\n ◎疾風之訊◎"+HIC"【天疾門的玄外老人】"+HIW"被"+HIR"【"+ob->name()+"給殺掉了】\n\n"+NOR,users());
        
        if(random(60)<20)
          ob->add("popularity",6);
        else if(random(60)<20)
          ob->add("popularity",7);
        else if(random(60)<20)
          ob->add("popularity",8);
        ob->set("guild_rank",HIC"參透"HIY"天宇日理"HIC"萬機"NOR);
        ::die();
        return;
}











