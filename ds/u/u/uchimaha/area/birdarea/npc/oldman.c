inherit NPC;
void create()
{
        set_name("老人",({ "old man","man" }) );
        set("long","一個居住在獵狐村的老人，看來並無什麼過人之處。\n");
        set("race","人類");
        set("title","獵狐村");
        set("age",70);
        set("level",7);
        set("attitude","friendly");

        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);
      
   setup();
add_money("silver",5);           
}
