inherit NPC;

void create()
{
       set_name("�_�I��",({"adventurer","man"}));
       set("long","���F�U�ؤ��P�z�ѦӦV�����D�Ԫ��k�H�C\n");
       set("gender","�k��");
       set("age", random(20)+15);
       set("level", random(10)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say �U�����ؼ�...�o�̶ܡH"):),
            (:command("say �K�I�W�����_�I�i�u���O�\\���I"):),
            (:command("say �u�Q�ܤ@�M�ڡ��"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("grin"):)
        }) );
    
        setup();

	carry_object( __DIR__"wp/sword")->wield();
         carry_object( __DIR__"eq/l_armor")->wear();  
        carry_object( __DIR__"eq/cloth")->wear();
}

