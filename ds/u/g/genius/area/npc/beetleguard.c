#include <ansi.h>
inherit NPC;
//修改標本來自冷月
mapping *combat_action = ({
        ([      "action":               "$N張開駭人的嘴巴朝著$n的$l狠狠咬去",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "咬傷",
        ]),
        ([      "action":               HIW"只見$N"HIW"的觸鬚像鞭子一般，向著$n"HIW"的$l不斷抽打"NOR,
                "attact_type":  "bio",
                "damage_type":  "瘀傷",
        ]),
        ([  "action":                   "$N舉起前肢，用力地抓向$n的$l",
                "attact_type":  "bar",
                "damage_type":  "抓傷",
        ]),
       ([  "action":                   "$N的背甲忽然撐大，往$n的$l撲了過去"NOR,
                "attact_type":  "mit",
                "damage_type":  "撞傷",
        ]),

});
void do_clean();

void create()
{
        set_name(HIG"盔甲蟲守衛"NOR,({"Guard of armor beetle","guard","beetle"}) );
        set("long",@LONG
這是一種可怕的蟲型怪物，身上披著一層硬可比擬金屬的殼。
你面前的這一隻更是這種蟲類中的戰士，感覺上比一般的大盔
甲蟲還要強壯許多，令人遇見就不寒而慄。
LONG
);
        set("limbs", ({
                "頭部", "頸部", "胸口","背後","腰間","腹部","前腳","後腳",
        }) );
        set("title",HIW"異蟲");
        set("age",16);
        set("level",50);
        set("gender","雄性");
        set("race","monster");
        set("attitude", "killer");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "盔甲蟲守衛的觸鬚不斷地揮動著，作為警戒。\n",
        "盔甲蟲守衛的觸鬚不斷地揮動著，作為警戒。\n",
        "盔甲蟲守衛的觸鬚不斷地揮動著，作為警戒。\n",
        "盔甲蟲守衛的背甲震動著，發出駭人的聲響。\n",
        "盔甲蟲守衛兩顆眼珠子忽然往你的方向一瞪，好像發現了什麼。\n",
        }));
        set_skill("mob_bite", 85);
        set("addition_armor",100);
        set("addition_damage",50);
        add("apply/hit",50);

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
