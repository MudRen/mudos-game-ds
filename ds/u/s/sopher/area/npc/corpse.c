inherit NPC;

void create()
{
        set_name("į�ʪ�����", ({ "corpse" }) );
        set("long", "�@�Ӧ��`�w�[�o�|�ʪ�����C\n");
        set("race", "���~");
        set("gender","�۩�");   // 1999.2.28 �W�[������
        set("age", 10);
        set("level",2);
        
        set("str", 54);
        set("dex", 16);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) ); //���𳡦�
        set("verbs", ({ "bite", "claw" }) );
         set("chat_chance", 10);
        set("chat_msg", ({
                (: command("angry") :),
                "���骦�r���A����F�A�}��C\n",
                "����j�ܤ@�n:��~~��~~~�R~~~�ӡC\n",
                "���鼫�㪺�ݵۧA�C\n",
                "�����M���ʤF�C\n" }) );
                
        set_temp("apply/damage", 30);   //���[�ˮ`�O
        set_temp("apply/hit", 20);      //���[�R���v
        set_temp("apply/armor", 0);     //���[���m�O 

        setup();
}

int accept_object(object who, object ob)    //�i�����F��
{
        if( ob->id("water") ) {
                set_leader(who);
                message("vision", name() + "�ͮ𪺻��D:�y�Q�`���ڰڡH���ڳܸt��!�z\n", this_player());
                return 1;
        }
}
