inherit NPC;

void create()
{
        set_name("����",({ "villager" }) );
        set("long","�@�ӧ����A�ݨӨõL����L�H���B�C\n");
        set("race","�H��");
        set("age",30);
        set("level",5);
        set("attitude","friendly");

        set_skill("dodge",10);
        set_skill("unarmed",10);
        set_skill("parry",10);
        setup();
add_money("coin",500);           
}

