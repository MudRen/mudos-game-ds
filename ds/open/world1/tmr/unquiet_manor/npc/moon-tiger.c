#include <ansi.h>
inherit NPC;

void combat_ai() {
                if( is_busy() ) return;
                if( query_temp("do_attack") ) return;
                message_vision(HIC "��v�Q�������겴�S�����A�ĤW�ӤF�X�B�I�I\n" NOR, this_object());
                set_temp("do_attack",1);    // mark �קK�h������
                add_temp("apply/damage",50);
                add_temp("apply/hit",300);
                        attack();
                        attack();
                add_temp("apply/hit",-300);
                add_temp("apply/damage",-50);
                delete_temp("do_attack");
}

void create()
{
        set_name(HIY "��v�Q��������" NOR,({"moon-shadow tiger","tiger"}) );
        set("title",CYN "" NOR);
        set("long",@LONG
�o�ئѪ�q�Ⲵ�����ڦy���æ��@�����u�A�u���b�P��M��
���U��i�o���A�D�O�m�����q�Сn�����W�������u��v�Q������
��v�C
LONG    
        );
        set("race", "tiger");    
      	set("title",HIG"�L�����"NOR);
        set("unit","��");
        set("age", 600);
        set("level", 55);
        set("attitude", "aggressive");
        set("limbs", ({ "�Y��", "����","�ݳ�","����","��f","���" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_hp", 5000);
        add("addition_armor", 90);
        add("addition_damage", 80);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:combat_ai:), 
          }) );        
        setup();
//        set_living_name("_UNQUIET_MANOR_NPC_");
  	    set_temp("apply/bar", 3);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
        set_temp("apply/damage",50);

	    if( random(100) < 50 ) carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_plate");
		carry_object(__DIR__"obj/moon-mask")->wear();
}


