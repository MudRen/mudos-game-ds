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
            (:command("say �C�v�j�n�i����I�����򭷮v�S�n���}�A�L�M�C�v�j���O�̦n�ܡH"):),
            (:command("say ���I���n���ѧڭ̤��b�A�_�h����b�o�̽͸ܩO�H"):),
            (:command("say �C�v�n�����˥��ܡA���v�S�S....���C"):),
         (:command("say ��v�S�ݺު�����U�l�n���A�`�ڳ������h�L���̾ǪZ�\�K"):),
            (: random_move :),
           }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("slap"+this_player()->query("id")):),
       "�K�P���̤l�j�ۡG�u�A�ӹL���F��I�v\n"
        }) );
    
        setup();
        add_money("coin", 200);
        carry_object( __DIR__"wp/long_dagger")->wield();
       carry_object( __DIR__"eq/cloth")->wear();         

}
