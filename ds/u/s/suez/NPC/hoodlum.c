inherit NPC;

void create()
{
       set_name("�p�y�]",({"small hoodlum","hoodlum"}));
       set("long","�o�Ӧ�ˤ���,�⤤���@��p�M���֦~,�ݰ_�ӥu�Q�|�B����,�N���O�k�a�����}�֦~�C\n");
       set("gender","�k��");
       set("age", 14);
       set("level", 5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("snort"):),
            (:command("say �K�K��Ӥl��G�I�A�O�b�o�̨m�o�I�I"):),
            (:command("say �ݤ���ݡI�I�A�ݫ��X�A�Ⱖ�Ӥl�I�I"):),
         (:command("say �A�I����F��I�I"):),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       "�p�y�]�ܹD�G�u�ڤ��Ѥ��n�n�аV�A�@�y�I��.....%$#@^&�v\n"
        }) );
    
        setup(); 
       carry_object( __DIR__"wp/knife")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}