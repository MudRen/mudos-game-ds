// �s                         by Zorg
// �i�H�M�����d��
// ��: ���ȬO�����ͪ��i�H�M��, �N��O�S���ͩR���F��]�i�H, �Ҧp ���涳
//     �u�n�[�W set("ridable",1); �N�i�H�M��
inherit NPC;

void create()
{
        
        set_name("�s",({"dragon"}) );
        set("race", "���~");
        set("level",50);
        set("str",100);
        set("con",100);
        set("int",100);
        set("dex",100);
        set("age",4000); 
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_spell("god-benison",100); 
        set("long", "�o�O�@�ثD�`�u���o�~��,�䦨�s��O���o�@��,
�b�ͪ��ɤ��L��O�̱j���ͪ�,������O'�]�k�O'�ͩR�O���O�̱j���C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}","����","�ͻH"}));
        set("verbs", ({"bite"}));
        set("ridable",1);               // �]�w���i�M����
        set("chat_chance", 9);      
        set("chat_msg", ({   
        (:command("defend zorg"):),
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("defend zorg"):), 
        (:command("cast god-benison"):),  
}) );
        setup();
}

int ride_before_action(object me)       // �M�����e�|����禡
{
        int s = me->query("str");
        if( s<10 || !s )
        {
                message_vision("�ѩ�$N���O�q�����A�L�k����"+this_object()->name()+"�A�]�ӳQ"+this_object()->name()+"�q�s�I�W�L�F�U�ӡI\n",me);
                return 0;               // �^�� 0 �N�O�N�����M��
        }
        else 
        {
                message_vision("$N�ϥX�������Z�O�ǳƩ��A�o��"+this_object()->name()+"�C\n",me);
                return 1;               // �^�� 1 �N�O�N��i�H�M��
        }
}

int ride_after_action(object me)        // �M������|����禡
{
        message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
        return 1;                       // �����n�^�� 1
}


int ride_off_action(object me)          // ���}�y�M����|����禡
{
        message_vision("$N�w�g���}"+this_object()->name()+"�F�C\n",me);
        return 1;                       // �����n�^�� 1
}


