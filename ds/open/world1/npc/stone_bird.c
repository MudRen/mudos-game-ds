inherit NPC;

void create()
{
        set_name("���]��", ({ "stone bird","bird" }) );
        set("race","beast");
        set("unit","��");
        set("level",35);
        set("age",20);
        set("evil",-10);
        set("long",@LONG
�����B�ਭ�B�������l�B�D�����_���]�~�A�ڻ��Q�e�A�G�L
���H���|�Ƭ��۹��C
LONG
);
        set("limbs", ({ "�Y��", "����", "��}","�e�}"}));
        set("verbs", ({ "crash","hoof","claw","poke" }));
        setup();
        //carry_object(__DIR__"../eq/mb_wing");
}

void die()
{
	carry_object(__DIR__"../eq/mb_wing");
	::die();
}