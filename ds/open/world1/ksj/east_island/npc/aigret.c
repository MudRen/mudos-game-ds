inherit NPC;

void create()
{
        set_name("���O��",({"aigret"}) );
        set("long","���۳��ժ��Ф��������L�ڡA�g�`�X�{�b�A�СB�e��V���C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",6);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����","���}","�ͻH"}) ); 
        set("verbs", ({ "poke" }) );     
        set("chat_chance", 10);
        set("chat_msg", ({
        "���O����L�Y�h��z�ͻH���Ф�C\n",
        }));                                
        setup();
        add_money("coin",20);
}
