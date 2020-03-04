inherit NPC;
void create()
{
        set_name("神秘人物", ({ "mystical man ", "man" }) );
        set("long", "神秘的人，\n"
                    "從一個神秘的世界來的。\n");

        
        set("class","fighter");
        set("attitude","friendly");

        set("level",15);
        set("age",  28);
        set("chat_chance",9);
        set("chat_msg",({
  "神秘的人低聲講：這世界，我來無影，去無縱。\n",
  (: command,"sweat" :),
}));

        set_skill("sword",  20);
        set_skill("dodge",  20);
        set_skill("parry",  25);
        
        setup();
        
}
