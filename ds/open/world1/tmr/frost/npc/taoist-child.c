inherit NPC;

void create()
{
        set_name("小道僮",({"taoist child","child"}) );
        set("long",@LONG
他是寒澈道觀中年幼的道僮，雖然年紀嫩小，但已經擁有獨立的能力
。他正拿著掃帚清理道觀正門階梯上的落葉。
LONG
);
        set("age",8);
        set("race","人類");
         set("level",1);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("title","寒澈道");
        set("chat_chance",10);
        set("chat_msg",({
                "小道僮辛勤地掃著階梯上的落葉..\n",
               (:command("sweat"):),
                "小道僮別過頭來望了你一眼之後，又繼續做他的工作了。\n",
        }) );

        set_skill("unarmed",20);

        setup();
        carry_object(__DIR__"eq/shoe")->wear();
        receive_money(10);
}

