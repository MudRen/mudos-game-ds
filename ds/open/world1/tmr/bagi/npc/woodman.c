inherit NPC;

void create()
{
        set_name("樵夫",({ "woodman","man" }) );
        set("long",@LONG
這是一個上山砍柴的樵夫，由於長年行走於山野，所以身材健碩。
LONG
        );

        set("race","人類");
        set("gender","男性");
        set("age",30);
        set("level",1);
        set("attitude", "heroism");  

        setup();
        add_money("coin",50);
        if(random(3)) carry_object(__DIR__"obj/firewood");
        if(random(3)) carry_object(__DIR__"obj/firewood");
        if(random(3)) carry_object(__DIR__"obj/firewood");
        if(random(3)) carry_object(__DIR__"obj/firewood");
        if(random(3)) carry_object(__DIR__"obj/firewood");
}
