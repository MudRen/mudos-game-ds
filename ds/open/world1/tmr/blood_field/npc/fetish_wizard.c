#include <ansi.h>
inherit NPC;

void do_fire() 
{
        object target;
        int dmg;
        if( is_busy() ) return;

        target = this_object()->query_opponent();
        if(!objectp(target)) return;
        message_vision(HIW"$N"HIW"���X����A�۳�X�@�T���b�Y�V$n"HIW"...\n"NOR,this_object(),target);
        dmg = this_object()->query_damage() - target->query_shield();
        if(dmg<10) dmg = 10 + random(30);
       	dmg = COMBAT_D->Merits_damage(this_object(), target, dmg, "bio");
        if( random(200) > target->query_skill("dodge") ) {
                message_vision(HIR"��a�@�n�A���b���$n"HIR"���n�`�I�I�I\n"NOR,this_object(),target);
                target->receive_damage("hp", dmg, this_object());
        } else {
                message_vision(CYN"���O���b�n�n�ױת��g�n�F�C\n"NOR,this_object(),target);
        }
}
void create()
{
        set_name("�g�H���v", ({ "fetish wizard","fetish","wizard","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
���ǹ��Ю{�몺�ͪ��A�|�H�M�L�̨��߮t���h���M�ӧ����A�p�g�H��
���O�O�L�����~���A�@��٬��L�̬����H�ڡA������p�B�Q���o�����ͪ�
�A��W���p�g�H�Q���ܮz�ӥB�i�H�������ˡC�Ӥg�H�ڸs�������v��O��
�M�������ժ��̡A�㦳����������ĤH����O�C
long
);
        set("title","��{�");
		set("race","evil");
		set("level", 28 + random(5));
        set("age", 120);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: do_fire :),

        }) );

        set("attitude", "aggressive");
        setup();
        switch(random(4)) {        
        case 0:
                carry_object(__DIR__"obj/boots")->wear();
        break;
        case 1:
                carry_object(__DIR__"obj/belt")->wear();
        break;
        case 2:
                carry_object(__DIR__"obj/ring")->wear();
        break;
        case 3:
                carry_object(__DIR__"obj/armor")->wear();
        break;
        }        
        carry_object(__DIR__"obj/staff")->wield();        
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/blood_pill");
        carry_object(__DIR__"obj/q_stone");
        carry_object(__DIR__"obj/q_stone");

}

