inherit NPC;

void create()
{
        set_name("���D",({"water snake","snake"}) );
         set("long","�@�������@�ت����D�A�ݰ_�Ӻ��Ź����A�u�n�A���h�S�����ܡC�C\n");
        set("race", "���~");
        set("env/wimpy", 20);
        set("unit","��");
        set("age",4);
        set("level",3);
        set("attitude", "heroism");  
        set("str",1);
        set("con",1);
        set("dex",1);
        set("limbs", ({ "�Y��", "����", "����", "����" }) ); //���𳡦�
        set("verbs", ({ "bite" }) );                         //�����覡
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
add_money("coin",50);
}
