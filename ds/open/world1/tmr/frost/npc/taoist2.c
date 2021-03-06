inherit NPC;

void create()
{
        set_name("道人",({"taoist"}) );
        set("long",@LONG
一個寒澈道觀的道人，身著道服，精神羿羿地十分享受修道的生活。
道人是道觀中資歷比較年長的道士，須經過一定的苦修。
LONG
);
        set("age",40);
        set("race","人類");
        set("level",20);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("title","寒澈道");
        set("chat_chance",12);
        set("chat_msg",({
                "道人親切地跟你打招呼。\n",
        }) );

        set_skill("parry",60);
        set_skill("dodge",60);
        set_skill("unarmed",60);
        set_skill("pick-plumblossom",60);
        map_skill("unarmed","pick-plumblossom");
        set_spell("freeze-ball",50);
        set_spell("fall-thunder",50);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (:command("cast freeze-ball"):),
                (:command("cast fall-thunder"):),
        }) );


        setup();
        carry_object(__DIR__"eq/shoe")->wear();
        carry_object("/open/world1/eq/clothes_8")->wear();
        carry_object("/open/world1/wp/woodfist_8")->wield();
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");
         carry_object(__DIR__"obj/water");

}

