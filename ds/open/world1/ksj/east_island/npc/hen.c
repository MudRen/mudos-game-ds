inherit NPC;

void create()
{
        set_name("����",({"hen"}) );
        set("long","�@�������A�������a���Ө��h�C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",5);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","�}��","�ͻH"}) ); 
        set("verbs", ({ "bite","claw"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�������㫣��a�s�ۡC\n",
        }));                                
        setup();
        add_money("coin",25);
}
