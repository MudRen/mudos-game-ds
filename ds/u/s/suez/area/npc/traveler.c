inherit NPC;

void create()
{
       set_name("�ȤH",({"traveler"}));
       set("long","�@�ӮȦ�̡A�{�b�����ۥ𮧩O�I");
       set("gender","�k��");
       set("age", 21);
       set("level", 5);

       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("sweat"):),
            (:command("say �O�ֹL�F�Y�A�𮧤@�U�ϦӤ���n�C"):),
            (:command("say �𮧬O���F������������A�����u�n�A���O�ܡH"):)
           }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("walileh"+this_player()->query("id")):),
       "�ȫȴq������:�u�کM�A�L�޵L���A���D���F�@�I�I�g��ȴN�n���ڶܡH�v\n"
        }) );
    
        setup();
        add_money("coin", 200);
        carry_object( __DIR__"eq/cloth")->wear();           
}