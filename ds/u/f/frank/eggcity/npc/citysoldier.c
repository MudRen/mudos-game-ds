inherit NPC;
void create()
{
        set_name("�ೣ�B�L", ({ "city soldier","soldier" }) );
        set("long","�@�Ө���ԥҡA�⮳���C���h�L�C�g�`�b�����ն����ޡA���������v�w�C\n");
        set("level",30);
        set("age",35);

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "�u�û��G�S�̡̭A��L���F\n"
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
}

