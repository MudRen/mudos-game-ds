#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(YEL"�����L�u��"NOR, ({ "goblin guard","guard" }) );
        set("long","�}�ޤJ�f���ݦu�̡C\n");
        set("race", "human");
        set("gender","����");
        set("level",20);
        set("age",25);

        set("combat_exp", 1000);

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	HIW"�����L�u�æ��G�@���Q�n��P��������I�I�J�̡C\n"NOR,
	}));
        setup();
        carry_object(__DIR__"wp/longsword")->wield();

}
void die()
{
   	object me;
   	object env = load_object("/u/s/sdo/pwest/hill1.c");
   	if( !me = query_temp("last_damage_from") )
   	me = this_player();
   	if( !me )
   	{
     		::die();
     		return;
   	}
   	env->call_monster();
   	message_vision(
   	"\n\n$n"HIY"�o�X�@�n�Y�F���s�n�A��ʤF�s�}�̪��Ǫ��̡I\n\n"NOR,me,this_object());
   	::die();
   	return;
}