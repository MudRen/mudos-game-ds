inherit NPC;

void create()
{
	set_name("�Q��", ({"squirrel"}) );
	set("long", @LONG
�@���p�ʪ�, �b��W�]�Ӷ]�h�C
LONG	);
	set("unit","��");
	set("race", "���~");
	set("limbs", ({ "�Y��", "����", "��}","�e�}"})); //���𳡦�
	set("verbs", ({ "crash","bite", "claw" })); //�������A��hoof��crash�rbite��claw��poke
	set("age", 1);
	set("max_hp",56);
	set("level",2);
	set("dex",3);
	setup();
}