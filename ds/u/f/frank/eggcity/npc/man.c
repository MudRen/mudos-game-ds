inherit NPC;
void create()
{
        set_name("居民", ({ "man" }) );
        set("long","住在錟都城的人。\n");
        set("level",3+random(5));
        set("age",38+random(10));

        set("combat_exp", 2000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 8);
        set("chat_msg_combat", ({
   (:command("say 最近井裡的水，怎麼好像不太乾淨!"):),
   (:command("say 現在的野狗越來越凶了!!"):),
   (:command("say 今天會下雨!!"):),
   (:command("say 今天要做啥呢???"):),
   (:command("say 今天會出太陽"):),
}));
        set_skill("sword", 20);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);

        setup();
        carry_object(__DIR__"obj/poorcloth")->wear();
       
}

