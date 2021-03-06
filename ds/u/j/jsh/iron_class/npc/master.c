// new class - Jangshow 03.24.2006
// /u/s/shengsan/npc/bluemaster.c       by shengsan
// 藍天導師                             1999.03.28
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"鐵紹鴻"NOR,({"iron shouw hung","iron","hung","shouw","master"}));
        set("gender", "男性");
        set("long",@LONG
他是鐵盾門的掌門人，手拿著一把巨斧，身穿著百斤重的鐵甲，巨大的
身軀，讓你忘了他已將近六十歲。
LONG
        );
        set("level",60);                // 設定導師的等級
        set("age",55);                  // 設定導師的年齡 
        set("title",HIC"鐵盾門"NOR);

// ========================================================================
//      adv_class: x    x = 數值(1~2)
//      此參數是說明此玩家或NPC目前的職業是第幾級, 1 就是第一級, 也就是最初
//      的職業等級, 2 就是第二級, 依此類推...
// ========================================================================
        set("adv_class",1);             // 設定他的職業等級是初級(值為1)

// ========================================================================
//      class1: x       x = 職業字串(英文)
//      這是第一級職業的職業英文名稱, 不管此玩家或NPC目前為第幾級的職業, 這
//      個參數一定要定義, 否則程式就不會正常工作... 記住, 職業歷程要完整...
// ========================================================================
        set("class1","iron_class");           // 設定職業的名稱

// ========================================================================
//      工會導師可以教授的技能列表
// ========================================================================
        set("guild_skills",([   // 難度, 等級1可學到的技能等級倍率, 上限
                "dodge":({30,2,50}),   // 基本閃躲
                "blade":({30,2,50}),    // 刀法技巧
                "sword":({30,2,50}),   //劍法技巧
        ]) );

// ========================================================================
//      工會導師可以教授的法術列表
// ========================================================================
        set("guild_spells",([           // 難度, 等級1可學, 上限
            //    "iron_soul":({50,2,100}),   // 鐵將魂
        ]) );

// ========================================================================
//      導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
//      設定屬性分配表, 每一項的值在負9至正10之間
//      而且四項的總和要剛好等於 20
// ========================================================================
        set("guild_gifts",({10,5,-3,8}));
         add("addition_armor",300);
        add("addition_damage",200);  
        set("chat_chance", 12);
        set("chat_msg", ({
  (: command("say 今天天氣真好") :), 
})); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("wield axe") :),   
  (: command("wield axe") :),  
  (: command("wield axe") :),  
  (: command("wield axe") :),  
  (: command("wield axe") :),  
})); 
      //set_skill("heavy-sword",100);     
        setup();
        carry_object(__DIR__"wp/axe.c")->wield();
        add_money("coin",1000);
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
        GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
        return 1;
}

int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // 避免列出檢查職業的訊息
        write("\n");
        GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
        this_player()->delete("no_check_class");
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

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

// ========================================================================
// join 加入職業, 必須要使用 do_guild_join(),
// 如果巫師要使用自己的回應方式, 請用 do_guild_join_with_no_message()
// 傳回數值, 再使用這些數值作您想做的回應方式.
// ========================================================================
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("say 玩家已經加入其他組織。");break;
                case -2: command("say 玩家已經加入了與導師同級或更高級的組織。");break;
                case -3: command("say 玩家目前的組織並不適合加入本組織。");break;
                case -4: command("say 玩家等級不夠。");break;
                case -5: command("say 玩家的 termstr 並沒有大於 termnum 值。");break;
                case -6: command("say 玩家的 termstr 並沒有等於 termnum 值。");break;
                case -7: command("say 玩家的 termstr 並沒有小於 termnum 值。");break;
                case -8: command("say 玩家輸入的組織錯誤或沒有輸入要加入的組織名。");break;
                default: command("say Yes...你就是我要找的人。");
        }
        
        return 1;
}

int do_advance(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
}

// ========================================================================
// 使用 advance 升級時會參考到 guild_rank() 這個函數, 這個函數可以改變
// 玩家的職業rank.
// ========================================================================
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
                        case 0: rank = HIR"鐵盾門之初心弟子"NOR; break;
                        case 1: rank = HIR"鐵盾門之中階弟子"NOR; break;
                        default: rank = HIR"鐵武將之火神盾◆"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"鐵盾門之初心弟子"NOR; break;
                        case 1: rank = HIC"鐵盾門之中階弟子"NOR; break;
                        default: rank = HIC"鐵武將之風神盾◆"NOR;
                }
        }
        return rank;
} 
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision(HIY"\n$N氣運雙掌，手上巨斧發出嗡嗡聲響！\n"
                    +HIW"\t擊出！！\n"
                    +HIR"$n被一道看不見的氣勁重創！\n"+NOR,me,target);  
    target->receive_damage("hp",500+random(199), this_object());
      return 1; 
    }
    else
    {
      message_vision(HIY"\n$N快步向前，沒想到是用頭撞向$n\n"
                    +HIR"$n被撞的頭昏眼花 !@#$%！\n\n"+NOR,me,target);    
   target->receive_damage("hp",200+random(100),  this_object());
   target->add_busy(5+random(5));
      return 1;
    }
}
void die()
{
        object ob,key;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",HIC"\n\t◆鐵盾門◆\t"HIW"掌門人【鐵紹鴻】慘死在"HIR""+ this_player()->name()+""HIW"手下\n\n"NOR, users());
        ob->add("popularity", 5); //聲望
        ::die();
        return;
}

