// Jay 3/17/96

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;

void create()
{
        set_name("�X����", ({"rousi whip", "whip"}));
        set_weight(60);
		if (clonep())
			set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("rigidity", 1);
                set("unique", 1);
                set("long", "�o�O�@��L�ӳz��, �X�D�ײ��ү��������C\n");
                set("value", 3500);
                set("material", "leather");
                set("wield_msg", "$N������X�@��$n�M�b��W�C\n");
                set("unwield_msg", "$N�N�⤤��$n�����@�ΡA��J�S���C\n");
        }
        init_whip(20);
        setup();
}
/*
void init()
{
        add_action("do_tao","tao");
}

int do_tao(object me, object target)
{
        string msg;

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("�A�u��b�԰�������ŧ���ΡC\n");

        if (me->is_busy()) 
                return notify_fail("�A�{�b�����۩O�C\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang" ||
            me->query_skill_mapped("strike") != "chousui-zhang" ||
            me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("�A�������N�ƥ\�j�k�\�M����x�k�ۤ��t�X�A�~��ϥάX�����I�C\n"); 
       
        if( (int)me->query_skill("huagong-dafa",1) < 80 )
                return notify_fail("�A���ƥ\�j�k�\�O�����A�ϥΤ��F�X�����I\n");
        if( (int)me->query_skill("chousui-zhang",1) < 80 )
                return notify_fail("�A������x�\�O�����A�ϥΤ��F�X�����I\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("�A�Q��ŧ�ۤv�ڥ������L���H�H�䦺�ڡH\n");
 

        tell_object(me, HIW "\n�A������}�X�����A�ʰʤ��O�@���_���a�@�\�C\n\n" NOR);
                 

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            random(10) > 5) 
               {
                msg = HIR"$n���M�ʧ@�@�y�A���M���Q�H�j��F�@�ˡI\n" NOR;
                tell_object(target, HIB "\n�A���l��M�@��A�~�o�{�ۤv������ı���Q�H�ΪF��M��F�I\n\n" NOR);
                target->start_busy(4);
                } 
          else {
                me->start_busy(2);
                msg = HIY"���M�����@�{�A���n�Ө�$N�ߥX�F����F��A���G�Q$n���F�a���F�}�h�C\n" NOR;
                tell_object(me, HIB "\n�A��Mı�o�����j�F�ܦh�A�V�|�I�ۤv�����ϳQ�o�{�F�I\n\n" NOR);
                tell_object(target, HIB "\n�A��M�ݨ��F�@���ȥզ⪺�F��b�����U�@�{�A���W�D�F�}�h�I\n\n" NOR);
                }

        message_vision(msg, me, target);
        me->add("neili", -50);
        me->add("shen", -(random(200)));
        return 1;
}
*/