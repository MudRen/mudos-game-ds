inherit NPC;

void create()
{
       set_name("�ӤH",({"businesswoman","woman"}));
       set("long","�q�Ʈ��W�T�����ӤH�C\n");
       set("gender","�k��");
       set("age", random(20)+20);
       set("level", random(5)+1);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("smile"):),
            (:command("say �n���n���I�I"):),
            (:command("say ����p���I�I�O�I�ˤF�I"):),
            (:command("say �������ƥع��....�H"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("fear"):)
        }) );
    
        setup();
        switch(random(4))
        {
        case 1: carry_object( __DIR__"eq/dress")->wield();break;
        case 2: carry_object( __DIR__"eq/rich_cloth")->wear();break;   
        case 3: carry_object( __DIR__"eq/cloth")->wear();break; 
        default:break;
        }
        
        add_money("coin", random(1000));
}

