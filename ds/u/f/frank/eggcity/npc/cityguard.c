inherit NPC;
void create()
{
        set_name("�ೣ�u��", ({ "city guard","guard" }) );
        set("long","�@�Ө���ԥҡA�⮳���j���h�L�C�t�d�b�����L�o���Ӫ���H�A��
��i�ê��H�i��L�d�C\n");
        set("level",35);
        set("age",38+random(5));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
    "�u�û��G�S�̡̭A��L���F\n"
}));
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 76);
        set_skill("dodge", 80);

        setup();
        carry_object(__DIR__"obj/fake-armor")->wear();
        carry_object(__DIR__"obj/pike")->wield();
}

