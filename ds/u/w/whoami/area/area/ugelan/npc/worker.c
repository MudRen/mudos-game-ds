inherit NPC;
void create()
{
        set_name("碼頭工人",({ "worker" }) );
        set("long","一位在碼頭工作的工人。\n");
        set("race","人類");
        set("age",43);
        set("level",15);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",50);
        set_skill("parry",20);
        set("chat_chance",10);
        set("chat_msg", ({"碼頭工人吆喝道：大伙加把勁•\n",
                          "碼頭工人努力的把漁貨搬下船•\n",
                          (:command("sweat"):),
                        }));
   setup();
   carry_object(__DIR__"eq/pants.c")->wear();
   add_money("silver",6);           
}

