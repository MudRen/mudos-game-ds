#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

int HelpMoxibustion()
{

    write(@HELP
      ���ްw�b�ϥΤ�k:       exert moxibustion <�\��> on <�Y�H>

          �D�԰��\��G
          �m����Z�nrekee       ���Ӥ��l�I��(AP)�Ӧ^�ХͩR�I��(HP)
          �m����Z�nregin       �����]�k�I��(MP)�Ӧ^�Ф��l�I��(AP)
    �m�����Z�nresen       ���Ӥ��l�I��(AP)�Ӧ^���]�k�I��(MP)
    �m���@�Z�nadvkee      ���Ӥ��l�I��(AP)�ӫ���ʦ^�ХͩR�I��(HP)
    �m�
}
�ѳZ�nsky         �����]�k�I��(MP)�Ӧ^�Х��檱�a�����l�I��(AP),�ͩR�I��(HP)
�m¡���Z�nheal        �����]�k�I��(MP)�Ӫv¡���˳B
�m���߳Z�naddint      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϴ��z(INT)����
�m�T�J�Z�naddcon      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�����(CON)����
�m�h�ƳZ�nadddex      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϱӱ�(DEX)����
�m�Ӷ��Z�naddstr      ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)�ϤO�q(STR)����
�m�����@��Z�nghost   ���Ӥ��l�I��(AP)�A�]�k�I��(MP)�A�ͩR�I��(HP)�Ϫ��z�����O�M���z���m�O����
�԰��\��G
�m���d���_�Z�nattack  ���Ӥj�q���l�I��(AP)�A�]�k�I��(MP)��ĤH���n�޵o�X
�P�R���@��
HELP);
return 1;
       }

       void ShowMessage(object me, object target, string msg)
       {
           message_vision( msg, me, target);
       }

       void MoxibustionFail(object me, object target, string msg)
       {
           if( target != me )
           {
               msg += HIB "$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A��$n"HIB"�P��@�}���֡E\n" NOR;
           }
           else
           {
               msg += HIB "$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A�ۤv�P��@�}���֡E\n" NOR;
           }
           ShowMessage(me, target, msg);
       }

       void ShowDamage(object me, object target,int damage)
       {
           if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
               tell_object(me,HIY"("+damage+")"NOR);
           if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
               tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
           if(wizardp(me) && me->query("env/debug"))
               tell_object(me, HIR"  ("+damage+")\n"NOR);
       }

       void SkillImporving(object me, int Bonus)
       {
           me -> improve_skill("moxibustion", 1+Bonus);
           me -> improve_skill("acupuncture_cognition", random(Bonus));
       }

       void rekee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"���y�ѻa�ղ@�L���A���ӫ�_�F���֦��C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("hp", effect);
       }

       void regin(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"���ê��������G���ұ���A�v��í�w�F�U�ӡC\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*4/5);
           target -> receive_heal("ap", effect);
       }

       void resen(object me, object target, int effect, string msg)
       {
           msg += HIM"�믫����������$N"HIM"�A�y�ɮe���صo�A�믫�����C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*4/5);
           target -> receive_heal("mp", effect);
       }

       void advkee(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"�a�ժ��y��A�]����𪺹B��A��������F�_�ӡC\n"NOR ;
           target -> apply_condition("advkee", effect*me->query_tec());
           target -> set_temp("advkee", effect);
       }

       void sky(object me, object target, int effect, string msg)
       {
           object *s_target = all_inventory(environment(me));
           int x,y = sizeof(s_target);
           for(x=0;x<y;x++)
           {
               if( !userp(s_target[x]) || !living(s_target[x]))
                   continue;
               if( s_target[x] == me )
                   continue;
               if( random(me->query_skill("acupuncture_cognition")) > 40 )
               {
                   message_vision("$N�Pı��@�Ѯ�q�u�R���ޡv�Ρu�Үc�ޡv�ĥX�A�y�ɦ�𪺹B��Τ�����í�w�F���֡C", s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_heal("hp", effect);
                   s_target[x] -> receive_heal("ap", effect);
               }
               else
               {
                   message_vision(HIB"$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR, me, s_target[x]);
                   me -> receive_damage("mp", effect*19*y/20);
                   s_target[x] -> receive_damage("mp", random(20));
                   s_target[x] -> receive_damage("ap", random(20));
               }
           }
           SkillImporving(me, x*(me->query_int()/8));
       }

       void heal(object me, object target, int effect, string msg)
       {
           msg += HIC"$N"HIC"���W���ˤf�A�庥�����F�A�ˤf�]�H�w�C�����t�׺C�C���ǦX�_�ӡC\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("mp", effect*5);
           target -> receive_curing("all", effect);
       }

       void addAttribute(object me, object target, int effect, string msg, int x)
       {
           string Attr;
           switch( x )
           {
           case 0:
               msg += HIY"$N"HIY"�����v�]�����ܱo���j�j���A�٦תȵ��ʾw����I�I\n"NOR ;
               Attr = "str";
               break;
           case 1:
               msg += HIG"$N"HIG"������Pı���F�ǳ\�����ܡA���G�j���F���֡C\n"NOR ;
               Attr = "con";
               break;
           case 2:
               msg += HIW+BLK"$N"HIW+BLK"���Mı�o��ӤH�Ií�F�U�ӡA������������G��M���F�@�ǡC\n"NOR ;
               Attr = "int";
               break;
           default:
               msg += HIW"$N"HIW"���Mı�o���骺�I���P�����F���֡A���ػ����ƪ��Pı�C\n"NOR ;
               Attr = "dex";
               break;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*15);
           me -> receive_damage("mp", effect*15);
           target -> start_busy(effect/5);
           target -> set_temp("add"+Attr, effect);
           target -> apply_condition("add"+Attr, effect*me->query_tec());
           target -> add_temp("apply/"+Attr, effect);
           target -> add_temp("e_"+Attr, 1);
       }

       void ghost(object me, object target, int effect, string msg)
       {
           msg += CYN"$N"CYN"����l���M�W�j�F�ǳ\�A���~�ɪ������]�h�F���֩�ܯ�O�C\n"NOR ;
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", effect*18);
           me -> receive_damage("mp", effect*18);
           target -> set_temp("ghost", effect);
           target -> start_busy(effect/5);
           target -> apply_condition("ghost", effect*me->query_tec());
           target -> add_temp("apply/damage", effect);
           target -> add_temp("apply/armor", effect);
           target -> add_temp("d_a_up",1);
       }

       void attack(object me, object target, int damage, string msg)
       {
           int BusyTime, HitRate, DodgeRate;


           damage = (me->query_damage()) * (me->query_tec()/2);
           damage -= target->query_armor();
           damage += random((me->query_int())/25 * me->query_skill("moxibustion"));
           damage = COMBAT_D->Merits_damage(me, target, damage, "tec");
           if( damage < 0 )
               damage = 0;

           HitRate = (me->query_skill("acupuncture_cognition"))*2 + me->query_dex();
           DodgeRate = (target->query_dex())/2 + target->query_skill("acupuncture_cognition");

           if( HitRate > DodgeRate )
           {
               msg += HIB"���W�Q�G�ӭn�`���ަ쳣�Q�H�������I�J�A�y�ɵL�O�۬[�A�餺��l�z���A��Ŧ���Ƴ������Y�����ˮ`�C"NOR ;
               BusyTime = me->query_tec()/3;
               target -> start_busy(BusyTime);
           }
           else
           {
               msg += CYN"���F���{�L�b�ƴH��A�����K�٬O����p�p���i�ΡC"NOR ;
               damage /= 4;
           }
           ShowMessage(me, target, msg);
           me -> receive_damage("ap", 150);
           me -> receive_damage("mp", 250);
           me -> start_busy(random(2));
           target -> receive_damage("hp", damage);
           target -> receive_damage("ap", damage*4);
           ShowDamage(me, target, damage);
           COMBAT_D->report_status(target);
       }

       int cast_skill(object me, object target, string arg)
       {
           object weapon = me->query_temp("weapon"), *s_target;
           string msg;
           int HitRate, DodgeRate, effect, sk1, sk2, Bonus, x;
           if( !target )
               target = me;
           sk1 = me->query_skill("acupuncture_cognition");
           sk2 = me->query_skill("moxibustion");

           if( arg == "?" || arg == "help" )
               return HelpMoxibustion();

           if( !weapon )
               return notify_fail("�A��W�S�w�O����I�i���ްw�b���C\n");
           if( weapon->query("skill_type")!="needle" )
               return notify_fail("�A��W�S�w�O����I�i���ްw�b���C\n");
           if( !target )
               return notify_fail("�A�S���i�H�I�i���ؼСC\n");
           if( me->query("class2") )
           {
               if( target != me && me->query("class2") != "skyowl_med" )
                   return notify_fail("�A��O�H���W���޹D��m���x���٤����m�A�����L�H�I�i���ۡC\n");
           }
           if( me->is_busy() )
               return notify_fail("�A�{�b���b���A�L�k�ϥΪ��ްw�b�I\n");

           switch( arg )
           {
           case "rekee":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 5 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 5 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"����Z"NOR"�n�E\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"�èS�����ˡA���G���ݰw�b�E\n");

               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"����W���ߪ��u�R���ޡv�C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   rekee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "regin":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 5 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 5 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIG"����Z"NOR"�n�E\n");
               if( target->query("ap") >= target->query("max_ap") )
                   return notify_fail(target->query("name")+"�����l�R�K�A���G���ݰw�b�E\n");

               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIG"����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"��x�W�u�Үc�ޡv�C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   regin(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "resen":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 5 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 5 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"NOR+MAG"�����Z"NOR"�n�E\n");
               if( target->query("mp") >= target->query("max_mp") )
                   return notify_fail(target->query("name")+"���믫���A���G���ݰw�b�E\n");

               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"NOR+MAG"�����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"����W���ߪ��u�����ޡv�C\n"NOR ;
               if( random(sk1) > 15 )
               {
                   effect = sk2;
                   me -> start_busy(1);
                   Bonus = me->query_int()/8;
                   resen(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "advkee":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 10 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 15 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"���@�Z"NOR"�n�E\n");
               if( target->query("hp") >= target->query("max_hp") )
                   return notify_fail(target->query("name")+"�èS�����ˡA���G���ݰw�b�E\n");
               if( target->query_temp("advkee") )
                   return notify_fail(target->query("name")+"���餺�w�g���@�ѷx�x��y���b�w�w���y�ʵۡC\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"���@�Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"��Ŧ���᪺�u���D�ޡv�C\n"NOR ;
               if( random(sk1) > 35 )
               {
                   effect = sk2/2;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   advkee(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "sky":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 15 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 30 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIR"�}�ѳZ"NOR"�n�E\n");
               message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIR"�}�ѳZ"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J����Ҧ��H���u�R���ޡv�Ρu�Үc�ޡv�C\n"NOR, me, target);
               if( random(sk1) > 45 )
               {
                   effect = sk2;
                   me -> start_busy(2);
                   sky(me, target, effect, msg);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "heal":
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 20 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 40 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"¡���Z"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"¡���Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"���W���ˤf�|�P�C\n"NOR ;
               if( random(sk1) > 45 )
               {
                   effect = sk2/5;
                   me -> start_busy(2);
                   Bonus = me->query_int()/4;
                   heal(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addint":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 30 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 50 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIW+BLK"���߳Z"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"BLK"���߳Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"�Y�����u�ʷ|�ޡv�C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 2);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addcon":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 30 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 50 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIG"�T�J�Z"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIG"�T�J�Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"����W���U�J�T�����C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 1);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "adddex":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 30 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 50 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIW"�h�ƳZ"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-�h�ƳZ�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"�L�W���u�����ޡv�C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 3);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "addstr":
               if( target->query_temp("e_con") || target->query_temp("e_int") || target->query_temp("e_str") || target->query_temp("e_dex") )
                   return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 30 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 50 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIY"�Ӷ��Z"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIY"�Ӷ��Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"�I�����u���j�ޡv�C\n"NOR ;
               if( random(sk1) > 55 )
               {
                   effect = sk2/8;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   addAttribute(me, target, effect, msg, 0);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "ghost":
               if( target->query_temp("d_a_up") )
                   return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
               if( me->is_fighting() )
                   return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
               if( me->query("level") < 30 )
                   return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
               if( sk2 < 55 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HBWHT+BLK"�����@��Z"NOR"�n�E\n");
               msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HBWHT+BLK"�����@��Z"NOR"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"���ФU�u�����ޡv�B�V�U�u�Ѭ�ޡv�B���Y�u�Ӥ��ޡv���Q�G�B�޹D�W�C\n"NOR ;
               if( random(sk1) > 65 )
               {
                   effect = sk2/4;
                   me -> start_busy(2);
                   Bonus = me->query_int();
                   ghost(me, target, effect, msg);
                   SkillImporving(me, Bonus);
               }
               else
               {
                   MoxibustionFail(me, target, msg);
               }
               break;
           case "attack":
               if( target == me )
                   return notify_fail("�� suicide ���O�|�����:P�C\n");
               if( sk2 < 70 )
                   return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIR"���d���_�Z"NOR"�n�E\n");
               if(!me->can_fight(target))
                   return 0;

               if(!me->is_fighting(target))
                   me->kill_ob(target);
               if(!target->is_fighting(me))
                   target->kill_ob(me);

               msg+= HIC"$N"HIC"���X�a�͸U�����˽��j���Ѧa�`���u�z�A����d�Y�C" ;
               msg+=    "\n    �H�Y�@�}�g�r���H���$N"HIC"�⤤���w�W«�X�A�V$n"HIC"�Q�G�R�����t�ӥh�I�I\n" ;
               Bonus = me->query_int()/2;
               attack(me, target, 1, msg);
               SkillImporving(me, Bonus);

               break;
           }
           return 1;
       }

       int valid_learn(object me)
       {
           return 1;
       }
       int practice_skill(object me)
       {
           return 1;
       }
       int improve_limite(object ob)
       {
           return 100;
       }

