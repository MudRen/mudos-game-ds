#include <ansi.h>
inherit NPC;

// ���]���A�ͪ���O
void do_heal();

void create()
{
  set_name( HBK "���ƥ��]" NOR, ({"terror troll", "troll"}) );
  set("long",@LONG
���]�]Troll�^�_����_�گ��ܡA�O�@�إީ~�ʡA�ۻ���c���Y�H�Ǫ��A
�����i�F�E�`�A�魫���ʽS�C���]��O����׳��Y�����ƭ��ת̡A�q�`����
�D�`�ժZ���O�A�󽦦����ֽ��л\�ۺ��ѪѪ��٦סA�n���y�L���I�O�A�N��
��A�����}�F�C
LONG
);
  set("age", 200);
  set("gender", "����" );
        set("attack_merits","bar");

        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("block",100);
        set_skill("staff",100);
        set_skill("hammer",100);
        set_skill("unarmed",100);
            set("attitude", "aggressive");
  set("level", 45);
        set("chat_chance", 30);
        set("chat_msg",({
        	(: do_heal() :),
        }) );
  setup();
	carry_object(__DIR__"obj/bloodstar-hammer")->wield();
	carry_object(__DIR__"obj/juniper-shield")->wear();

	if(random(5)==0)
		carry_object(__DIR__"obj/troll_chest_bone");
	if(random(7)==0)
		carry_object(__DIR__"obj/troll_head_bone");
	if(random(10)==0)
		carry_object(__DIR__"obj/troll_spinal_bone");
	if(random(5)==0)
		carry_object(__DIR__"obj/troll_blood");
	set_temp("apply/armor",150); 
}

void do_heal() {
	if( !query_temp("weapon") ) command("wield hammer");
	if( query("hp") < query("max_hp") ) {
		message_vision( "$N���W���ˤf�]���A�ͯ�O���ĪG�A�C�C�a��_�F�C\n" , this_object());
		receive_heal("hp", 500);
	}
}
