inherit NPC;
#include "skin_drop.c"
void create()
{
    set_name("�j�ǯT", ({ "gray wolf", "wolf" }) );
    set("race", "beast");
    set("age", 10);
    set("long", "�@�Y���j���c�T, �Ӷզp�q, �S�X�մ˴˪��y���C\n");
    set("attitude", "aggressive");
	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance", 5);
	set("chat_msg", ({
                "�u��~~~~�v�j�ǯT�o�X�@�n��s�C\n",
                "�j�ǯT�o�X�@�n��s�A�n���H�ɳ��n���W�ӡI\n",
	}) );
	set("level", 20);
	set("skin", __DIR__"obj/langpi");
	setup();
}

