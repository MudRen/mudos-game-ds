inherit NPC;

void create()
{
        set_name("�ѹ�", ({"mouse"}) );
        set("long", "�@�����ߪ��ѹ�,�s�s���b�A���䪦�Ӫ��h.\n");
        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"})); //���𳡦�
        set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
        set("age", 2);
        set("level", 5);
        set("con",1);
        set("str",1);
        set("dex",10);
        set("int",1);
        setup();

}

