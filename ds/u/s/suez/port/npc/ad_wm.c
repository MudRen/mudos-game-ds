inherit NPC;

void create()
{
       set_name("�_�I��",({"adventuress","woman"}));
       set("long","�k�ʫ_�I�̦����鵹����k�ʪ���O�Υ��ϤߡC\n");
       set("gender","�k��");
       set("age", random(20)+15);
       set("level", random(10)+5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say �U�����ؼЬO���̩O�H"):),
            (:command("say �I��W�����_�I�u��E�r�I"):),
            (:command("say �Ӧn�n�𮧤@�U�F..."):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("lick"):)
        }) );
    
        setup();

	carry_object( __DIR__"wp/sword")->wield();
         carry_object( __DIR__"eq/l_armor")->wear();  
        carry_object( __DIR__"eq/cloth")->wear();
}

