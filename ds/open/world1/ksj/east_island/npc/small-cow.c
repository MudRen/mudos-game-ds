inherit NPC;

void create()
{
        set_name("�p�Ť�",({"small cow","cow"}) );
        set("long","�T�Ӥ�j���p�Ť��A�ݰ_�Ӳ����������C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",1);
        set("level",10);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","�e�}","��}","����"}) ); 
        set("verbs", ({"hoof","crash"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�p�Ť����ɿ��Ħa�S�]�S�ޡC\n",
        }));                                
        setup();
        add_money("coin",100);
}
