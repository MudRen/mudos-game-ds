//  �w�b1.0���ժ� 
//           By Uchimaha
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
        int sk, lv, wis, heal, reheal;
        // �� !arg �M arg =="?" ��X
        // �o�ئ��Ѽƪ�exert skill.. �Х[�W�Ѽƻ���. Luky
        if( !arg || arg == "?" )
        {
                write(@SKILL_HELP

        ���ްw�b�ϥΤ�k:       exert moxibustion.�\�� on �Y�H
        �D�԰��\��G
             �m����Z�nrekee       ����AP�Ӧ^��HP
             �m����Z�nregin       ����MP�Ӧ^��AP
             �m�����Z�nresen       ����AP�Ӧ^��MP
             �m�}�ѳZ�nsky         ����MP�Ӧ^��AP,HP
             �m���@�Z�nadvkee      ����AP�Ӧ^�Фj�qHP
             �m¡���Z�nheal        ����MP�Ӫv¡�ˤf 
             �m���߳Z�naddint      ���Ӥj�qAP,MP��INT���� ( �i�� ) lv 27
             �m�T�J�Z�naddcon      ���Ӥj�qAP,MP��CON���� ( �i�� ) lv 28
             �m�h�ƳZ�nreheal      ���Ӥj�qAP,MP��DEX���� ( �i�� ) lv 29
             �m�i�ͳZ�naddstr      ���Ӥj�qAP,MP��STR���� ( �i�� ) lv 30
             �m�������Z�ngod     ���Ӥj�qMP�A������¡ ( �i�� ) lv 35
             �m�����@��Z�nghost   ����AP,MP,HP��DAMAGE,ARMOR���� ( �i�� ) lv 40
        �԰��\��G
             �m�Ѥ��Z�nover        ����HP,AP�A�ϩR���{������ lv 25
             �m���d���_�Z�nattack  ���ӥ���AP,MP�t�`�@�Y ( �i�� ) lv 35
        PS. ( �i�� ) - ���i���~�i�ϥΡC

SKILL_HELP      );
                return 1;
        }

        if( arg == "rekee" )
        {
                sk = (int)me->query_skill("moxibustion");
                sk = (sk > 50) ? 50 + (( sk-50 )/2) : sk;
                lv = me->query_level();
                wis = me->query_wis();
                heal = (int)me->query("max_hp");
                heal = (heal > 4000) ? 4000 + (heal-4000)/8 : heal;
                reheal = (heal / 15) + ((sk/5)*3) + random(9) + (lv/2);

                if( me->query("hp") < 0 )
                        return notify_fail("�A�ثe���x�����A, �L�k�ϥΪ��ްw�b�I\n");
                if( me->query("ap") < 20 )
                        return notify_fail("�A�ثe�����p���ΡA�L�k�ϥΪ��ްw�b�C\n");
                if( me->query_skill("moxibustion") < 10 )
                        return notify_fail("�A�����ްw�b��¦�����I\n");
                if( me->query_skill("acupuncture_cognition") < 5 )
                        return notify_fail("�A���޹D�{����¦�����I\n");
                if( objectp(target) && target->query("hp") >= heal )
                        return notify_fail(target->name(1) + "�ثe���ͩR���p�w�g�O�����F�C\n");
                else if( !objectp(target) && me->query("hp") >= heal )
                        return notify_fail("�A�ثe���ͩR���p�w�g�O�����F�C\n");

                if( !objectp(target) ) target = me;
                target->receive_heal("hp",reheal);
                me->receive_damage("ap", 27 + reheal/8 + random(4));
                me->start_busy(2);

                message_vision(YEL"\n$N���ؾ���, �N��l�B��⤤�Ȱw, �ǳƨϥX�|���w�b���u"+HIC+"�i����j"+NOR+YEL"�v�Z�C\n"NOR, me);
                message_vision(YEL"\n$N���M�M�S�@�n, �⤤�Ȱw���I$n�߯�, �ʦ�F$n�ˤf���˶� !!\n"NOR, me, target, target);
                message_vision(YEL"\n$N���ˤf����y�������F....\n"NOR, target );

                me->improve_skill("moxibustion",me->query("int")/4 + random(4));
                me->improve_skill("acupuncture_cognition",me->query("int")/4 + random(3));
                return 1;
        }
        else return notify_fail("���ްw�b�S���o�إ\\��I\n");
}

void skill_improved(object me) // �`�N, �@��skill��W�[���ݩ��`�M�H 5 ���W��
{
        int b,c;
        b = me->query_skill("moxibustion",1);
        c = me->query("skill/moxibustion"); 
        
        if( b % 20==19 && b > c)
        {
                if(random(2))
                {
                        tell_object(me, HIW "�A�����z�ѩ�⮩��`�h���w�b�Ӵ����F�C\n" NOR);
                        me->add("addition/dex", 1);
                }
                else
                {
                        tell_object(me, HIW "�A�����ѩ�⮩��`�h���w�b�ӼW�j�F�C\n" NOR);
                        me->add("addition/con", 1);
                }
                me->set("skill/moxibustion", b);
        }
        me->save();
}

int improve_limite(object ob)
{
        int a;
        
        a=(ob->query("level")*3)+(ob->query_int());
        if( a > 90 && ob->query("level") < 26 ) a=100;
        else if( a > 100 ) a =100;
        return a;
}

