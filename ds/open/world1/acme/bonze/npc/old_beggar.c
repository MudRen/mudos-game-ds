inherit NPC;

void create()
{
        set_name("老叫化子",({"old beggar","beggar"}) );
        set("long",@LONG
一個年邁的老叫化子，穿著一件補著不能再補的破棉衫，還不時彎腰
劇咳了起來，看來身染重病。你看著看著，不禁想從身上拿些雜物、銀兩
什麼的送給他。
LONG
);
        set("age",70);
        set("race","人類");
        set("level",10);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance",10);
        set("chat_msg",({
        "老叫化子敲著一個破碗，搖頭晃腦地唱起了歌\n",
        }) );

        setup();
        carry_object(__DIR__"obj/travel_bag");
}

int accept_object(object who,object ob)
{
     message_vision("$N拿出了一"+ob->query("unit")+ob->query("name")+"送給了老叫化子。\n",who);
        command("say 咳...謝..咳咳..謝謝...。");
        destruct(ob);
        return 1;
}


