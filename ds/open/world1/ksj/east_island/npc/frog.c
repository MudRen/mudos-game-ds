inherit NPC;

void create()
{
        set_name("�е�",({"frog"}) );
        set("long","�ڴx�j���C��A�@�Ƹ����Ӱʪ��ˤl�C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",1);
        set("level",3);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","�e�}","��}"}) ); 
        set("verbs", ({ "crash" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�е칪�_���U�A�O���O��a�s�ۡC\n",
        }));                                
        setup();
        add_money("coin",10);
}
