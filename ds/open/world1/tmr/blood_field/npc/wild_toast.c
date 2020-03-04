#include <ansi.h>
inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name(HIC"��g�q"NOR, ({ "field toast", "toast", "_BLOOD_FIELD_NPC_" }) );
        set("long",@long
���ǹ��Ю{�몺�ͪ��A�|�H�M�L�̨��߮t���h���M�ӧ����A�p�g�H��
���O�O�L�����~���A�@��٬��L�̬����H�ڡA������p�B�Q���o�����ͪ�
�A��W���p�g�H�Q���ܮz�ӥB�i�H�������ˡC�Ӥg�H�ڸs������g�q��
�O�۵M�������ժ��̡A�åB�|�I�B�ަ�ӧ����۷S�L�̪��H�C
long
);
        set("title", HIR"��{�"NOR);
        set("race", "evil");
        set("age", 300);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
	      	(: do_fight_help :),        
			(: do_fight_heal :),      
        }) );

        set("attitude", "aggressive");
        set("addition/bar", 5);
        set("addition/wit", 5);
        set("addition_armor", 100);
        set("addition_damage", 150);
        set("addition_shield", 200);
          set("level", 40+random(5));

        setup();
        set_temp("apply/hit", 50);

        carry_object(__DIR__"obj/wizard_hat")->wear();
        carry_object(__DIR__"obj/wizard_gloves")->wear();
        carry_object(__DIR__"obj/wizard_pants")->wear();

        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");
}


