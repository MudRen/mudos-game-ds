inherit NPC;

void create()
{
set_name("�H�~��",({"pagurian"}));
set("race", "���~");
set("level",13);
set("age",5);
set("long","�@�����⪺�H�~�ɥ��������q�A�����e�w�w���L�C\n");
set("limbs", ({ "�Y��", "����", "�e�g", "����","����"}));
 set("verbs", ({ "bite"}));
set("chat_chance",30);
set("chat_msg",({
(:command("east"):),
(:command("west"):),
(:command("north"):),
(:command("south"):),
}));
set("amount",1);
        setup();
add_money("coin",random(200));
}

