#include <ansi.h>
inherit NPC;
void create()
{
        set_name("傲無痕",({"aw wu hen","aw","hen"}) );
        set("long","他是傲梅派的第子，一身淨白裝扮，衣裳左胸前畫有七朵梅花，另有紫白青金四線為底。\n");
        set("age",35);
        set("race","人類");
        set("level",25);
        set("title","【傲梅派】第四代第子");
        set("gender", "男性" );
        set("Merits/wit",2);
        set("chat_chance",5);
        set("chat_msg",({
            "傲無痕喃喃自語地說道：這個施迅不知把邪教一干人藏到哪去了。\n",
            (: random_move :),
        }) );
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("sword",70);
        setup();
        carry_object(__DIR__"wp/longsword2")->wield();
}
