inherit NPC;

void create()
{
        set_name("認錯的人", ({ "pigking" }) );


        set("level",1);
        set("age", 19);
        set("gender", "男性");
        set("long",
"這個人是一個犯錯的小孩。\n"
);
        set("chat_chance",70);
        set("chat_msg",({
                (:command("sigh"):),
(:command("sorry"):),
                "純廷道：「瑋怡！對不起！我錯了！請原諒我！」\n",
        }) );
        setup();
        add_money("coin", 0);

}

