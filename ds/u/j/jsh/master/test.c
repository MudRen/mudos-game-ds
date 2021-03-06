#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY"光之子"NOR,({"son of light","son","light","master"}));
        set("gender", "男性"); 
        set("title",HIW"龍的傳人"NOR);        set("long",@LONG
        list    列出可學的技能與法術列表
        train   訓練技能
        learn   學習法術
        join    加入工會
        advance 升級或增加屬性

LONG
        );
        set("level",45);                
        set("age",53);                  

        set("adv_class",2);             
        set("class1","dragon");           �
        set("guild_skills",([   
                "dodge":({32,2,105}),   �
                "blade":({30,2,90}),    
        ]) );

        set("guild_spells",([           
                "killingdragon-yet-blade":({60,2,30}),
        ]) );

        set("guild_gifts",({10,5,-3,8}));

        setup();

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
        this_player()->set("no_check_class",1); 
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

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("say 玩家已經加入其他門派。");break;
                case -2: command("say 玩家已經加入了與導師同級或更高級的組織。");break;
                case -3: command("say 玩家目前的組織並不適合加入本組織。");break;
                case -4: command("say 玩家等級不夠。");break;
                case -5: command("say 玩家的 termstr 並沒有大於 termnum 值。");break;
                case -6: command("say 玩家的 termstr 並沒有等於 termnum 值。");break;
                case -7: command("say 玩家的 termstr 並沒有小於 termnum 值。");break;
                case -8: command("say 玩家輸入的組織錯誤或沒有輸入要加入的組織名。");break;
                default: command("say 玩家加入了神刀門。");
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

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/4;     
        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                        case 0: rank = HIW"神刀入門小小刀客"NOR; break;
                        case 1: rank = HIG"神刀入門爐火純青"NOR; break; 
                        case 2: rank = HIB"神刀入門萬夫莫敵"NOR; break;                        default: rank = HIY"神"HIR"毀 天  滅 地"HIY"刀"NOR;
                }
        }
        return rank;
}


