// Npc: /u/l/luky/npc/1.c

inherit NPC;

void create()
{
set_name("�p��", ({ "little bug","bug" }) );
set("age", 1);
set("level",1);
set("long", @LONG

�@���p�Τl, �]���o�{�A�b�ݨe�ӥ��b�˦��C

LONG
);
set("con",1);
set("str",1);
set("dex",1);
set("int",1);
set("race","���~");
set_temp("apply/hit",-20);	//�z�ƩR���v
set_temp("apply/dodge",-20);	//�z�ư{���v
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"})); //���𳡦�
set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
setup();
}
