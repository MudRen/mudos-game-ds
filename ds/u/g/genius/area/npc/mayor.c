#include <ansi.h>
inherit NPC;
void create()
{
set_name( "洛蒙斯•巴德里卡", ({ "Lormans Badurleica","mayor","lormans","badurleica","lormans badurleica" }) );
        set("long","(Lormans Badurleica, The Mayor Of Almond Village)\n"
"他是愛門村的村長，雖然他已經不年輕了，但是雙目之間仍然發出迥迥\n"
"金光。他曾經是一名英勇的戰士，在他那把大府下被除剷的邪惡難計其\n"
"數。他不僅武藝高超，在智慧上也有不凡之處。二十多年前他因追殺一\n"
"名流亡惡徒行經此地，又因受傷暫住下來。十多年後，再度經過這裡，\n"
"受到這裡人情味的感動在愛門村定居，結束了行俠仗義的生活。不久老\n"
"村長病死，村民就一致推舉他領導眾人，成為此村的村長。\n"
           );
        set("level",32);
        set("age",55);
        set("title",HIR"村長　"HIG"戰士"NOR);
        set("gender","男性");
        set("race","人類");

        set("addition_armor",99);

        setup();

        carry_object(__DIR__"wp/heroaxe")->wield();
}
