inherit NPC;

void create()
{
        set_name("����",({"cock"}) );
        set("long","�@�������A�������a���Ө��h�C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",6);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","�}��","�ͻH"}) ); 
        set("verbs", ({ "bite","claw"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�����θ}��½�ʪd�g�A�@��֭��g�̪��p�ΡC\n",
        }));                                
        setup();
        add_money("coin",30);
}
