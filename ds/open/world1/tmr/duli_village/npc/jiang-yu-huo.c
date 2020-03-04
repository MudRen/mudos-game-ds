// By Tmr 2002/05/07
// Quest skill:歸隱、征戰 兩劍法 放出系用(劍氣) sk point 4
// 做錯事的小孩...
// 
#include <npc.h>
#include <skill.h>
#include <ansi.h>
inherit F_VILLAGER;
void do_ask(object me);
void create()
{
        set_name("江漁火", ({ "jiang yu huo","jiang","huo" }) );
        set_race("human");
        set("title","村長");
        set("age", 60);
        set("long",@LONG
江漁火是這漁村的村長，瞧他滿臉紅光，滿頭烏黑的頭髮和湛然有神
的雙眼，在在讓人不敢因為他老邁的年紀而輕視他。
LONG
);
        set_skill("sword",80);
        set_skill("secondhand sword",80);
        set_skill("isolate sword",90);
        set_skill("campaign sword",90);
        map_skill("sword","isolate sword");
        map_skill("secondhand sword","campaign sword");
        map_skill("parry","campaign sword");

        set_skill("parry",60);
        set_skill("dodge",80);
        set("chat_msg", ({
                (: command("sigh") :),
                (: command("say 唉呀..我那小孫子從昨天出去玩，竟然就沒再回來了，真令人擔心呀。") :),
        }));
	set_attr("emit",50);

        setup();
        set_level(20);
        carry_object(__DIR__"obj/drift-cloud-sword")->wield("secondhand sword");
        carry_object("/d/obj/shortsword")->wield("sword");

}

