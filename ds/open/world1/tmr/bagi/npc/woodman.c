inherit NPC;

void create()
{
        set_name("����",({ "woodman","man" }) );
        set("long",@LONG
�o�O�@�ӤW�s��㪺���ҡA�ѩ���~�樫��s���A�ҥH�������ӡC
LONG
        );

        set("race","�H��");
        set("gender","�k��");
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
