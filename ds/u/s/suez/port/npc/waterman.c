inherit NPC;

void create()
{
       set_name("����",({"waterman","man"}));
       set("long","�K�ª��ֽ��A���n�����n�A�o�O�@��i�������W�k��C\n");
       set("gender","�k��");
       set("age", random(20)+15);
       set("level", random(5)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say ���U�ӳܤ@�M�a�I�I"):),
            (:command("say �K�I�W���ڹJ�쨺�Ӥ~���ƩO�I"):),
            (:command("say �ޡI�ɹL�I�ɹL�@�U��I"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("snort"):)
        }) );
    
        setup();
        carry_object( __DIR__"wp/waterman_knife")->wield();
        if(random(50)>random(500)) carry_object( __DIR__"eq/waterman_dress")->wear();  
         else{carry_object( __DIR__"eq/waterman_cloth")->wear();} 

}

