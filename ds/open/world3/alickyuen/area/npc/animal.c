#include <ansi.h>
//updated by alickyuen on 26/12
inherit NPC;
void create()
{
	set_name( "�p�ʪ�" , ({ "animal" }) );
	set("long",@long
�@���i�R���p�ʪ��C
long
);
	set("age", 60);
	set("level", 1);
 set("race", "���~");
        set("limbs", ({ "�Y��", "����","�ݳ�","�p��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
	setup();
       set_living_name("reward-war-animal");
}

