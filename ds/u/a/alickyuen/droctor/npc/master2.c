
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("院長",({"leader"}));
        set("gender", "男性");
        set("long",@LONG
他是院長。
LONG
        );
        set("level",30);                // 設定導師的等級
        set("age",40);                  // 設定導師的年齡
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
        set("class1","外科醫生");           // 設定職業的名稱

// ========================================================================
//      工會導師可以教授的技能列表
// ========================================================================
        set("guild_skills",([   // 難度, 等級1可學到的技能等級倍率, 上限
        ]) );
// ========================================================================
//      工會導師可以教授的法術列表
// ========================================================================
        set("guild_spells",([           // 難度, 等級1可學, 上限
        ]) );

// ========================================================================
//      導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
//      設定屬性分配表, 每一項的值在負9至正10之間
//      而且四項的總和要剛好等於 20
// ========================================================================
        set("guild_gifts",({4,5,6,5 }));
  set("inquiry/help",
        "list    列出技能列表\n"
        "train   訓練技能\n"
        "join    加入部門\n"
        "advance 升級或增加屬性\n"); 
       setup();
}
void init()
{
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

        return GUILDMASTER->do_skill_list(ob,me,arg);   
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
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        message_vision("$N想加入「"+ arg+ "」。\n",me); 
        if(me->query("class1")=="外科醫生")
                return notify_fail("你已經是一位醫生了。\n");
        if(!arg || arg!="外科醫生" )
                return notify_fail("這裡沒有這個公會。\n");
        if(me->query("adv_class") )
                return notify_fail("你已經加入公會或門派了。\n");

        if(!me->query_temp("get_pass") )
        {
        command("say 你必須先拿醫生證照。");
        }
        else {
        command("nod "+me->query("id") );
        me->delete_temp("get_pass");
   me->set("adv_class",1);
      me->set("class1","外科醫生");
me->set("guild_rank","『☆』級的醫生");
me->set("title","實習醫生");
        me->set("adv_class",1);
        }               
        return 1;
}

// ========================================================================
// 使用 advance 升級時會參考到 guild_rank() 這個函數, 這個函數可以改變
// 玩家的職業rank.
// ========================================================================
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="外科醫生" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("你並沒有加入醫生公會。\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        switch( lv )
        {
        case 0: rank = "『☆』級的醫生"; break;
        case 1: rank = "醫生"; break;
        case 2: rank = "醫生"; break;
        case 3: rank = "醫生"; break;
        }
        return rank;
}
