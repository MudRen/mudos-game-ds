inherit NPC;

void create()
{
          set_name("尹志平",({"yi zhi-ping","yi","ping"}) );
        set("long",
"尹志平是丘處機的大弟子，為全真教的弟子，武功\、人品都還不錯，\n"
"為全真教弟子中比較有前途的一位。只是不知道為何他會躲在這裡，神色顯\n"
"緊張不自然，\n"
);
        set("age",40);
        set("race","人類");
        set("level",30);
        set("attitude", "peaceful");
        set("title","全真教");
        set("gender", "男性" );
  
        set_skill("unarmed",80);
        set_skill("sword",80);
        set_skill("quanzhen-sword",80);
        map_skill("sword","quanzhen-sword");

        set("chat_chance",6);
        set("chat_msg",({
                (:command("sigh"):),            
                (:command("walk"):),            
        }) );

        setup();
        carry_object("open/world1/wp/longsword.c")->wield();
          carry_object(__DIR__"obj/cap")->wear();
          carry_object(__DIR__"obj/robe")->wear();

}

