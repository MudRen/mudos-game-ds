#include <npc.h>

void create()
{
        set_name("喝醉的魔獸", ({ "drunk evil monster","monster" }) );
        set("long",@long
    這是一隻長得人模人樣的怪物，但是你可以清楚瞧見牠全身長滿黃色
短毛，細長如柳葉而散發紅光的眼睛正瞪視著你，牠兩隻手臂長可及膝，正伸
著五大根如黑色鐵塊般尖銳的指甲，似乎隨時都可以把你撕成兩半。但是牠似
乎連站都站不穩了，一臉醉醺醺的樣子。
long
);
        set("title","迷霧森林");
        set_race("human");
        set("age", 120);
          set_skill("sword",120);
          set_skill("parry",120);
        set_skill("dodge",60);
          // 殺死魔獸，能得到 5點聲望
        set("bounty",([
                "reputation":5, 
        ]) );
        setup();
          set_level(35);  // 魔獸 是很強的....
        carry_money("gold", 1);
        /* 基本裝備 */
        carry_object(__DIR__"obj/evilmonster-armor")->wear();
        carry_object(__DIR__"obj/python-belt")->wear();
        // only sword：御虛長劍
        carry_object(__DIR__"obj/dominate-sword")->wield();
}

