inherit NPC;

void create()
{
        set_name("�d��",({"loach"}) );
        set("long","�@���Ƥ��ȥ᪺�d�ϡA���b�d�ڸ��ٯu�ݤ��ӥX�ӡC\n");
        set("race", "���~");    
        set("unit","��");
        set("age",1);
        set("level",3);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","����"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�d�Ϧb����½�u�@�}�A�����ܱo�ÿB���M�C\n",
        }));                                
        setup();
        add_money("coin",10);
}
