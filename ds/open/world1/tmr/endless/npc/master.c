
#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("無極導師", ({"endless master", "master"}) );
    set("gender", "男性");
        set("title","天下式");
    set("long",@LONG
無極即道，是比太極更加原始更加終極的狀態︰無極，本來是老子
用以指稱道的終極性的概念。《老子》第二十八章︰「知其白，守
其黑，為天下式。為天下式，常德不忒，復歸於無極。」這是第一
次出現無極的概念。全段意思是說︰雖知道潔白，卻安守於昏黑，
便能做天下的模式。能做天下的模式，永恆的德性不相差失，性回
復到不可窮盡的真道。所以無極的原義就是道，指道是不可窮盡的
。以後道門人士，都是在這一意義上使用無極的概念，但在不同場
合引伸的側重點稍有不同。莊子在《逍遙遊》中說「無極之外，復
無極也。」意思是世界無邊無際，無窮之外，還是無窮。無極便是
無窮。漢代的河上公《老子章句》認為復歸無極就是長生久視。依
道門觀念，與道相合，才能長生久視，因此將無極解釋成道，或者
解釋成長生久視，是一致的。道是無限的。天地開闢之前，它已經
存在了無限的時間，而且會永恆地存在下去，空間上它也是無限的
，不局限於任何一個具體的區域。因此用無極的範疇稱道。在宇宙
演化的角度使用無極一詞，常與太極對舉，指比天地未闢、但卻是
天地直接起始的混沌更加古老、更加終極的階段，這一階段，就是
道。因此，無極是太極的根源。修道者都追求與道合一，道門術語
稱與道合真，在具體機制上便是返回到元初的終極的狀態，這就叫
做復歸無極。
你可以打 transform art 指令，將一千萬點經驗值換成一點戰鬥藝術。
LONG
    );
        set("level", 200);
        set("age", 99999);
        set("adv_class",3);
        set("class3","復歸無極");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("attack_merits","endless");

        set("guild_skills",([           // 難度, 等級1可學, 上限
                "constant-virtue":({300,0,100}),
                  "block":({300,0,100}),
        ]) );
        
        set_temp("fly",1);
        set_temp("apply/bar",99);
        set_temp("apply/bio",99);
        set_temp("apply/wit",99);
        set_temp("apply/sou",99);
        set_temp("apply/tec",99);
        set_temp("apply/int",99);
        set_temp("apply/dex",99);
        set_temp("apply/armor",999999);
        set_temp("apply/damage",999999);
        set_temp("apply/shield",999999);
          set_temp("apply/hit_ratio",100);
        setup();
        set_temp("apply/endless",99);

}
void init()
{
        ::init();
        add_action("do_advance","advance");
        add_action("do_transform","transform");
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}


// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost;
        cost = me->query_skill(argx) * 100;
        me->add("war_art",-cost);
        return;
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class3") != "復歸無極")
               return notify_fail("你並不是「復歸無極」的弟子。\n");

        lv = me->query_skill(arg,1);
        if(lv==100)
                return notify_fail("你這個技能已經到達登峰造極的境界了。\n");
                cost = lv*100;
        if( me->query("war_art") < cost)
                return notify_fail("看來無極導師並不想教你更深一層。(除非你有"+cost+"點戰爭藝術)\n");
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}



int do_advance(string arg)
{
        return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int EXP_AMOUNT = 10000000;

int do_transform(string arg)
{
        object me;
        if(arg != "art")
                return notify_fail("目前只能 transform art。\n");
        me = this_player();
        if(me->query("exp")<EXP_AMOUNT)
                return notify_fail("你目前的經驗值不足，無法轉換成戰鬥藝術。\n");
        me->add("exp",-EXP_AMOUNT);
        me->add("war_art",1);
        message_vision(HIY"$N覺得靈台清明，對於武術又有更多一點的體悟了。\n"NOR,me);
        return 1;
}


string guild_rank(object me)
{
        return "與道合真復歸無極";
}



