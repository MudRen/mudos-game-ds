inherit NPC;

void create()
{
        set_name("�Ѫ�", ({ "tiger" }) );
        set("long", "�@���۷��r���Ѫ�C\n");
        set("race", "���~");
        set("gender","����");   // 1999.2.28 �W�[������
        set("age", 12);
        set("level",5);
        
        set("str", 20);
        set("dex", 12);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) ); //���𳡦�
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�Ѫ���Ѩg�q~~�q~~~~�C\n",
                "�Ѫꤣ�h�n�N�����q�A�C\n",
                "�Ѫ�b�A����¶��¶�h�C\n",
                "�Ѫ�ܬ����r�F�A�@�f�A��A�r���z�z�j�s�C\n" }) );
                
        set_temp("apply/damage", 15);   //���[�ˮ`�O
        set_temp("apply/hit", 20);      //���[�R���v
        set_temp("apply/armor", 5);     //���[���m�O 

        setup();
}



