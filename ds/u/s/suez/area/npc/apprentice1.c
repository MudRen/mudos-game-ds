inherit NPC;

void create()
{
       set_name("�K�P���̤l",({"apprentice"}));
       set("long","�@�ӥ��Υ\\�m\�Z���H�A���F�_���K�P���ӧV�O�C\n");
       set("gender","�k��");
       set("age", 21);
       set("level", 20);

       set("attitude", "peaceful");

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("sweat"):),
            (:command("say ���v�S�]�u�O���A���M��ڭ̺K�P����ۤ��ޡI"):),
         (:command("say �Q�n�ɬ��i�����ŴN�n��u�����V���Y�C"):),
           (:command("say �C�v�n�����ˤ@�۵L�W�j��L�i�F�`���ܡTť���i�H�N���Y���X�@�Ӵx�L�C"):),
          (:command("say ť��....�C�v�n�����˴��g���H�ݨ�L���j�_�L�h�A�M��N�A�]�S�X�{�L�F�C"):),
            (: random_move :),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("angry"+this_player()->query("id")):),
       "�K�P���̤l�j�ۡG�u�i�c�I�����p���I�v\n"
        }) );
    
        setup();
        add_money("coin", 200);   
       carry_object( __DIR__"wp/long_dagger")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}
