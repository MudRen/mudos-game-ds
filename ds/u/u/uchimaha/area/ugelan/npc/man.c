inherit NPC;
void create()
{
        set_name("男子",({ "man" }) );
        set("long","一個準備出海度假的男子。\n");
        set("race","人類");
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

