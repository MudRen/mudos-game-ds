#include <ansi.h>
inherit NPC;
void create()
{

        set_name("半羊人", ({"bariour"}));
        set("long",@LONG
半羊人看起來像人馬，他混合了人和羊的特徵而不是人和馬。從腰部以下它看起來像是一 
個強壯的羊。腰部以上，看上去像人，只是在前額上長有一對彎曲的角。 
LONG
        );
        set("gender", "男性");
        set("title","羊男的迷宮");
        set("race", "human");
        set("level",10);
        set("age", 30);
        set("env/wimpy", 10);         //逃跑wimpy (10%)
        set("evil",-20);                //邪惡度 -20 (正的表邪惡, 負表善良)
        set("attitude", "peaceful");   //溫和的 NPC。
        setup();
         add_money("coin", 100);
        carry_object("/open/world1/eq/fur_waist")->wear();
        carry_object("/open/world1/eq/bs_boots")->wear();
        carry_object("/open/world1/wp/sword")->wield();
        carry_object(__DIR__"obj/bariour_fur");

}

