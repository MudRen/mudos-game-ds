inherit NPC;

void create()
{
         set_name("四段生化人",({"lv 14 robot","robot"}) );
set("long","由超•光子企業贊助於超•光子練習場的會員利用！\n");
        set("race","human");
set("age",60);
         set("level",14);
set("chat_chance",10);
        set("chat_msg",({
                         (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-gun.c")->wield();  
}

