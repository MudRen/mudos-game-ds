inherit NPC;

void create()
{
        set_name("�p��",({"small fish","fish"}) );
        set("long","�@���p���A���b�����ӱ��a��Ӵ�h�C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",2);
        set("attitude", "heroism");  
        set("str",1);
        set("con",1);
        set("limbs", ({ "�Y��", "����", "�e�_", "����" }) ); 
        set("verbs", ({ "bite" }) );                       
        setup();
        add_money("coin",10);
}

