#include <ansi.h>
inherit NPC;

// ���]���A�ͪ���O
void do_heal();

void do_combat();

void create()
{
  set_name( HIW "�������]" NOR, ({"snow troll", "troll"}) );
  set("long",@LONG
���]�]Troll�^�_����_�گ��ܡA�O�@�إީ~�ʡA�ۻ���c���Y�H�Ǫ��A
�����i�F�E�`�A�魫���ʽS�C���]��O����׳��Y�����ƭ��ת̡A�q�`����
�D�`�ժZ���O�A�󽦦����ֽ��л\�ۺ��ѪѪ��٦סA�n���y�L���I�O�A�N��
��A�����}�F�C
LONG
);
  set("age", 400);
  set("gender", "����" );
  set("level", 55);
        set("attack_merits","bar");

        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("block",100);
        set_skill("staff",100);
        set_skill("hammer",100);
        set_skill("unarmed",100);
            set("attitude", "aggressive");
        set("chat_chance", 30);
        set("chat_msg",({
        	(: do_heal() :),
        }) );

		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_combat:), 

		}) );   
  setup();
	carry_object(__DIR__"obj/bloodstar-hammer")->wield();
	carry_object(__DIR__"obj/juniper-shield")->wear();

	if(random(5)==0)
		carry_object(__DIR__"obj/troll_chest_bone");
	if(random(5)==0)
		carry_object(__DIR__"obj/troll_head_bone");
	if(random(5)==0)
		carry_object(__DIR__"obj/troll_spinal_bone");

    carry_object(__DIR__"obj/troll_blood");
	set_temp("apply/armor",150); 
	set_temp("apply/damage",150); 
}

void do_heal() {
	if( !query_temp("weapon") ) command("wield hammer");
	if( query("hp") < query("max_hp") ) {
		message_vision( "$N���W���ˤf�]���A�ͯ�O���ĪG�A�C�C�a��_�F�C\n" , this_object());
		receive_heal("hp", 800);
	}
}

void do_combat()
{
	object target;
	if( is_busy() ) return;
	target = select_opponent();
	if( !target ) return;
	if( query_temp("do_attack") ) return;
	if( !target->is_busy() && random(3) ) {
		message_vision(HIW "$N"HIW"�@�i�f�j�X�F�D�B�N���Ů�A$n"HIW"�Q�᪺�����G�ۡC\n" NOR, this_object(), target);
		target->start_busy(1);
	}
	message_vision(HIR "$N"HIR"��q�s�s�A��յn�ɿE�i���֡I�I\n" NOR, this_object());
	set_temp("do_attack",1);	// mark �קK�h������
	add_temp("apply/damage",50);
	add_temp("apply/hit",300);
		attack();
		attack();
	add_temp("apply/hit",-300);
	add_temp("apply/damage",-50);
	set_temp("do_attack",0);
}
