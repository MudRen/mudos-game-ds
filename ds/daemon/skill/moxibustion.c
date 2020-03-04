#include <ansi2.h>
inherit SKILL;
inherit SSERVER;


void ShowMessage(object me, object target, string msg)
{
    message_vision( msg, me, target);
}

void MoxibustionFail(object me, object target, string msg)
{
    if( target != me )
        msg += HIB "$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A��$n"HIB"�P��@�}���֡E\n" NOR;
    else
        msg += HIB "$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A�ۤv�P��@�}���֡E\n" NOR;

    ShowMessage(me, target, msg);
    me->start_busy(2);
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
    me -> improve_skill("acupuncture-cognition", random(Bonus));
}

void rekee(object me, object target, int effect, string msg)
{
    tell_object(target, CYN"�A�y�ѻa�ղ@�L���A���ܦ���_�F���֦��C\n" NOR);
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*4/5);
    target -> receive_heal("hp", effect);
}

void regin(object me, object target, int effect, string msg)
{
    tell_object(target, HIC"�A���ê��������G���ұ���A�v��í�w�F�U�ӡC\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("mp", effect*4/5);
    target -> receive_heal("ap", effect);
}

void resen(object me, object target, int effect, string msg)
{
    tell_object(target, HIM"�A�쥻�믫���������A�p���y�ɮe���صo�A�믫�����C\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("hp", effect*4/5);
    target -> receive_heal("mp", effect);
}

void advkee(object me, object target, int effect, string msg)
{
    tell_object(target, "�A�a�ժ��y��A�]����𪺹B��A��������F�_�ӡC\n"NOR) ;
    me -> receive_damage("mp", effect*4);
    me -> receive_damage("ap", effect*4);

    target -> apply_condition("advkee", 10*me->query_tec());
    target -> set_temp("advkee", effect);
}

void sky(object me, object target, int effect, string msg)
{
    int ppl_cnt = 0;
    object *s_target = all_inventory(environment(me));
    int x,y = sizeof(s_target);

    // �̦h8�Ӫ��a
    for(x=0;x<y && ppl_cnt < 8 ;x++)
    {
        if( !userp(s_target[x]) || !living(s_target[x]))
            continue;
        if( s_target[x] == me )
            continue;
        if( s_target[x]->is_fighting() )
            continue;   //  �԰��������a����v��

        ppl_cnt += 1;   // ��ڱ�����v�������a��
        if( random(me->query_skill("acupuncture-cognition")) > 40 )
        {
            message_vision("$N�Pı��@�Ѯ�q�u�R���ޡv�Ρu�Үc�ޡv�ĥX�A�y�ɦ�𪺹B��Τ�����í�w�F���֡C\n", s_target[x]);
            s_target[x] -> receive_heal("hp", effect );
            s_target[x] -> receive_heal("ap", effect );
        }
        else
        {
            message_vision(HIB"$N"HIB"�@�Ӥ��ߡA�w�N�����F�ަ�A��$n�P��@�}���֡E\n"NOR, me, s_target[x]);
            s_target[x] -> receive_damage("mp", 10 + random(20));
            s_target[x] -> receive_damage("ap", 10 + random(20));
        }
    }
    // �@����n��Omp
    me -> receive_damage("hp", effect*ppl_cnt);
    me -> receive_damage("ap", effect*ppl_cnt);
    me -> receive_damage("mp", effect*ppl_cnt);
    SkillImporving(me, x*(me->query_int()/8));
}

void heal(object me, object target, int effect, string msg)
{
    tell_object(target, HIC"�A�ˤf�W���庥�����F�A�ˤf�C�C�a�ǦX�_�ӡC\n"NOR) ;
    ShowMessage(me, target, msg);
    me -> receive_damage("mp", effect*5);
    me -> receive_damage("hp", effect*5);
    target -> receive_curing("all", effect);
}

void addAttribute(object me, object target, int effect, string msg, string type)
{
    string Attr;
    switch( type )
    {
    case "addstr":
        msg += HIY"$n"HIY"�������ܱo���j�j���A�٦תȵ��ʾw����I�I\n"NOR ;
        Attr = "str";
        break;
    case "addcon":
        msg += HIG"$n"HIG"����観�F��۪��ﵽ�A��ӤH�j�����֡C\n"NOR ;
        Attr = "con";
        break;
    case "addint":
        msg += HIC"$n"HIC"������������֦a�B��A�F�P��u�����C\n"NOR ;
        Attr = "int";
        break;
    case "adddex":
        msg += HIW"$n"HIW"ı�o�}�B�ܪ��D�`���֡A���_���Ӧ������ƪ��Pı�A�D�`�F�ӡC\n"NOR ;
        Attr = "dex";
        break;
    }
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*15);
    me -> receive_damage("mp", effect*15);

    target -> start_busy(effect/5);
    target -> set_temp("add"+Attr, effect);

    target -> add_temp("apply/"+Attr, effect);
    target -> apply_condition("add"+Attr, 10*me->query_tec() );
}

void ghost(object me, object target, int effect, string msg)
{
    tell_object(target, CYN"$N"CYN"���Ȥ�l�W�j�\\�h�A��~�ɪ������]�h�F���֩�ܯ�O�C\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*10);
    me -> receive_damage("mp", effect*10);
    me -> receive_damage("hp", effect*10);

    target -> start_busy(effect/5);
    target -> set_temp("ghost", effect);
    target -> apply_condition("ghost", 10*me->query_tec());

    // effect �̦h��100/4 = 25�I
    target -> add_temp("apply/damage", effect);
    target -> add_temp("apply/armor", effect);
}

int exert(object me, object target, string arg)
{
    object weapon = me->query_temp("weapon");
    string msg = "";
    int effect, sk1, sk2, Bonus;

    if( !target ) return notify_fail("�п�w�@�ӥؼСC\n");

    sk1 = me->query_skill("acupuncture-cognition");
    sk2 = me->query_skill("moxibustion");

    if( arg == "?" || arg == "help" )
        return notify_fail("�аѦ�help moxibustion �ޯ໡�����C");

    if( !weapon )
        return notify_fail("�A��W�S�w�O����I�i���ްw�b���C\n");
    if( weapon->query("skill_type") != "needle" )
        return notify_fail("�A��W�S�w�O����I�i���ްw�b���C\n");
    if( !target )
        return notify_fail("�A�S���i�H�I�i���ؼСC\n");
    /*
        if( me->query("class2") )
        {
            if( target != me && me->query("class2") != "skyowl_med" )
                return notify_fail("�A��O�H���W���޹D��m���x���٤����m�A�����L�H�I�i���ۡC\n");
        }
    */
    if( me->is_busy() )
        return notify_fail("�A�{�b���b���A�L�k�ϥΪ��ްw�b�I\n");

    switch( arg )
    {
        ///////////////////////////////////////////////////////////////////////////////////
    case "rekee":
    case "regin":
    case "resen":
        if( me->is_fighting() )
            return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
        if( me->query("level") < 5 )
            return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
        if( sk2 < 5 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥγo�ӥ\\��E\n");

        effect = sk2;

        if(arg == "rekee") {
            if( me->query("ap") < effect )
                return notify_fail("�A�����l�����C\n");
            if( target->query("hp") >= target->query("max_hp") )
                return notify_fail(target->query("name")+"�èS�����ˡA���G���ݰw�b�E\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"����Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"����W���ߪ��u�R���ޡv�C\n"NOR, me, target);
            else
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"����Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J�ۨ����ߪ��u�R���ޡv�C\n"NOR, me);
        }

        if(arg == "regin") {
            if( me->query("mp") < effect )
                return notify_fail("�A���]�O�����C\n");
            if( target->query("ap") >= target->query("max_ap") )
                return notify_fail(target->query("name")+"�����l�R�K�A���G���ݰw�b�E\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIG"����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"��x�W�u�Үc�ޡv�C\n"NOR , me, target);
            else
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIG"����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J�ۨ���x�W�u�Үc�ޡv�C\n"NOR , me);
        }

        if(arg == "resen") {
            if( me->query("hp") < effect )
                return notify_fail("�A���ͩR�����C\n");

            if( target->query("mp") >= target->query("max_mp") )
                return notify_fail(target->query("name")+"���믫���A���G���ݰw�b�E\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"NOR+MAG"�����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"����W���ߪ��u�����ޡv�C\n"NOR, me, target);
            else
                message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"NOR+MAG"�����Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J�ۨ����ߪ��u�����ޡv�C\n"NOR, me);
        }

        if( random(sk1) > 15 ) {
            me -> start_busy(1);
            Bonus = me->query_int()/8;
            if(arg=="rekee")
                rekee(me, target, effect, msg);
            else if(arg=="regin")
                regin(me, target, effect, msg);
            else if(arg=="resen")
                resen(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else    // ����
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "advkee":
        if( me->is_fighting() )
            return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
        if( me->query("level") < 10 )
            return notify_fail("�A���⪺���Ť���10�šA����զ۴��L�H�w���E\n");
        if( sk2 < 15 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"���@�Z"NOR"�n�E\n");

        // �ϥ�condition �ӧP�_
        if( target->query_condition("advkee") || target->query_temp("advkee") )
            return notify_fail(target->query("name")+"���餺�w�g���@�ѷx�x��y���b�w�w���y�ʵۡC\n");

        effect = sk2/2;
        if(me->query("ap") < effect*4 )
            return notify_fail("�A�����l�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("mp") < effect*4 )
            return notify_fail("�A���]�O�����A�L�k�ϥγo�ӥ\\��C\n");

        if(me!=target)
            message_vision( HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"���@�Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"�ݵĳB���u���D�ޡv�C\n"NOR, me, target);
        else
            message_vision( HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"���@�Z"HIW"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J�ۨ��ݵĳB���u���D�ޡv�C\n"NOR, me);
        if( random(sk1) > 35 )
        {
            me -> start_busy(2);
            Bonus = me->query_int()/4;
            advkee(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else
            MoxibustionFail(me, target, msg);

        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "sky":
        if( me->is_fighting() )
            return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
        if( me->query("level") < 15 )
            return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
        if( sk2 < 30 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIR"�}�ѳZ"NOR"�n�E\n");

        effect = sk2;

        if(me->query("hp") < effect*8 )
            return notify_fail("�A���ͩR�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("ap") < effect*8 )
            return notify_fail("�A�����l�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("mp") < effect*8 )
            return notify_fail("�A���]�O�����A�L�k�ϥγo�ӥ\\��C\n");

        message_vision(HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIR"�}�ѳZ"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~�A�@�@��J���ǩҦ��H���u�R���ޡv�Ρu�Үc�ޡv�C\n"NOR, me);
        if( random(sk1) > 45 )
        {
            me -> start_busy(2);
            sky(me, target, effect, msg);
        }
        else    // ����
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "heal":
        if( me->is_fighting() )
            return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");
        if( me->query("level") < 20 )
            return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
        if( sk2 < 40 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HIC"¡���Z"NOR"�n�E\n");

        effect = sk2/5;

        if(me->query("mp") < effect*5 )
            return notify_fail("�A���]�O�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("hp") < effect*5 )
            return notify_fail("�A���ͩR�����A�L�k�ϥγo�ӥ\\��C\n");

        msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"¡���Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"���W���ˤf�|�P�C\n"NOR ;

        if( random(sk1) > 45 )
        {
            me -> start_busy(2);
            Bonus = me->query_int()/4;
            heal(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "addstr":
    case "addcon":
    case "addint":
    case "adddex":
        // �����ϥ� condition �ӧP�_
        if( target->query_condition("addcon")
                || target->query_condition("addint")
                || target->query_condition("addstr")
                || target->query_condition("adddex")
                || target->query_temp("addstr")
                || target->query_temp("addint")
                || target->query_temp("adddex")
                || target->query_temp("addcon") )
            return notify_fail(target->query("name")+"������ȮɵL�k�A��������W���j�ƤF�C\n");

        if( me->is_fighting() )
            return notify_fail("�A�����۾԰��A�S���Űw���C\n");
        if( me->query("level") < 30 )
            return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
        if( sk2 < 50 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥγo�ӥ\\��E\n");

        effect = sk2/10;        // �C�Q�Ť@�I

        if(me->query("hp") < effect*15 )
            return notify_fail("�A���ͩR�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("ap") < effect*15 )
            return notify_fail("�A�����l�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("mp") < effect*15 )
            return notify_fail("�A���]�O�����A�L�k�ϥγo�ӥ\\��C\n");

        if( arg == "addstr")
            msg = HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIY"�Ӷ��Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"�I�����u���j�ޡv�C\n"NOR ;
        else if( arg == "addint")
            msg = HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HBK"���߳Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"�Y�����u�ʷ|�ޡv�C\n"NOR ;
        else if( arg == "addcon")
            msg = HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIG"�T�J�Z"HIW"�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"����W���U�J�T�B�C\n"NOR ;
        else if( arg == "adddex")
            msg = HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HIC"�h�ƳZ�A�⤤"+weapon->name()+HIW"�Ʀ��I�I�H�~��J$n"HIW"�L�W���u�����ޡv�C\n"NOR ;

        if( random(sk1) > 55 ) {
            me -> start_busy(2);
            Bonus = me->query_int();
            addAttribute(me, target, effect, msg, arg);
            SkillImporving(me, Bonus);
        }  else // ����
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "ghost":
        // �Hcondition �ӧP�_
        if( target->query_condition("ghost")  || target->query_temp("ghost") )
            return notify_fail(target->query("name")+"������w�g�L�k�A��������W���j�ƤF�C\n");
        if( me->is_fighting() )
            return notify_fail("�������A�S���ɶ���"+target->query("name")+"�w�b�C\n");

        // �̦h100/4 = 25�I�����O�Ψ��m�O
        effect = sk2/4;

        if(me->query("hp") < effect*10 )
            return notify_fail("�A���ͩR�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("mp") < effect*10 )
            return notify_fail("�A���]�O�����A�L�k�ϥγo�ӥ\\��C\n");
        if(me->query("ap") < effect*10 )
            return notify_fail("�A�����l�����A�L�k�ϥγo�ӥ\\��C\n");

        //        if( me->query("level") < 30 )
        //            return notify_fail("�A���g�礣���A����զ۴��L�H�w���E\n");
        if( sk2 < 55 )
            return notify_fail("�A�瘟�ްw�b�������m�A�L�k�ϥX�m"HBWHT+BLK"�����@��Z"NOR"�n�E\n");
        msg+= HIW"$N"HIW"�������u�۵ۥj�Ѫ��~�Ǹֺq-"HBWHT+BLK"�����@��Z"NOR"�A�⤤"+weapon->name()+HIW"�]�Ƭ��I�I�H�~��J$n"HIW"���ФU�u�����ޡv�B�V�U�u�Ѭ�ޡv�B���Y�u�Ӥ��ޡv���Q�G�B�޹D�W�C\n"NOR ;
        if( random(sk1) > 65 )
        {
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
        ///////////////////////////////////////////////////////////////////////////////////
        // skyowl �S�������������ޯ�
        // tmr 2007/01/05
        /*
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
        */
        ///////////////////////////////////////////////////////////////////////////////////
    default:
        return notify_fail("���ްw�b�S���o�ӥΪk�A�аѦ�help moxibustion�C\n");
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
int improve_limite(object me)
{
    return me->query_int() + 60;
}


