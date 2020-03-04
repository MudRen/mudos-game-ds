#include <ansi.h>
inherit NPC;
void create()
{
        set_name("傲無悔",({"aw wu hui","hui"}) );
        set("long",
"你眼前一亮，不禁被這位身著白衣，美皙如玉，風度翩翩的瀟灑男子\n"
"所吸引住，其衣裳左胸前畫有七朵梅花，另有紫白青金四線為底。渾\n"
"身英氣十足，神采曄然，一眼便得知其武術造詣之高。\n"
);
        set("age",33);
        set("race","人類");
        set("level",25);
        set("attitude", "peaceful");
        set("title","【傲梅派】第四代弟子");
        set("gender", "男性" );
        set("Merits/wit",1);
        set("chat_chance",6);
        set("chat_msg",({
            "傲無悔說道：你就承認吧，別再做無謂的掙扎了。\n",
            "傲無悔說道：施迅，你到底將邪派眾人藏到哪去了！難道要我們把你家掀了嗎？\n",
        }) );
        set_skill("unarmed",70);
        set_skill("sword",70);
        set_skill("force",80);
        setup();
        carry_object(__DIR__"wp/longsword2")->wield();
}
