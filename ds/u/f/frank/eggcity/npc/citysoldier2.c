inherit NPC;
void create()
{
        set_name("�ೣ�Z�L", ({ "city soldier","soldier" }) );
        set("long","���ೣ�S����V�m�X���h�L�A�ӭӨ��j�駧�A���Ť�i�����@�w���V\n"
                   "�m�A�`�O�b�ƬG�o�ͮɲĤ@�ӻ���A���ೣ�����~���V�ӳ��O�������M\n"
                   "���C\n");
        set("level",35);
        set("age",25+random(5));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "�u�û��G�S�̡̭A��L���F\n"
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 80);
        set_skill("dodge", 70);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/fist")->wield();
}
