#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$n讀著$N，發現自已違反了不得違戾父母師長，反逆不孝的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得殺生屠害，割截物命的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得叛逆君主，謀害家國的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得淫亂骨肉姑姨姊妹及婦女的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),        ([  "action":       "$n讀著$N，發現自已違反了不得毀謗道法，輕泄經文的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得汙漫靜壇，單衣裸露的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得欺凌孤貧，奪人財物的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得裸露三光，厭棄老病的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了得耽酒任性，兩舌惡口的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),
        ([  "action":       "$n讀著$N，發現自已違反了不得凶豪自任，自作威利的戒條",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "內傷",
        ]),

});

/* 自定戰鬥訊息 */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("說戒部",({"against book" ,"book", "_AGAINST_BOOK_"}));
        set("gender", "男性");
        set("long",@LONG
這是道派道藏中最有名「雲笈七籤」中的說戒部。裡頭記載
了十戒、太上洞玄靈寶消魔寶真安志智慧本願大戒、太霄瑯書十
善十惡及微定志經十戒等戒條。
LONG
        );
          set("level",32);
        set("age",300);
          set("attack_merits", "sou");
        set("title","雲笈七籤");
        set_skill("parry", 100);
        set_skill("block", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("attitude", "aggressive");
        set_temp("fly",1);

        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);

        if(random(10)>=7) carry_object(__DIR__"obj/book2");

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
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

        ob->add("popularity", 1);
        tell_object(ob,HIG "(你的聲望增加一點了。)\n" NOR);

        ::die();

        return;
}

