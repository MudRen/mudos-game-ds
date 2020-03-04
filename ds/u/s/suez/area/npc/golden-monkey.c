
#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N����$n�����W��$n��$l�r�r",
		"attact_type":  "bar",	// �]�w�ޯ઺��������
					// ������ �ͪ�(bio) �~��(bar)
					// �]�k(wit)���F(sou)���(tec)
		"damage_type":	"�r��",
	]),
	([	"action":		"$N�@����$n��$l��F�L�h",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N��F�@��g�۹��$n��$l��F�L�h",
		"attact_type":  "bar",
		"damage_type":	"���",
	]),
	([	"action":		"$N����$n���W�ΤO�ԧ�$n��$l",
		"attact_type":  "bar",
		"damage_type":	"�Զ�",
	]),
});

void do_clean();
#include <ansi.h>
void create()
{
        set_name(HIY"��������"NOR,({"golden-monkey", "monkey" }) );
	set("long",@LONG

    ������j�j�������A�F������ۧA�A�����⹳�����@�몺�֤�{�{ 
�o���A�i�R���ˤl���A�Ԥ���Q��e�@��C�i�O�e�X�G���A���@�b�j�A�[
�W�e�L���Τ���W�����A�ݨӨe�i��S�A�Q�������i�R��T


LONG
);
        set("limbs", ({
		"�Y��",	"�ݤf",	"�I��",	"�y��",	"�v��",	"���u","�L��",
	}) );
        set("age",70+random(70));
        set("level",40);
        set("dex",100);
        set("gender","����");
        set("race","���~");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	"��������n���@�����ۤ@�Ǫ��g��A�����D�b������C\n",
  	"�������᮳�_�a�W��O�O���׶��A���L���C�Z�ۡC\n",
}));
      set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C

	set_skill("mob_bite", 64);
	set_skill("dodge", 100);
	set("addition_armor",20);
	set("addition_damage",20);
	set("default_actions", (: call_other, __FILE__, "query_action" :));

        setup();
}

int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIR"$N����$n�����W�A�@���U���@���V$n�����V�T\n"NOR,me,victim);
	if(hitrole > 100)
	{
		message_vision(MAG"$n�Q�U������Aı�o�˳B�@�}���o�C\n"NOR,me,victim);
		victim->receive_damage("hp",50+random(20),me);
                        victim->start_busy(3);
		return 1;
	}
	else message_vision(HIW"$n���$N�ΤO�@�ϡA�N$N�L��Ƥؤ��~�C\n"NOR,me,victim);
            me->start_busy(3);
	return 1;
}
mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->add("popularity",1); //�n��
 message_vision( "$N ���ѤF���������A�N�������᪺�֭�F�U�ӡA�d�U�@���O�O���Ͷ��C"  ,ob );  
       obj=new(__DIR__"eq/golden_m_s");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}
