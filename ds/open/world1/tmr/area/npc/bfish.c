inherit NPC;

void create()
{
        set_name("�j��",({"big-fish","fish"}) );
        set("long","�@�����ά����j���A���|�B��ʧ�M�����C\n");
        set("race", "���~");
        set("env/wimpy", 20);
        set("unit","��");
        set("age",4);
        set("level",3);
          set("attitude", "heroism");
      set("str",2);
      set("dex",1);
        set("limbs", ({ "�Y��", "����", "�e��", "����" }) ); //���𳡦�
        set("verbs", ({ "bite" }) );                         //�����覡
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
	add_money("coin",30);
}
