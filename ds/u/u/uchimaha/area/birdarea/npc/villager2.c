inherit NPC;
void create()
{
        set_name("村民",({ "villager" }) );
        set("long","一個居住在獵狐村的村民，看來並無什麼過人之處。\n");
        set("race","人類");
        set("title","獵狐村");
        set("age",30);
        set("level",7);
        set("attitude","friendly");
        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);
        set("chat_chance",20);
        set("chat_msg", ({"村民對你說:小兄弟你怎麼隨便就闖入別人的家裡呢?\n",
                        (:command("sigh"):),
        }));
   setup();
add_money("silver",8);           
}

