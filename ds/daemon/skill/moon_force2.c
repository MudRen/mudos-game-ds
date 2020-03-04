// v1.02 ��
// 1. Luky del idle
// v1.01 ��
// 1. �W�[ �e�� adv
// QC: Luky [10.21.1999] �}���ڴ���.
/* �e���� �G �ݤ�ߪk(moon_force) �� Cominging �� 1999/5/29 ��ҳ� */
//�ץ��ݼv�Z�j�� by linjack
// luky del idle
// �p�G�@�w�n��. ���۷|�����L. ���N�ЧA�̶}�o�@�M�����a
// �Ϋ��O�ӹB�𪺨t��. ��p������ɭԸӹB��� ( motion ���F )
// �o�Өt�έn�����a����� robot�A�]�N�O����άۦP�����ܰT��.

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void arc(object me,object target);
void long_arc(object me, object *tar);
void rewield(object me, object weapon);
void moon_shadow(object me, int ar1, int ar2);
void help(object me);

string *random_train_msg = ({
                                "�A���b���i�����A�Ȯɤ��ಾ�ʡC",
                                "�A�{�b���b�m�\���A�L�k�����󲾰ʪ��ʧ@�I",
                                "��m�\�䨫���H",
                                "���p�A�Q�n��ʡA�Х�����m�\�A�_�h�N�B�𤣶��Ө����J�]�F�I"
                            });

string help_msg = @SKILL_HELP

                  �ݤ�ߪk�ϥΤ�k:       exert moon_force <�Ѽ�>
                  �Ѽ�:
                  recover         ����AP�Ӧ^��HP
                  moon-arc        �N���u�W�����O�Ƭ��뫬��l�_���ĤH�Z��
                  long-arc        ���뫬��l, �N�i�������� ( �i�� )
                  shadow          �i�H�W�[�{�����ޯ� - �ݼv�Z ( �i�� )

                                            PS. ( �i�� ) - ���i���~�i�ϥΡC

                                            SKILL_HELP;

                                            int exert(object me,object target, string arg)
                                            {
                                                int heal,reheal,sk,lv;
                                                int p, ar1=0, ar2=0;
                                                object weapon, *tar;
                                                sk = me->query_skill("moon_force");

                                                //�o�ئ��Ѽƪ�exert skill.. �Х[�W�Ѽƻ���. Luky
                                                return notify_fail("BUG �Ӧh, �ݭ�..!\n");
                                                if( arg == "?" )
                                                {
                                                    write(help_msg);
                                                    return 1;
                                                }

                                                if( arg=="off" )
                                                {
                                                    if( me->query_skill_mapped("force")!="moon_force" )
                                                        return notify_fail("�A�èS���b�B�\\�C\n");
                                                    me->delete_temp("is_busy/moon_force");
                                                    message_vision(HIY"$N���_���Ⲵ�C�C�C�}�A�����S�y�^�g�ߤ��F�C\n"NOR,me);
                                                    me->map_skill("force");
                                                    return 1;
                                                }

                                                if( me->query_skill_mapped("force")=="moon_force" )
                                                    return notify_fail("�A�{�b�٦b�׷Ҵݤ�ߪk���C\n");

                                                if( !arg )
                                                {
                                                    return notify_fail(help_msg);
                                                    if( me->is_fighting() )
                                                        return notify_fail("�A�{�b�����ۥ��[, �S�Žm�\\�C\n");
                                                    if( me->query("hp") < 20 || me->query("ap") < 20 )
                                                        return notify_fail("�A�ثe�����p���ΡA�L�k�׷Ҥߪk�C\n");
                                            if( !me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3) )
                                                        if( me->query_temp("class_wind/on_shadow") )
                                                            return notify_fail("�ثe�A���b�ϥδݼv�Z�I\n");
                                                        else return notify_fail("�A�����B�\\���ʧ@�٨S�����C\n");
                                                    //		if( me->query_skill("moon_force",1) < 85 )
                                                    //			return notify_fail("�A���ݤ�ߪk�ڥ��٤��Φۤv�׷�, �h��Ѯv�ǧa�C\n"); //�o��Idle Skill. Luky

                                                    message_vision(HIC"$N�H�a�L�}���U�A��B���e�A�E�Ȥ��Ӿi���C\n"NOR,me);

                                                    me->map_skill("force","moon_force");
                                                    me->receive_damage("ap", 5);
                                                    me->receive_damage("hp", 2);
                                                    me->set_temp("is_busy/moon_force", random_train_msg[random(sizeof(random_train_msg))]);
                                                    me->start_busy(2);
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me:), 2);
                                                    return 1;
                                                }

                                                if( arg=="recover" )
                                                {
                                                    sk = (int)me->query_skill("moon_force");
                                                    sk = (sk > 50) ? 50 + (( sk-50 )/2) : sk;
                                                    lv = (int)me->query("level");
                                                    heal = (int)me->query("max_hp");
                                                    heal = (heal > 4000) ? 4000 + (heal-4000)/8 : heal;
                                                    reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);

                                                    if( me->query("ap") < 20 )
                                                        return notify_fail("�A�ثe�����p���ΡA�L�k�ϥδݤ�ߪk�C\n");
                                                    if( me->query_skill("moon_force") < 10 )
                                                        return notify_fail("�A���ݤ�ߪk��¦�����I\n");
                                                    if( me->query("hp") >= heal )
                                                        return notify_fail("�A�ثe���ͩR���p�w�g�O�����F�C\n");

                                                    me->receive_heal("hp",reheal);
                                                    me->receive_damage("ap",27 + reheal/7 + random(4));
                                                    me->start_busy(2);

                                                    message_vision(HIR"$N�@�ɶ��R�U�ߨӡA�B���I�F���W�U�ˤf�Ǫ��j�ޡC\n"NOR,me);

                                                    me->improve_skill("moon_force",me->query("int")/8 + random(3));
                                                    me->improve_skill("force",me->query("int")/7 + random(3));

                                                    return 1;
                                                }

                                                if( arg=="moon-arc" )
                                                {
                                                    if( !me->is_fighting() )
                                                        return notify_fail("�A�èS���b�԰����C\n");
                                                    if( me->query_skill("moon_force") < 45 )
                                                        return notify_fail("�A���ݤ�ߪk�ä��������I\n");
                                                    if( !target ) target = offensive_target(me);
                                                    if( !target ) return notify_fail("�A�n��֨ϥΡu����v�H\n");

                                                    weapon=target->query_temp("weapon");
                                                    if( !weapon )
                                                        return notify_fail("�Ĥ�èS�����Z���A�u����v�L�k�o���ĥΡC\n");
                                                    if( me->query("hp") < 100 || me->query("ap") < 100 )
                                                        return notify_fail("�A�����骬�p���n�C\n");

                                                    message_vision("\n$N����@�X�@���A�H�ŵ깺���X�@���u����v�C\n"
                                                                   HIY "��������ͩR�@��A�H�ֱ��L�۪��e�t��V$n���Z��������I�I\n" NOR,me,target);

                                                    me->receive_damage("hp",30);
                                                    me->receive_damage("ap",50);
                                                    me->start_busy(2);
                                                    me->improve_skill("moon_force",me->query("int")/6 + random(4));
                                                    me->improve_skill("force",me->query("int")/5 + random(4) );
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "arc", me,target:), 2+random(1) );
                                                    return 1;
                                                }

                                                if( arg == "long-arc" ) // wind adv ���\��: ������
                                                {
                                                    if( me->query("level") < 30 )
                                                        return notify_fail("�A�������٤����M�L�k�Ⲥ������I\n");
                                                    if( me->query_skill("moon_force", 1) < 90 )
                                                        return notify_fail("�A���ݤ�ߪk�ٵL�k�z�R�M�ҥH�L�k�ϥΪ�����I\n");
                                                    if( !me->is_fighting() )
                                                        return notify_fail("�A���b�԰�����M�Q�n��֨ϥX������O�H\n");
                                                    tar = me->query_enemy();
                                                    if( !tar )
                                                        return notify_fail("�A�n���S���ؼЭC�I\n");
                                                    if( me->query("ap") < 125 )
                                                        return notify_fail("�A����O���p���١M�L�k�ϥX�y������z�C\n");

                                                    me->start_busy(1);
                                                    me->receive_damage("ap", 120);
                                                    message_vision(HIW"\n$N����@�X�@���M�H�ŵ깺���X�@�j���u����v�C\n"NOR
                                                                   "��������ͩR�@��M�H�ֱ��L�۪��e�t��V���I�I\n" NOR,me);
                                            me->skill_active("moon_force", (: call_other, __FILE__, "longarc", me, tar :), random(1));
                                                    return 1;
                                                }

                                                if( arg == "shadow" ) // wind adv �s�W: �ݼv�Z
                                                {
                                                    if( me->query("level") < 30 )
                                                        return notify_fail("�A�������٤����M�L�k�ϥδݼv�Z�I\n");
                                                    if( me->query_skill("moon_force", 1) < 70 )
                                                        return notify_fail("�A���ݤ�ߪk�ٵL�k�z�R�M�ҥH�L�k�Ⲥ�ݼv�Z�I\n");
                                                    if( me->query("mp") < 45 )
                                                        return notify_fail("�A���k�O������I\n");
                                                    if( me->query("ap") < 90 )
                                                        return notify_fail("�A����O���䨬�H�ϥX�ݼv�Z�I\n");
                                                    if( me->query_temp("class_wind/on_shadow") )
                                                        return notify_fail("�A�w�g�ϥιL�ݼv�Z�F�M�L�k�A�~��W�j�F�I\n");

                                                    message_vision(BLU"�u��$N���κ����ҽk�M���G�O�ޥX�F�ݤ�ߪk�����ݼv�Z�I�I\n"NOR, me);

                                                    me->add_temp("apply/dodge", ( ar1=(int)(sk*3/2 + random(sk/10)) ) );
                                                    //me->add_temp("apply/armor", ( ar2=(int)(sk/5 + random(sk/40)) ) ); // ���n�[ armor point by linjack

                                                    me->receive_damage("ap", 90);
                                                    me->receive_damage("mp", 45);
                                                    if( me->is_busy() ) me->add_busy(2);
                                                    else me->start_busy(1);
                                                    me->set_temp("class_wind/on_shadow", 1);

                                            me->skill_active("moon_force", (: call_other, __FILE__, "moon_shadow", me, ar1, ar2 :), 600 - random(60));
                                                    return 1;
                                                }
                                                else return notify_fail("�ݤ�ߪk�S���o�إ\\��I\n");

                                            }

                                            void moon_shadow(object me, int ar1, int ar2)
                                            {
                                                if( me->query_temp("apply/dodge") <= ar1 )
                                                    me->set_temp("apply/dodge", 0);
                                                else me->add_temp("apply/dodge", -ar1);

                                                if( me->query_temp("apply/armor") <= ar2 )
                                                    me->set_temp("apply/armor", 0);
                                                else me->add_temp("apply/armor", -ar2);

                                                me->delete_temp("class_wind/on_shadow");
                                                message_vision(HIB"$N�����κ������S�F�X�ӡM��M�O�ݼv�Z���h�F�ĥΡI\n"NOR, me);

                                                return;
                                            }

                                            void arc(object me, object target)
                                            {
                                                object wp;
                                                int t, m, sk_lv;
                                                if(!me || !target ) return;

                                                sk_lv = me->query_skill("moon_force");
                                                wp = target->query_temp("weapon");
                                                t=target->query_skill("dodge")+target->query_dex();
                                                m=me->query_skill("dodge")+me->query_dex();

                                                if( !wp )
                                                {
                                                    message_vision("�u����v�����F�ư�A�Ʀ��@�}���Ϯ����F�C",me);
                                                    return;
                                                }
                                                if( random(t) < random(m) && wp->unequip() ) {
                                                    message_vision(HIC "�u��v�a�@�n�T�A���뼲�o$N�渨�F�⤤���Z���I�I\n" NOR ,target);
                                                    target->start_busy(1);
                                                    call_out("rewield", sk_lv*5/4, target, wp);
                                                } else {
                                                    message_vision(CYN "�u��v�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR,target);
                                                    me->add_busy(1);
                                                }
                                                me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                                                me->improve_skill("moon_force",1+random(5+me->query("level"))+me->query_int()/4 );
                                                return;
                                            }

                                            void rewield(object target,object wp)
                                            {
                                                if( !target || userp(target) || !wp ) return;
                                                if( environment(wp) != target ) return;
                                                if( wp->query("equipped") ) return;
                                                message_vision("������$N���ĤO����A$N�˳ư_$n�C\n",target,wp);
                                                wp->wield();
                                            }

                                            void longarc(object me, object *tar)
                                            {
                                                object weapon;
                                                int x=0, q, tar_d, me_d;

                                                for(q=0;q<sizeof(tar);q++)
                                                {
                                                    if(!tar[q]) continue;
                                                    if( !(weapon=tar[q]->query_temp("weapon")) ) continue;
                                                    if( 20+random((tar_d=tar[q]->query_skill("dodge")+tar[q]->query_dex())*7/12) < random(me_d=me->query_skill("dodge")+me->query_dex())
                                                            && weapon->unequip() ) {
                                                        message_vision(HIC "�u��v�a�@�n�T�A�@�D���뼲�o$N�渨�F�⤤���Z���I�I\n" NOR , tar[q]);
                                                        tar[q]->start_busy(1);
                                                        //			call_out( (: rewield, tar[q], weapon :), me->query_skill("moon_force"));
                                                    } else {
                                                        message_vision(CYN "�u��v�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR, tar[q]);
                                                        me->add_busy(1);
                                                    }
                                                    x++;
                                                }
                                                if( !x ) {
                                                    message_vision("�u����v�����F�ư�A�Ʀ��@�}���Ϯ����F�C",me);
                                                    return;
                                                }
                                                me->improve_skill("force", 1 + random(me->query("level")+x+5) + me->query_int()/5 + random(me->query_int()/10));
                                                me->improve_skill("moon_force", 1 + random(me->query("level")+x+5) + me->query_int()/5 + random(me->query_int()/10) );
                                                return;
                                            }

                                            void delay(object me)
                                            {
                                                int sk_level,lv,i;

                                                sk_level = me->query_skill("moon_force");
                                                lv = me->query("level");
                                                i = me->query_int();

                                                if( !me ) return;

                                                if( me->query_skill_mapped("force")!="moon_force" ) return;

                                                if( me->query("ap") < 13 || me->query("hp") < 13 )
                                                {
                                                    message_vision(HIR"$N�߯��p�@�D�����L�A£�M����F�B�\\�C\n"NOR,me);
                                                    me->delete_temp("is_busy/moon_force");
                                                    me->map_skill("force");
                                                    return;
                                                }
                                                else if ( sk_level < 50 )
                                                {
                                                    me->receive_damage("ap",8);
                                                    me->receive_damage("hp",5);
                                                }
                                                else if ( sk_level > 49 )
                                                {
                                                    me->receive_damage("ap",12);
                                                    me->receive_damage("hp",7);
                                                }
                                                me->improve_skill("force",1 + random(5+lv/2) + (sk_level/5) + (i/3) );
                                                me->improve_skill("moon_force",1 + random(5+lv/2) + (sk_level*3/8) + (i/3) );
                                            me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3);
                                            }

                                            int valid_learn(object me)
                                            {
                                                return 1;
                                            }

                                            int practice_skill(object me)
                                            {
                                                return 1;
                                            }

                                            void skill_improved(object me) // �`�N, �@��skill��W�[���ݩ��`�M�H 5 ���W��
                                            {
                                                int b,c;
                                                b = me->query_skill("moon_force",1);
                                                c = me->query("skill/moon_force"); //luky

                                                if( b % 20==19 && b > c)
                                                {
                                                    if(random(2))
                                                    {
                                                        tell_object(me, HIR "�A���ʧ@�ѩ�⮩�ݤ�ߪk���D�ӧ�[���դF�C\n" NOR);
                                                        me->add("addition/dex", 1);
                                                    }
                                                    else
                                                    {
                                                        tell_object(me, HIR "�A�����ѩ�⮩�ݤ�ߪk���D�ӼW�j�F�C\n" NOR);
                                                        me->add("addition/con", 1);
                                                    }
                                                    me->set("skill/moon_force", b);
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
