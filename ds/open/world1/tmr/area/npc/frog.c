inherit NPC;

void create()
{
        set_name("�е�",({"frog"}) );
        set("long","�@���C��⪺�Υе�A���b�����W�O�O�a�s�ۡC\n");
        set("race", "���~");
        set("env/wimpy", 10);
        set("unit","��");
        set("age",1);
        set("level",1);
      set("str",1);
         set("dex",-1);
      set("attitude","heroism");
        set("limbs", ({ "�Y��", "����", "�}" }) ); //���𳡦�
        set("verbs", ({ "bite" }) );                         //�����覡
        set("chat_chance",6);
        set("chat_msg",({
		"�е�µ����Ū��Ѫťs�D�G�u�O�����O����v\n",
        }) );

        setup();
	add_money("coin",10);
}
