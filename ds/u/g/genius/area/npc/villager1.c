inherit NPC;

void create()
{
        set_name("����",({ "villager" }) );
        set("long","�R�������¾�����A���b�Q�רƱ��C\n");
        set("race","�H��");
        set("age",28);
        set("level",4);
        set("attitude","friendly");

        set_skill("dodge",10);
        setup();
        add_money("coin",200);           
}

