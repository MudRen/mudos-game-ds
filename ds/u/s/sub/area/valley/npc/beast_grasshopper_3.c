inherit NPC;

void create()
{
        set_name("�p�K�g", ({"small grasshopper","small","grasshopper"}) );
        set("long",@LONG
�@�����۶ø����p�K�g�A�����a�b���O�̸��Ӹ��h�C
LONG);
        set("unit","��");
        set("race", "beast");
        set("limbs", ({ "�Y��", "����", "��L", "�ͻH"})); 
        set("verbs", ({ "bite","poke","crash" })); 
        set("age", 1);
        set("level",3);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-30);    
        set("chat_chance",1);
        set("chat_msg",({
               (: random_move :),
        }));

        setup();
}
