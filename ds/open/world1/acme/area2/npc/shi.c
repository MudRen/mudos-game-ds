#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�I��", ({ "shi shen","shi" }) );
        set("gender", "�k��" );
        set("long",
            "�L�N�O�a��g���A�a�]�U�e�A�I�i�İ�A���䬰�H�۷�p��\n"
            "�A�B�`�`�ۭ�a��a�x�H�a�A�i���O�Ӵc�H�A���L��L���a\n"
             "�H�o�Q�����n�A�ר��d�R�L���k��C\n"
           );
        set("age",45);
        set("level",35);
        set("title","�i���I��j");
      set_skill("axe",70);
        set_skill("parry",60);
        set_skill("dodge",85);
    set("chat_chance", 5);
        set("chat_msg", ({
                "�I�����D�G�ڤ��O��A���L�F�ܡI�S���o�^�Ƨr�I\n",
                 "�I�����D�G�O�ֶóy�������r�I�ګ��i��h�]�ȳo�Z�c�{�O�I\n",
                "�I�����D�G�ک����èS���ðε۳o��c�{�r�I\n",
        }));
        set("chat_chance_combat",90);
        set("chat_msg_combat", ({
              "�I���H���D�G�c��I�h���a�I\n",
         }) );
        set("talk_reply","���}�I���}�I�O�ӷЧڡI\n");
        set("inquiry", ([
            "�խߦa��": "�ڡ���A��|���D�I�I�N���A�i�O�ñi���r�I�I\n",
            "�խߨ���": "�ڡ���A��|���D�I�I�N���A�i�O�ñi���r�I�I\n",
            "�I���w" : "�F���I�o�O�ڤk��ڡI�A�i�O��L��˧r�I�_�h�I��I��I\n",
            "�H��" : "�o�H�ѧA�i�O�ðʧr�I�_�h�|�ިӱ������ת��I\n",
            "���Z��": "�o�ǤH�ڡA�o�X�~��B�b�䨸�Ъ��ѡA������n�ϱo�ѤU�ӥ���\n"
        "          �A�o�X�ѳ��M�h�è�ڪ��Y�W�A���ڥ]�óo�娸�дc�{�C\n",
            "�K����": "�o�ǤH�ڡA�o�X�~��B�b�䨸�Ъ��ѡA������n�ϱo�ѤU�ӥ���\n"
        "          �A�o�X�ѳ��M�h�è�ڪ��Y�W�A���ڥ]�óo�娸�дc�{�C\n",
            "�e����": "�o�ǤH�ڡA�o�X�~��B�b�䨸�Ъ��ѡA������n�ϱo�ѤU�ӥ���\n"
        "          �A�o�X�ѳ��M�h�è�ڪ��Y�W�A���ڥ]�óo�娸�дc�{�C\n",
            "�Ʊ���": "�o�ǤH�ڡA�o�X�~��B�b�䨸�Ъ��ѡA������n�ϱo�ѤU�ӥ���\n"
        "          �A�o�X�ѳ��M�h�è�ڪ��Y�W�A���ڥ]�óo�娸�дc�{�C\n",
        ]) );
        setup();
      carry_object(__DIR__"wp/axe2.c")->wield();
}
