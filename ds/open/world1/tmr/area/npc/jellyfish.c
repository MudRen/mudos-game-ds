inherit NPC;

void create()
{
        set_name("����",({"jellyfish"}) );
        set("long","�@���b�z���������A���b���ʥ���Ĳ�⮷������...�C\n");
        set("race", "���~");
        set("env/wimpy", 20);
        set("unit","��");
        set("age",5);
        set("level",2);
        set("attitude", "heroism");  
        set("str",-2);
        set("dex",3);
        set("limbs", ({ "�Y��", "����", "Ĳ��" }) ); //���𳡦�
        set("verbs", ({ "bite","claw" }) );                         //�����覡
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
	add_money("coin",30);
}
