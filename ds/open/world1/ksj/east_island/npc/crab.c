inherit NPC;

void create()
{
        set_name("����",({"crab"}) );
        set("long","�@�����x�٤j�Ǫ����ɡA����ۧA���R�ۤj�g�C\n");
        set("race", "���~");    
        set("unit","��");
        set("age",2);
        set("level",4);
        set("attitude", "heroism");  
        set("limbs", ({ "�Y��", "����", "�k�g", "���g" }) ); 
        set("verbs", ({ "bite" }) );         
        set("chat_chance", 15);
        set("chat_msg", ({
        "�����䴧�R���g�@��R�۪w�j�C\n",
        }));              
        setup();
        add_money("coin",20);
}
