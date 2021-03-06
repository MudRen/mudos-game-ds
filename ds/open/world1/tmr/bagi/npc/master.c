//八極門 進階Master 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("吳鐘",({"wu chung master","master","wu","chung"}));
        set("gender", "男性");
        set("long",@LONG
吳鐘為八極門拳術的始祖，年少時勇氣出眾，超拔出群，其武藝由一
名「癲」的道士所傳授，其大槍訣從癲的徒弟－癖，所習得，至此不分晝
夜，修習武藝，於五十歲時大成，次年創八極門，七十歲大徹大悟，退居
山林，悠遊自得。
LONG
        );
        set("level",60);
        set("age",80);
        set("adv_class",2);
        set("class1","八極門");
        set("class2","八極門");
        set("title","八極門開山祖師");

        set("apply/armor",30);
        set("apply/damage",30);

        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("fork",100);

        set_skill("da-fork",100);
        set_skill("bagi_fist",100);
        set_skill("horse-steps",100);

        set("chat_chance", 10);
        set("chat_msg",({
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
        }) );
// ========================================================================
//      工會導師可以教授的法術列表
// ========================================================================
        set("guild_skills",([           // 難度, 等級1可學, 上限

        ]) );

// ========================================================================
//      導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
//      設定屬性分配表, 每一項的值在負9至正10之間
//      而且四項的總和要剛好等於 20
//      ********************* 必須要和初級職業一樣 **********************
// ========================================================================
        set("guild_gifts",({10,7,0,3}));

        setup();
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_guild_join","join");
        add_action("do_advance","advance");
}


int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(this_player()->query("class2") != "八極門")
                return notify_fail("你並不是八極門弟子。\n");
        if( this_player()->query("popularity") < 3 ) 
                return notify_fail(".....");
             me->set("popularity",j-3);
        return    GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        message_vision("$N想加入"+arg+"。\n",me);
// ========================================================================
// join 加入職業, 必須要使用 do_guild_join(),
// 如果巫師要使用自己的回應方式, 請用 do_guild_join_with_no_message()
// 傳回數值, 再使用這些數值作您想做的回應方式.
// ========================================================================
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("你已是其他們派的徒弟了\n");break;
               case -2: notify_fail("你已是其他們派的徒弟了\n");break;
               case -8: notify_fail("沒有這個門派吧");break;

        }
        if( arg=="八極門"
         && me->query("class1")=="八極門" 
         && me->query("level")==25 )
          {       
            command("pat " + me->query("id") );
            me->set("class2","八極門");
            me->create_family("八極門",2,"俠客");
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

        if(this_player()->query("class2") != "八極門")
                return notify_fail("你並不是八極門弟子。\n");
        if(me->query("popularity") < 3 ) 
                return notify_fail("你的聲望不夠。\n");
        me->set("popularity",j-3);
        return GUILDMASTER->do_advance(ob,me,arg);
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
                                // LV 1 ~ 9
                        case 0: rank = "神武教第三代教徒"; break;
                                // LV 10 ~ 19
                        case 1: rank = "神武教第三代教徒"; break;
                                // LV 20 ~ 29
                        case 2: rank = "神武教之烈焰破空"; break;
                                // LV 30 ~ 39
                        case 3: rank = "神武教之火劍雙絕"; break;
                                // LV 40 ~ 49
                        case 4: rank = "神武教火雲女劍俠"; break;
                                // LV 50
                        default: rank = HIC"神武教之毀天滅地"NOR;
                }
        }
        else
        {
        }
        return rank;
}


