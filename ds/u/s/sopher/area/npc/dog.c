inherit NPC;

void create()
{
        set_name("����", ({ "dog" }) );
        set("long", "�@������ż�����������C\n");
        set("race", "���~");
        set("gender","�۩�");   // 1999.2.28 �W�[������
        set("age", 3);
        set("level",2);
        
        set("str", 14);
        set("dex", 16);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) ); //���𳡦�
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�����λ�l�D�F�D�A���}�C\n",
                "�����b�A���}������������M�Q�Q�F��Y�C\n",
                "������ۧA�n�F�n���ڡC\n",
                "�����Ϋ�L��F��ۤv���զ��C\n" }) );
                
        set_temp("apply/damage", 10);   //���[�ˮ`�O
        set_temp("apply/hit", 10);      //���[�R���v
        set_temp("apply/armor", 3);     //���[���m�O 

        setup();
}



