inherit NPC;
void create()
{
        set_name("����",({ "villager" }) );
        set("long","�@�ө~��b�y�����������A�ݨӨõL����L�H���B�C\n");
        set("race","�H��");
        set("title","�y����");
        set("age",25);
        set("level",7);
        set("attitude","friendly");

        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);
      
   setup();
add_money("silver",8);           
}
