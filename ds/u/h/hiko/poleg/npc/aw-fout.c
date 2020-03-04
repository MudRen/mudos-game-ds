#include <ansi.h>
inherit NPC;
void create()
{
        set_name("傲鋒",({"aw fout","aw","fout"}) );
           set("long",
            "你眼前一亮，不禁被這位身著白衣，美皙如玉，風度翩翩的瀟灑男子\n"
            "所吸引住，只見他一臉寒列，不時地張望，似乎正尋找東西的樣子。細看\n"
            "其衣裳左胸前畫有七朵梅花，另有紫白青金四線為底。渾身英氣十足，神\n"
            "采曄然，一眼便得知其武術造詣之高。\n"
           );
        set("age",28+random(4));
        set("race","人類");
        set("level",28+random(5));
        set("title","【傲梅派】第四代第子");
        set("gender", "男性" );
        set("Merits/wit",2);
        set("chat_chance",5);
        set("chat_msg",({
            "傲鋒喃喃自語地說道：這個要怎麼才能找到他呢?\n",
            (: random_move :),
        }) );
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("sword",70);
        set_skill("awmay-ken",80);
        setup();
        carry_object(__DIR__"wp/faumin-sword")->wield();
}


