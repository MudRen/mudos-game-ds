inherit NPC;
void create()
{
        set_name("�԰�",({"war horse","horse"}) );
        set("race", "���~");
        set("level",15);
        set("age",10);
        set("long", "�@���ܵ��K�Ҫ��԰��E\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}","�_��"}));
        set("verbs", ({"bite","hoof","crash"}));
        set("ridable",1);               // �]�w���i�M����
        setup(); 
        carry_object(__DIR__"eq/horse_armor")->wear();
}

int ride_before_action(object me)       // �M�����e�|����禡
{
        int s = me->query("str");
        if( s<25 || !s )
        {
                message_vision("�ѩ�$N���O�q�����A�L�k����"+this_object()->name()+"�A�]�ӳQ"+this_object()->name()+"�q�հ��I�W�L�F�U�ӡI\n",me);
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

