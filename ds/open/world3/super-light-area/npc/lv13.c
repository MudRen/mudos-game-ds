inherit NPC;

void create()
{
        set_name("�T�q�ͤƤH",({"lv 13 robot","robot"}) );
set("long","�ѶW�E���l���~�٧U��W�E���l�m�߳����|���Q�ΡI\n");
        set("race","human");
set("age",55);
         set("level",13);
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

