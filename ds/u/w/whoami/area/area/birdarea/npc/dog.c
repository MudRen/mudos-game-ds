inherit NPC;

void create()
{
        set_name("�ݪ���", ({"watchdog","dog"}) );
        set("long", "�@�����߯կժ��ݪ����A�}���O�@�J�f�E\n");
        set("unit","��");
        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}" })); //���𳡦�
        set("verbs", ({ "bite","poke","crash" })); //�������A��hoof��crash�rbite��claw��poke
        set("age", 5);
        set("level",20);
        set("dex",50);
        set("str",50);
        set("con",50);
        set_temp("apply/hit",20);      
        set_temp("apply/dodge",20);    
        set("max_hp",3000);
        set("evil",-10);
        setup();
}
