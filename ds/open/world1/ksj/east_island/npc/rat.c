inherit NPC;

void create()
{
        set_name("�й�",({"rat"}) );
        set("long","��κӤj���ѹ��A�Q���Y�F���ֹA�@���C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",4);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","����"}) ); 
        set("verbs", ({ "bite" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�й��@��s�s�s�A�@��b�g�����{���C\n",
        }));                                
        setup();
        add_money("coin",10);
}
