inherit NPC;

void create()
{
        set_name("�U��",({"fish"}) );
      set("long","�@�����q���p���A���ּ֪��y��C\n");
        set("race", "���~");    
        set("env/wimpy", 10);   
        set("unit","��");
        set("age",2);
        set("level",2);
        set("attitude", "heroism");  
      set("str",1);
      set("con",1);
        set("limbs", ({ "�Y��", "����", "�e��", "����" }) ); //���𳡦�
        set("verbs", ({ "bite" }) );                         //�����覡
        set("chat_chance",6);
        
        setup();
        add_money("coin",10);
}

