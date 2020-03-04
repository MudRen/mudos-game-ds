// venomsnake.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�r�D", ({ "snake" }) );
	set("long","�@�������R�H���C�˵����������a�n�ۧA�C\n");
	set("level",30);
	set("race","���~");
	set("age", 3);
	set("pursuer", 1);	// mob �|�l���a


	set("limbs", ({ "�Y��", "����", "����" }) );
	set("verbs", ({ "bite" }) );


        set("chat_chance",60);
        set("chat_msg",({
           (:command,"east":),
           (:command,"west":),
           }));

	setup();
}

int hit_ob(object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("poison") < 10 ) {
		ob->apply_condition("poison", 20);
		tell_object(ob, HIG "�Aı�o�Q�r�����a��@�}���o�T\n" NOR );
	}
}   

