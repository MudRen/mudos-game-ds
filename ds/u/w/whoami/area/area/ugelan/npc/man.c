inherit NPC;
void create()
{
        set_name("�k�l",({ "man" }) );
        set("long","�@�ӷǳƥX���װ����k�l�C\n");
        set("race","�H��");
        set("age",25);
        set("level",10);
        set("attitude","friendly");
        set_skill("dodge",20);
        set_skill("unarmed",20);
        set_skill("parry",20);
      
   setup();
   carry_object(__DIR__"eq/pants.c")->wear();
   add_money("silver",6);           
}

