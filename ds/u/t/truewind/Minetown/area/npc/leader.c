#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"�Ǥ�"NOR"�·G", ({"Armstrong william","william"}) );
        set("long",@LONG
�o�k�H�@�y�j�G�l�A������סA�O�ѬP�p�`�����ӡA�@���q�����`��
�A�L��۬P�p���Ŧ��A�A����ź�ơC�A�`�N��L���ӻH�S�O������
�A�H�ɥi�H�Ǧ��@�������ˤl�A���ǥs��"�Ǥ�"�C
LONG
);
        set("race", "�H��");
        set("age", 205);
        set("title","�q������");
        set("level", 40);
        set_skill("combat",70);
        set("chat_chance", 10);
        set("chat_msg", ({
        (: command("say �P�p���ڨӳo�̮t���h��Ӥ�F...�C") :),
        (: command("say �M�����o�ͤF���֩_�Ǫ��Ʊ��C") :),
        (: command("say ���X���q�u¼�Z�h�ܰs�A�����W�䧮�������F!?") :),
        (: command("say �٦��X���q�������D��˦b�ר��t�Q�d��F....") :),
        (: command("say ť�������ѳ���s�t����Q�n�����D�Ǥ���...���L���S�R�S...") :),
        (: command("think") :),
        }));
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
        carry_object(__DIR__"wp/armfist.c")->wield();
        setup();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(100) > 50) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +WHT"$N�޻L��$n�ĨӡA�}�U���_���ѹШF�I\n"
                    +HIW"$n�n�{�]�Ӥ��ΡA�ݤf���U�@�O$N���O���������I\n"
                    +"$n�ݤf�Q�r�P�����A�r�M�R�X�@�j�f�A��I\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",100+random(30), this_object());
      target->receive_wound("body",5);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +WHT"$N�޻L��$n�ĨӡA�}�U���_���ѹШF�I\n"
                    +HIW"$n�{�����ΡA��ӤH�Q���n���˦b�a�W�I\n\n"NOR
                    ,me,target);      
                    target->receive_damage("hp",random(50), this_object());
                    return 1;
    }
}

