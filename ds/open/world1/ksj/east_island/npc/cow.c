inherit NPC;

void create()
{
        set_name("�Ť�",({"cow"}) );
        set("long","�@�����~���Ť��A���b�����Y�Y��C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",5);
        set("level",15);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","�e�}","��}","����"}) ); 
        set("verbs", ({ "hoof","crash"}) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "�Ť��r�F�@��C��A�C�����z�a�Z���ۡC\n",
        }));                                
        setup();
        add_money("coin",200);
}
