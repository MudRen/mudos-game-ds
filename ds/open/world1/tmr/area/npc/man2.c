inherit NPC;

void create()
{
        set_name("犯人",({ "man" }) );
        set("long",
"一個看來瘦弱不堪的人，精神十分委靡，不時還乾咳了數聲，大去之\n"
"期不遠矣..\n"
        );

        set("race","人類");
        set("gender","男性");
          set("chat_chance",10);
        set("chat_msg",({
        (:command("puke"):),
   (:command("get all"): ),
   (:command("wear all"): ),
        }) );
        set("age",30);
        set("level",5);
        set("attitude", "heroism");  

        setup();
}

