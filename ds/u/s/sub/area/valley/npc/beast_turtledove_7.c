inherit NPC;
void create()
{
    set_name("����", ({"turtledove","dove"}) );
        set("long",@LONG
�@���p�����n�������A���b�o�̪F�ְ֡A���䪺�V���C
LONG);
        set("unit","��");
        set("race", "beast");
        set("limbs", ({ "�Y��", "����", "����", "�ͻH", "����" })); 
        set("verbs", ({ "bite","poke","claw","crash" })); 
        set("age", 1);
        set("level",7);
        set_temp("apply/hit",10);      
        set_temp("apply/dodge",20);    
        set("chat_chance",5);
        set("chat_msg",({
               (: random_move :),
        }));

        setup();
}
