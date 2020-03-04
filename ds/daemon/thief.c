// �{�N���|¾�~�H���֤� (�p�����|-Thief)
// �s�g��: Luky 1999.9.5
// Last update by Tmr 2006/11/10
//
#include <weapon.h>
#include <combat.h>
#include <door.h>
#include <box.h>
#include <ansi.h>

mapping default_dirs = ([
                            "north":		"�_",
                            "south":		"�n",
                            "east":			"�F",
                            "west":			"��",
                            "northup":		"�_��",
                            "southup":		"�n��",
                            "eastup":		"�F��",
                            "westup":		"����",
                            "northdown":		"�_��",
                            "southdown":		"�n��",
                            "eastdown":		"�F��",
                            "westdown":		"����",
                            "northeast":		"�F�_",
                            "northwest":		"��_",
                            "southeast":		"�F�n",
                            "southwest":		"��n",
                            "up":			"�W",
                            "down":			"�U",
                            "enter":		"��",
                            "out":			"�~",
                        ]);

void create()
{
    seteuid(getuid());
}

void show_damage(object me,object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
}

int do_backstab(object me,string arg)
{
    object target,weapon;
    int sk,cost;

    if(!me)
        return 0;
    if(!arg)
        return notify_fail("�A�n����֡S\n");
    sk=me->query_skill("backstab");
    cost=5+me->query("level");
    if(!weapon=me->query_temp("weapon"))
        return notify_fail("�A�S�����Z���p��I��?\n");
    if(!weapon->can_stab() )
        return notify_fail(weapon->name()+"�ä��A�X�ΨӭI��C\n");
    if(me->is_busy() || me->is_block())
        return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
    if( me->is_fighting() )
        return notify_fail("�A���b�԰��S�ŭI��C\n");
    if(sk<1)
        return notify_fail("�A���٨S�ǹL�I��C\n");
    if((int)me->query("ap")< cost )
        return notify_fail("�A���믫��O���ΡA�L�k�I��C\n");
    target = present(arg, environment(me));
    if(!target)
        return notify_fail("�A�n����֡S\n");
    if(!living(target) )
        return notify_fail("�ݲM���@�I, ���ä��O����.\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if(target->visible(me))
        return notify_fail("��西�`���ۧA�A�A�S�����|�I��C\n");
    if(me->query("evil")<-700)
        return notify_fail("�A�ӵ��}�F�A���ԤߤU��C\n");

    if(random(target->query_dex()/4+target->query_skill("perception")/3)
            > random(sk/2+me->query_dex()/3+me->query_temp("hide")*4)
      )
    {
        me->delete_temp("hide");
        message_vision(HIW"$N"HIW"�Q�q�I�᰽ŧ$n"HIW"�A���O�o�Q$n"HIW"�o�{�F!!\n"NOR,me,target);
        me->improve_skill("backstab",2+random(2+me->query_int()/10));
        target->kill_ob(me);
        if(me->query_skill("free_action")>49)
            me->add_busy(1); //�ޯ� free_action �ΨӴ�֦��L�ɶ�
        else
            me->add_busy(2);
        return 1;
    }
    tell_object(me,HIY"�A��"+weapon->name()+HIY"�A�p���l�l�a�V"+target->name()+HIY"���I�ᱵ��...\n"NOR);
    //	me->receive_damage("mp",cost/2);
    me->receive_damage("ap",cost);
    me->add_busy(1);
    call_out("bs",2,me,target);
    return 1;
}


void bs(object me,object target)
{
    int damage,exp,sk,c;
    int stillhunt_sk;
    object weapon;
    string msg;
    if(!me || !target)
        return;
    if(!weapon=me->query_temp("weapon"))
    {
        tell_object(me,"�A�{�ɨ��U�Z���A���F�o������ʡC\n");
        return;
    }
    else if(!weapon->can_stab())
    {
        tell_object(me,"�A���p�߮����F�Z���A���F�o������ʡC\n");
        return;
    }

    if(environment(me) != environment(target) || !me->visible(target))
    {
        tell_object(me,"�A���F�o������ʡC\n");
        return;
    }
    me->delete_temp("hide");
    sk=me->query_skill("backstab");
    c = target->query_armor();
    damage = me->query_damage()*3+sk;
    if(weapon->query("backstab_bonus")!=0)
        damage = damage*(100+weapon->query("backstab_bonus"))/100;
    
    damage = damage/2+random(damage/2);
    damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
    damage = damage-c/5-random(c/2);
    if(damage < 20)
        damage = 20+random(10);
 //   damage += damage*(me->query("evil")/700);
    exp = damage/2+random(damage/4);
    
    if(damage>200)
        msg=RED"$n"RED"�G�s�@�n!! ���W�ٵo�X�@�n�y��!!�z���G�O���Y�H�����n���C"NOR;
    else if(damage > 130)
        msg=HIR"$n"HIR"�@�n�s�z!! �ˤf�`�i�����C"NOR;
    else if(damage > 60)
        msg=HIM"$n"HIM"�j�s�@�n!! �A���q�F�@�a�C"NOR;
    else
        msg=HIM"�h��$n"HIM"�z�z�j�s�A�X�G�֭n�����L�h�C"NOR;
    
    me->kill_ob(target);
    target->kill_ob(me);
    message_vision(HIW"\n$N"HIW"��M�X�{�b$n"HIW"������A�|�_"+weapon->name()+HIW"�ΤO����$n"HIW"�I�W��F�U�h!!"NOR,me,target);

    show_damage(me,target,damage);
    target->receive_damage("hp",damage,me);
    message_vision("\n"+msg+"\n",me,target);
    COMBAT_D->report_status(target);

    /* �i���I�� (stillhunt)
     * tmr 2006/11/10
     */
    stillhunt_sk = me->query_skill("stillhunt");
    if( stillhunt_sk >= 1 )
    {
        message_vision(HIY"$N"HIY"��ŧ���\\�A�X��$n"HIY"���ߨ��l�U�A�S�r��@�U�I�I"NOR,me,target);
        
        damage = damage*stillhunt_sk/100;
        show_damage(me, target, damage);
        target->receive_damage("hp",damage,me);
        message_vision("\n",me);
        COMBAT_D->report_status(target);
        
        if( stillhunt_sk >= 20 )
            target->start_busy(1);
        if( stillhunt_sk >= 40 )
            target->add_busy(1);
        
        if( stillhunt_sk > 40 ) {
            message_vision(HIR"$N"HIR"�X��½���٦b$n"HIR"�餺��"
                           +weapon->name() +HIR"�A���G�y����j������ˮ`�C\n"NOR,me,target);
            target->receive_wound("body", 4 + random(3));
        }
        if( stillhunt_sk > 60 )
            me->attack();
        if( stillhunt_sk > 80 )
            me->attack();
        if( stillhunt_sk == 100 )
            me->attack();
         me->improve_skill("stillhunt",1+random(me->query_dex()));
    }

    tell_object(me,HIG"�A���o����ʱo��F"+exp+"�I�g��ȡC\n"NOR);
    me->add("exp",exp);
        me->add("evil", 1 + exp%10 );
    weapon->attack(me,target); 	//�Z���i�঳�S��.
    me->improve_skill("backstab",2+random(me->query_int()/2+me->query("level")/2));
    return;
}
int do_team_backstab(object me,string arg)
{
    object target,weapon,weapon2,*members=({}),*attacker=({});
    int i,k,sk,sk2;
    string false="",me_name,v_name,attacks_name="",temp_name;
    if(!me)
        return 0;
    if(!arg)
        return notify_fail("�A�n����֡S\n");
    sk=me->query_skill("backstab");
    sk2=me->query_skill("organization");
    if(!me->is_team_leader())
        return notify_fail("�u���ⶤ�i�H�U�F�p�X�����R�O�C\n");
    if(!weapon=me->query_temp("weapon"))
        return notify_fail("�A�S�����Z���p��I��?\n");
    if(!weapon->can_stab() )
        return notify_fail(weapon->name()+"�ä��A�X�ΨӭI��C\n");
    if(me->is_busy() || me->is_block())
        return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
    if( me->is_fighting() )
        return notify_fail("�A���b�԰��S�ŭI��C\n");
    if(sk<1)
        return notify_fail("�A���٨S�ǹL�I��C\n");
    if(sk2<1)
        return notify_fail("�A���ζ���ʤ������m�C\n");
    if(me->query("evil")<-700)
        return notify_fail("�A�ӵ��}�F�A���ԤߤU��C\n");
    if((int)me->query("ap")< 50 || (int)me->query("mp")< 50 )
        return notify_fail("�A���믫��O���ΡA�L�k�i���p�X�I��C\n");
    target = present(arg, environment(me));
    if(!target)
        return notify_fail("�A�n����֡S\n");
    if(!living(target))
        return notify_fail("�ݲM���@�I, ���ä��O����.\n");
    if(!me->can_fight(target))
        return me->can_fight(target);
    if(target->visible(me))
        return notify_fail("��西�`���ۧA�A�A�S�����|�I��C\n");

    members=me->query_team();
    k=0;

    for(i=0;i<sizeof(members) && k<4;i++)
    {
        if(members[i]==me)
            continue;
        if(environment(members[i])!=environment(me))
            continue;
        if(!members[i]->can_fight(target))
        {
            false+=members[i]->name(1)+"�L�k�����ĤH�C\n";
            continue;
        }
        if(members[i]->is_busy() || members[i]->is_block())
        {
            false+=members[i]->name(1)+"���b���C\n";
            continue;
        }
        if(members[i]->query_skill("backstab")<1)
        {
            false+="  "+members[i]->name(1)+"�S�ǹL�I�뤣���D�ӫ�򰵡C\n";
            continue;
        }
        if(random(sk2/15+members[i]->query_skill("organization")/10)<1)
        {
            false+="  "+members[i]->name(1)+"���G�Sť��A�����ܡC\n";
            continue;
        }
        if(!weapon2=members[i]->query_temp("weapon"))
        {
            false+="  "+members[i]->name(1)+"�S���Z���C\n";
            continue;
        }
        if(!weapon2->can_stab())
        {
            false+="  "+members[i]->name(1)+"�����F�Z���C\n";
            continue;
        }
        if(members[i]->is_fighting())
        {
            false+=members[i]->name(1)+"�����۾԰��C\n";
            continue;
        }
        if(members[i]->query("mp")<20 || members[i]->query("ap")<25 )
        {
            false+="  "+members[i]->name(1)+"�����z���H�I��C\n";
            continue;
        }
        if(target->visible(members[i]))
        {
            false+="  "+members[i]->name(1)+"�Q�ĤH�o�{�F�C\n";
            continue;
        }

        attacks_name+=members[i]->name(1)+"�A";
        attacker+=({members[i]});
        k++;
    }

    if(k < 1 )
    {
        if(false!="")
            return notify_fail("�A��F�@�ӧ��������...���G..\n"+false+"\n�A�u�n�����o��������ʡC\n");
        else
            return notify_fail("�A��F�@�ӧ�������աA���O���G�S���H�`�N��A���R�O�C\n");
    }
    me_name=me->name();
    v_name=target->name();
    tell_object(me,HIY"�A��F�@�ӧ�������աA�M��p���l�l�a�V"+target->name()+HIY"���I�ᱵ��...\n"NOR);
    for(i=0;i<sizeof(attacker);i++)
    {
        temp_name = attacks_name;
        temp_name = replace_string( temp_name, attacker[i]->name(1)+"�A", "");
        tell_object(attacker[i],me_name+"��F�@�ӧ�������աA"+temp_name+"�M�A�P�ɮ������V"+v_name+"���I��C\n");
        attacker[i]->add_busy(2);
//        attacker[i]->receive_damage("mp",10);
        attacker[i]->receive_damage("ap",20);
    }
    write("(�o��������`�H�Ƭ�: "+(string)(sizeof(attacker)+1)+" �H�C)\n");
  //  me->receive_damage("mp",45);
    me->receive_damage("ap",40);
    me->add_busy(2);
    call_out("team_bs",4,me,target,attacker);
    return 1;
}

void team_bs(object me,object target,object *attacker)
{
      int damage,exp,sk,c,i;
    object weapon;
    string msg;

    if(!me || !target)
        return;
    if(!weapon=me->query_temp("weapon"))
    {
        tell_object(me,"�A�{�ɨ��U�Z���A���F�o������ʡC\n");
        return;
    }
    if(environment(me) != environment(target) || !me->visible(target))
    {
        tell_object(me,"�ؼЮ����F�A�A�u�n���F�o������ʡC\n");
        for(i=0;i<sizeof(attacker);i++)
        {
            tell_object(attacker[i],"�ؼЮ����F�A�A�u�n���F�o������ʡC\n");
        }
        return;
    }

    if(target->query_skill("perception")/20+random(target->query_dex()/7)
            > sk/15+random(sk/10+me->query_dex()/4)+me->query_temp("hide")*3
      )
    {
        me->delete_temp("hide");
        message_vision(HIW"$N"HIW"�@�s�H�Q�q�I�᰽ŧ$n"HIW"�A���O�o�Q$n"HIW"�o�{�F!!\n"NOR,me,target);
        me->improve_skill("backstab",1+random(1+me->query_int()/10));
        target->kill_ob(me);
        me->add_busy(2-(me->query_skill("free_action")/50)); //�ޯ� free_action �ΨӴ�֦��L�ɶ�
        for(i=0;i<sizeof(attacker);i++)
        {
            attacker[i]->delete_temp("hide");
            target->kill_ob(attacker[i]);
            attacker[i]->add_busy(2-(attacker[i]->query_skill("free_action")/50));
        }
    }
    else
    {
        me->delete_temp("hide");
        sk=me->query_skill("backstab");
        c=target->query_armor();
        damage=me->query_damage()*4+sk;
        damage=damage/2+random(damage/3);
        if(weapon->query("backstab_bonus")!=0)
            damage=damage*(100+weapon->query("backstab_bonus"))/100;
        damage=damage-c/4-random(c/5);
        if(damage<20)
            damage=20+random(10);
        damage += damage*(me->query("evil")/700);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bio");
        exp=damage/2;
        if(damage>200)
            msg=RED"$n"RED"�G�s�@�n!! ���W�ٵo�X�@�n�y��!!�z���G�O���Y�H�����n���C"NOR;
        else if(damage > 130)
            msg=HIR"$n"HIR"�@�n�s�z!! �ˤf�`�i�����C"NOR;
        else if(damage > 60)
            msg=HIM"$n"HIM"�j�s�@�n!! �A���q�F�@�a�C"NOR;
        else
            msg=HIM"�h��$n"HIM"�z�z�j�s�A�X�G�֭n�����L�h�C"NOR;
        message_vision(HIW"\n$N"HIW"��M�X�{�b$n"HIW"������A�|�_"+weapon->name()+HIW"�ΤO����$n"HIW"�I�W��F�U�h!!"NOR,me,target);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
        message_vision("\n"+msg+"\n",me,target);
        target->receive_damage("hp",damage,me);
        target->add_busy(2);
        if(target->query("hp") > 0)
            COMBAT_D->report_status(target);
        tell_object(me,HIG"�A���o����ʱo��F"+exp+"�I�g��ȡC\n"NOR);
        me->add
        ("exp",exp);
        weapon->attack(me,target); //�Z���i�঳�S��.
        me->improve_skill("backstab",1+random(me->query_int()/2+me->query("level")/2));
        me->improve_skill("organization",1+random(me->query_int()/2+me->query("level")));
        me->kill_ob(target);
        if(target->query("hp") > 0)
            target->kill_ob(me);
        message_vision(HIC"\n\n$N"HIC"�@���o�⤧��A$n"HIC"�������H�Y�S«�X�X�D�¼v!!"NOR,me,target);
        for(i=0;i<sizeof(attacker);i++)
        {
            attacker[i]->delete_temp("hide");
            weapon=attacker[i]->query_temp("weapon");
            if(!weapon)
                continue;
            sk=attacker[i]->query_skill("backstab");
            damage=attacker[i]->query_damage()*4+sk;
            if(weapon->query("backstab_bonus")!=0)
                damage=damage*(100+weapon->query("backstab_bonus"))/100;
            damage=damage/2+random(damage/3);
            damage=damage-c/3-random(c/5);
            if(damage<20)
                damage=20+random(10);
            damage += damage*(attacker[i]->query("evil")/700);
            damage = COMBAT_D->Merits_damage(attacker[i],target,damage,"bar");
            exp=damage/2;
            if(damage>200)
                msg=RED"$n"RED"�G�s�@�n!! ���W�ٵo�X�@�n�y��!!�z���G�O���Y�H�����n���C"NOR;
            else if(damage > 130)
                msg=HIR"$n"HIR"�@�n�s�z!! �ˤf�`�i�����C"NOR;
            else if(damage > 60)
                msg=HIM"$n"HIM"�j�s�@�n!! �A���q�F�@�a�C"NOR;
            else
                msg=HIM"�h��$n"HIM"�z�z�j�s�A�X�G�֭n�����L�h�C"NOR;
            message_vision(HIW"\n$N"HIW"��M�X�{�b$n"HIW"������A�|�_"+weapon->name()+HIW"�ΤO����$n"HIW"�I�W��F�U�h!!"NOR,attacker[i],target);
            if(attacker[i]->query_temp("apply/show_damage") || attacker[i]->query_temp("show_damage") )
                tell_object(attacker[i],HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+(string)(target->query("hp")-damage)+"/"+target->query("max_hp")+")");
            message_vision("\n"+msg+"\n",attacker[i],target);
            target->receive_damage("hp",damage,attacker[i]);
            if(target->query("hp") > 0)
                COMBAT_D->report_status(target);
            tell_object(attacker[i],HIG"�A���o����ʱo��F"+exp+"�I�g��ȡC\n"NOR);
            attacker[i]->add
            ("exp",exp);
            weapon->attack(attacker[i],target); //�Z���i�঳�S��.
            attacker[i]->improve_skill("backstab",1+random(attacker[i]->query_int()/2+attacker[i]->query("level")/2));
            attacker[i]->improve_skill("organization",1+random(attacker[i]->query_int()/2+attacker[i]->query("level")));
            attacker[i]->kill_ob(target);
            if(target->query("hp") > 0)
                target->kill_ob(attacker[i]);
        }
        return;
    }

    return;
}

int do_sneak(object me,string arg)
{
    object env,obj,ride,defender,protecter;
    string dest, dir,*busy_type;
    mapping exit=([ ]),h_exit=([ ]),is_busy=([ ]);
    int wound=0,i=0,sk,h;

    if( !arg )
        return notify_fail("�A�n�����Ӥ�V���S\n");
    sk=me->query_skill("sneak");
    if(sk<1)
        return notify_fail("�A���٨S�ǹL���C\n");
    if( me->over_encumbranced() )
        return notify_fail("�A���t���L���A�ʼu���o�C\n");
    if( me->is_fighting() )
        return notify_fail("�A���b�԰��S�ż��C\n");
    if( me->is_busy() )
        return notify_fail("�A���ʧ@�٨S�������C\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("�A���믫��O���ΡA�L�k���C\n");
    if(mapp(is_busy=me->query_temp("is_busy")))
    {
        busy_type=keys(is_busy);
        for(i=0;i<sizeof(is_busy);i++)
        {
            if(stringp(is_busy[busy_type[i]]))
                return notify_fail(is_busy[busy_type[i]]+"\n");
            if(!is_busy[busy_type[i]])
                return notify_fail("�A�ȮɵL�k���ʡC\n");
        }
    }
    if(ride=me->query_temp("ride"))
        return notify_fail("�A�����b"+ride->name()+"�W�A�L�k���C\n");
    if(wound = me->query("wound/foot") )
    {
        wound/=10;
        if( wound > 2)
            return notify_fail(HIC"�A�����}�˶չL���A�L�k���C\n"NOR);
    }
    env = environment(me);
    if(!env)
        return notify_fail("�A���̤]�h���F�C\n");

    exit = env->query("exits");
    h_exit = env->query("hide_exits");

    if( mapp(exit) && !undefinedp(exit[arg]) )
        ;
    else
        if( !mapp(h_exit) || undefinedp(h_exit[arg]) )
        {
            return notify_fail("�o�Ӥ�V�S���X���C\n");
        }

    if(!mapp(exit))
        dest = h_exit[arg];
    else if( !exit[arg])
        dest = h_exit[arg];
    else
        dest = exit[arg];

    if( !(obj = find_object(dest)) )
        call_other(dest, "???");

    if( !(obj = find_object(dest)) )
        return notify_fail("�L�k���ʡC\n");

    if( !env->valid_leave(me, arg) )
        return 0;

    if( !undefinedp(default_dirs[arg]) )
        dir = default_dirs[arg];
    else
        dir = arg;

    if(defender=me->query_temp("defender"))
    {
        defender->delete_temp("protecter");
        me->delete_temp("defender");
    }
    if(protecter=me->query_temp("protecter"))
    {
        protecter->delete_temp("defender");
        me->delete_temp("protecter");
    }
    tell_object(me,"�A�p���l�l���}�l��"+dir+"���C\n");
    if(random(10+sk/5+me->query_dex()/5) < 7 )
        h=0;
    else
        h=1;
    me->set_temp("hide",h);
    me->delete_temp("visible_ob");
    me->receive_damage("ap",3);
//    me->receive_damage("mp",5);
    me->add_busy(2);
    call_out("go_sneak",3,me,obj,env,dir,arg);
    return 1;
}

void go_sneak(object me, object obj,object env,string dir,string arg)
{
    string mout,min;

    if(!me || !obj || !env || !dir)
        return;
    if( me->query_temp("invis") < 1 && me->query_temp("hide") < 1)
    {
        mout = "��������" + dir + "���F�L�h�C\n";
        if(me->query("race")=="�H��")
            min = "�����N�N�����F�L�ӡC\n";
        else
            min = "�������Ө즹�B�C\n";

        message( "vision", me->name() + mout, environment(me), (
                     {
                         me
                     }
                 ) );
    }

    if( me->move(obj) )
    {
        me->remove_all_enemy();
        if(me->query_temp("invis") < 1 && me->query_temp("hide") < 1 )
        {
            message("vision", me->name() + min, environment(me), ({me}) );
            //			all_inventory(env)->follow_me(me, arg);
            //			sneak ����, player�����follow, by -alickyuen@ds-
            //			�H����player follow thief �asneak fail �h�@�ǭ쥻���ɸ����a��
            me->add_busy(2);
        }
        else
        {
            tell_object(me,HIG"�A�������ȤF�L�ӡA�S���Q�H�o�{�C\n"NOR);
            me->improve_skill("sneak",1+random(me->query_int()/2+me->query("level")/2));
        }
        me->set_temp("pending", 0);
        if(random(3)==1)
            me->delete_temp("visible_ob");
        return;
    }

    return ;
}

int do_hide(object me,string arg)
{
    object env;
    int sk,i;
    string *busy_type;
    mapping is_busy=([ ]);

    sk=me->query_skill("hide");
    if(sk<1)
        return notify_fail("�A�٨S�ǹL�I����ä��N�C\n");
    if( me->is_fighting() )
        return notify_fail("�A���b�԰��S�ż��C\n");
    if( me->is_busy() )
        return notify_fail("�A���ʧ@�٨S�������C\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("�A���믫��O���ΡA�L�k���áC\n");
    if(mapp(is_busy=me->query_temp("is_busy")))
    {
        busy_type=keys(is_busy);
        for(i=0;i<sizeof(is_busy);i++)
        {
            if(stringp(is_busy[busy_type[i]]))
                return notify_fail(is_busy[busy_type[i]]+"\n");
            if(!is_busy[busy_type[i]])
                return notify_fail("�A�ȮɵL�k���ʡC\n");
        }
    }
    if(! env = environment(me) )
        return notify_fail("�o�̨S���a��i���C\n");
    if( env->query("no_hide") )
        return notify_fail("�o�̨S���a��i�H�ѧA�è��C\n");

    if(!me->query_temp("hide") && me->query_temp("invis"))
        message( "vision", me->name() + "�}�l��a����áC\n", environment(me), ({me}) );

    tell_object(me,"�A����I�l�A�}�l��a����áC\n");

    me->set_temp("is_busy/hide","�A���b���áC");
    me->receive_damage("ap",2);
//    me->receive_damage("mp",2);
    me->start_busy(2);
    call_out("finish_hide",3,me,sk);
    return 1;
}

void finish_hide(object me,int sk)
{
    int result;
    result=random(9+sk/5);
    me->delete_temp("is_busy/hide");
    me->add_temp("hide",result);
    if(result>5)
    {
        tell_object(me,"�A���������F�_�ӡC\n");
        ROOM_D->moveout(environment(me),me); //add by luky
        me->improve_skill("hide",2+random(me->query_int()/2+me->query("level")/2));
        me->delete_temp("visible_ob");
    }
    if( me->query_temp("hide") > 10)
        me->set_temp("hide",2+random(9));
    me->improve_skill("hide",2+random(1+me->query_int()/2));
}

int sort_item(object ob1, object ob2)
{
    string file1,file2;
    file1=base_name(ob1);
    file2=base_name(ob2);
    if(file1==file2)
    {
        return getoid(ob2)-getoid(ob1);
    }
    return strcmp(file1,file2);
}

int do_peep(object me,string arg)
{

    int i,j,sk;
    object *inv=({}), *obj=({}) ,ob;
    string str;
    if( !arg )
        return notify_fail("�A�n���s�֡S\n");
    if( me->is_fighting() )
        return notify_fail("�A���b�԰��S�Ű��s�C\n");
    if( me->is_busy() )
        return notify_fail("�A���ʧ@�٨S�������C\n");
    if((int)me->query("ap")<10 || (int)me->query("mp")<10 )
        return notify_fail("�A���믫��O���ΡA�L�k���s�O�H�C\n");
    sk=me->query_skill("peep");
    if(sk<1)
        return notify_fail("�A���٨S�ǹL���s���N�C\n");
    ob = present(arg, environment(me));
    if(!ob)
        return notify_fail("�o�̨S���o�ӤH�C\n");
    if(!me->visible(ob))
        return notify_fail("�o�̨S���o�ӤH�C\n");
    if( !ob->is_character() )
        return notify_fail(ob->name()+"�ä��O�H�C\n"); // add by alick
    me->add_busy(1);
    me->receive_damage("ap",4);
    if(sk/2+random(sk/2) < random(ob->query_skill("perception")))
    {
        tell_object(me,"�A�Q���s"+ob->name()+"�i�O�Q�o�{�F�C\n");
        tell_object(ob,"�A��M�o�{"+me->name()+"�Q���s�A�C\n");
        me->delete_temp("hide");
        me->add_busy(1);
        if(!userp(ob) && random(ob->query("evil"))>10)
            ob->kill_ob(me);
        return 1;
    }
    tell_object(me,"�A�}�l�J�Ӫ��[��"+ob->name()+"...\n�A�o�{");
    obj = all_inventory(ob);
    for(i=0;i<sizeof(obj);i++)
    {
        if(obj[i]->query_temp("riden"))
            continue;
        if(obj[i]->query_temp("invis"))
            continue;
        if(random(2+sk/15))
            inv+=({obj[i]});
    }
    if( !sizeof(inv) )
    {
        write( ob->name() + "���W�S����a����F��C\n");
        me->improve_skill("peep",1+random(me->query_int()/2));
        return 1;
    }
    inv = sort_array(inv, "sort_item", this_object());
    str="";
    j=1;
    for(i=0; i<sizeof(inv); i++)
    {
        if( i+1 < sizeof(inv) )
        {
            if( inv[i]->query("name") == inv[i+1]->query("name")
                    && inv[i]->query("secured") == inv[i+1]->query("secured")
                    && !inv[i+1]->query("equipped")
                    && !inv[i+1]->query_temp("has_light")
                    && !inv[i]->query_temp("no_combine")
                    && !inv[i+1]->query_temp("no_combine")
              )
            {
                if(inv[i]->query("equipped") || inv[i]->query_temp("has_light"))
                {
                    str += inv[i]->item_describe(0)+"\n";
                }
                else
                    j++;
            }
            else
            {
                if(j>1)		//luky ��ӥH�W�A��ܼƶq
                {		//luky
                    str += chinese_number(j);
                    str += inv[i]->query("unit")  ? inv[i]->query("unit"):"��";
                }		//luky
                str = sprintf("%s%-32s  \n",str,inv[i]->item_describe(0));
                j = 1;
            }
        }
        else
        {
            if(j>1)		//luky ��ӥH�W�A��ܼƶq�ո�
            {		//luky
                str += chinese_number(j);
                str += inv[i]->query("unit")  ? inv[i]->query("unit"):"��";
            }		//luky
            str = sprintf("%s%-32s  \n",str,inv[i]->item_describe(0));
        }
    }


    printf("%s���W�a�ۤU�C�o�ǪF��R         \n"+
           "=========================================\n",
           ob->name(),
          );
    str += "\n";
    me->start_more(str);
    me->improve_skill("peep",1+random(me->query_int()/2+me->query("level")/2));
    return 1;
}

int do_steal(object me,string arg)
{
    string what, who;
    object ob, victim,env;
    int sp, dp, sk, error, cost;

    if(!me)
        return 0;
    if(!living(me))
        return 0;
    if(!env=environment(me))
        return 0;
    if( me->is_busy() )
        return notify_fail("�A���ʧ@�٨S�������C\n");
    if( me->is_fighting())
        return notify_fail("�A���b�@�ԡA�S�Ű��F��C\n");
    if( me->query("mp")<10)
        return notify_fail("�A�믫���ΡA�L�k�����믫���F��C\n");
    if( me->query("ap")<15)
        return notify_fail("�A��O���ΡA�S���O�q���O�H���F��C\n");
    if( me->query("thief"))
    {
          // adv tf stealing > 70 �i�K�e�쭭��
          if( me->query("adv_class") == 1 )
                return notify_fail("�b�A���e�쥼�������e�A�ȮɵL�k���F��C\n");
           if( me->query_skill("stealing") < 70 )
                return notify_fail("�b�A���e�쥼�������e�A�ȮɵL�k���F��C\n");

           // �����e��
            me->delete("thief");
    }


    //�P�_����
    if( env->query("no_steal") )
        return notify_fail("�o�̸T����ѡC\n");
    //�O�_���b����
    if( me->query_temp("stealing") )
        return notify_fail("�A�w�g�b����|�U��F�T\n");
    //���O�O�_���T
    if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
        return notify_fail("���O�榡�Rsteal <���~> from <�H��>\n");
    //��H�O�_���T
    victim = present(who, environment(me));
    if(!me->visible(victim))
        return notify_fail("�A�Q���Ѫ���H���b�o�̡C\n");
    if( !victim || victim==me)
        return notify_fail("�A�Q���Ѫ���H���b�o�̡C\n");
    if( !victim->is_character())
    {
        notify_fail(who+"���G�S������n�����C\n");
        return victim->be_stolen(me,what);	//��\����i�H���Q�����ʧ@�禡.
    }
    if( victim->is_corpse() )
        return notify_fail("�ݲM���I�H�o�O����C�A�������N��F�r�I\n"); // add by alick
    if( !wizardp(me) && wizardp(victim) )
        return notify_fail("���a���ఽ�Ův���W���F��C\n");
    if( !me->can_fight(victim) || victim->query("no_steal"))
        return notify_fail("���G���@�ѤO�q���A�L�k��"+victim->name()+"�U��C\n");
    if( victim->is_shopman() )
        return notify_fail("�]��Bug�����Y�A�Ȯ����������E���\\��C\n");// alick
    sk=me->query_skill("stealing");
    //������? �޳N�����i��|�����F��..
    if(userp(victim))
    {

        //OK, �}�l���I�믫��F��a...

        if( !ob = present(what, victim) )
        {
            //			return notify_fail(" �A��b�ݤ��X��" + victim->name() + "�� "+ what + " ��b���̡C\n");
            return notify_fail("���G�S���o�ӪF��i���C\n");
        }

        if( random(20+sk) < 10 )
        {
            me->receive_damage("ap",2);
            me->add_busy(1);
            return notify_fail("�A���ޥ��������m�A�⦣�}�ä����Ӧp��U��C\n");
        }
        //�����F���o~~
        if(random(10+sk) < 5)
        {
            object *inv;
            inv = all_inventory(victim);
            if( !sizeof(inv) )
                return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");
            ob = inv[random(sizeof(inv))];
            if( !ob->id(what) )
                error = 1;
        }

         if(ob->query_autoload() || ob->query("no_give") || ob->query("no_steal") || ob->query("no_get") )
            return notify_fail("�A���ఽ�����˪F��C\n");
        if(ob->query("equipped"))
            return notify_fail("�A�L�k�������b�˳Ƥ����F��C\n");

        me->receive_damage("ap",5);

        sp = sk * 2 + (int)me->query_dex()*2 + me->query("level") + me->query_temp("hide")*5; //max=200+2*dex
        if( sp < 1 )
            sp = 1;

        dp = (int)victim->query_skill("perception") * 2 + (int)ob->weight()/100 + victim->query("level");
        dp += victim->query_dex()+victim->query_int();
        if( victim->is_fighting() )
            dp /= 2;

        cost=10;
        if(ob->value())
            cost+=5;
        else
            cost+=ob->weight()/1000;
        me->add_busy(3);
        me->receive_damage("ap",cost);
        if(wizardp(me) && me->query("env/debug"))
            write("SP-> "+sp+"  DP->"+dp+"\n");
        write("�A�����a�C�C�a��" + victim->name() + "�A���ݾ��|�U�� ...\n\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp , error);
        return 1;
    }
    else
    {
        if(victim->be_stolen(me,what))
            return 1;
        //OK, �}�l���I�믫��F��a...
        if( !ob = present(what, victim) )
        {
            if(victim->is_sellman() || victim->is_lottery_npc() )
            {
                mapping list;
                string *file;
                object item;
                int j;

                if(!mapp(list = victim->query("sell_list")) )
                    return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");
                file=keys(list);
                for(j=0;j<sizeof(file);j++)
                {
                    item=new_ob(file[j]);
                    if(item->id(what))
                    {
                        ob=item;
                        break;
                    }
                }

            }
            else if(victim->is_shopman())
            {
                object stroom;
                if(!stroom=load_object(victim->query("storeroom")))
                    return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");
                if( !ob = present(what, stroom) )
                    return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");
            }

            if(!ob)
                return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");

        }

        if(ob->query_autoload() && ob->query("no_drop"))
            return notify_fail("�A���ఽ�����˪F��C\n");
        if(ob->query("equipped"))
            return notify_fail("�A�L�k�������b�˳Ƥ����F��C\n");

        //�����F���o~~
        if(random(10+sk) < 5)
        {
            object *inv;
            inv = all_inventory(victim);
            if( !sizeof(inv) )
                return notify_fail("�A��b�ݤ��X��"+ victim->name() + "�� "+what+" ��b���̡C\n");
            ob = inv[random(sizeof(inv))];
            if( !ob->id(what) )
                error = 1;
        }

        /*		��improve_skill()�����h�� by -alickyuen@ds-
        		�H�K����player����Steal�F��,�]�����|�[��Լ�	*/
        if( random(20+sk) < 10 )
        {
            me->receive_damage("ap",2);
            me->add_busy(1);
            me->improve_skill("stealing", me->query_int()/3+random(me->query_int()/2));
            return notify_fail("�A���ޥ��������m�A�⦣�}�ä����Ӧp��U��C\n");
        }

//        me->receive_damage("mp",5);

        sp = sk * 2 + (int)me->query_dex() * 2 + me->query("level"); //max=300+2*dex
        if( sp < 1 )
            sp = 1;

        dp = (int)victim->query_skill("perception") + (int)ob->weight()/200 + victim->query("level");
        dp += victim->query_dex()+victim->query_int();
        if( victim->is_fighting() )
            dp /= 2;

        cost=10;
        if(ob->value())
            cost+=5;
        else
            cost+=ob->weight()/1000;
        me->add_busy(3);
        me->receive_damage("ap",cost);
        if(wizardp(me) && me->query("env/debug"))
            write("SP-> "+sp+"  DP->"+dp+"\n");
        write("�A�����a�C�C�a��" + victim->name() + "�A���ݾ��|�U�� ...\n\n");
        me->set_temp("stealing", 1);
        call_out( "compelete_steal", 3, me, victim, ob, sp, dp , error);
        return 1;
    }
}

void compelete_steal(object me, object victim, object ob, int sp, int dp,int error)
{
    object ob2;
    int amount,total,sk;
    if(!me)
        return;
    me->delete_temp("stealing");
    sk=me->query_skill("stealing");
    if(!victim)
    {
        tell_object(me, "�ӥi���F�A�A�U�⪺�ؼФw�g���F�C\n");
        return;
    }

    if( environment(victim) != environment(me) )
    {
        tell_object(me, "�ӥi���F�A�A�U�⪺�ؼФw�g���F�C\n");
        return;
    }

    if( !living(victim) || (random(sp+dp) > dp) )
    {
        if( total=ob->query_amount() )
        {
            ob2=new_ob(base_name(ob));
            amount=1+(total*sk/300);
            amount+=random(amount/2);
            ob2->set_amount(amount);

            if( !ob2->can_move(me) )
            {
                tell_object(me, "�A�N��@" + ob2->query("unit") + ob2->name()
                            + "�M�i�O�A�����ʡA�u�n���C\n");
                return;
            }
            total-=amount;
            ob->set_amount(total);
            ob2->move(me);
            tell_object(me, HIW "�o��F�T\n\n" NOR);
            tell_object(me, "�A���\\�a����@" + ob2->query("unit") + ob2->name() + "�T\n");
            if( living(victim) )
                me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
//          if( random(sp) < dp/2 )  // �Ȯ�mark ���A���p���C������F��ɡA�䥦�H����ݨ�T��
                message("vision", "�A�ݨ�" + me->name() + "���������a�q"
                        + victim->name() + "���W�����F�@" + ob2->query("unit")
                        + ob2->name() + "�T\n", environment(me), ({ me, victim }) );
            return;
        }
        else
        {
            if( !ob->can_move(me) )
            {
                tell_object(me, "�A�N��@" + ob->query("unit") + ob->name()
                            + "�M�i�O�A�����ʡA�u�n���C\n");
                return;
            }
            ob->move(me);
            ob->set
            ("value",ob->query("value")/5);
            tell_object(me, HIW "�o��F�T\n\n" NOR);
            tell_object(me, "�A���\\�a����@" + ob->query("unit") + ob->name() + "�T\n");
            if( living(victim) )
                me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
            if( random(sp) < dp/2 )
                message("vision", "�A�ݨ�" + me->name() + "���������a�q"
                        + victim->name() + "���W�����F�@" + ob->query("unit")
                        + ob->name() + "�T\n", environment(me), ({ me, victim }) );
            return;
        }
    }
    else
    {
        if( random(sp) > dp/2 )
        {
            tell_object(me, victim->name() + "���g�N�a�@���Y�M�A�榣�N���Y�F�^�h�T\n"
                        "�٦n�M�S���Q�o�{�C\n");
            me->improve_skill("stealing", 1+me->query_int()/2+random(me->query_int()/2));
            return;
        }
        me->add_busy(5-(me->query_skill("free_action")/30));
        me->add
        ("thief",1);
        tell_object(me, HIR "�V�|�T�A����F�T\n\n" NOR);
        me->improve_skill("stealing", me->query_int()/2+random(me->query_int()));
        message_vision("$N�@�^�Y�M���n�o�{$n���⥿���$P���W��" + ob->name() + "�T\n\n"
                       + "$N�ܹD�R�u�F����T�v\n\n", victim, me);
        victim->improve_skill("perception", 2+random(victim->query_int()/4));
        //		if( userp(victim) ) victim->fight_ob(me);
        //		else victim->kill_ob(me);
        if(!userp(victim))
        {
            victim->kill_ob(me);
            me->fight_ob(victim);
        }
        return;
    }
}

int do_pick(object me,string arg)
{
    mapping doors;
       string *dirs, dir;
    int i,sk,power;
      object env, obj;

    if( !arg )
        return notify_fail("�A�n�}������S\n");
    env = environment(me);
    if(!env)
        return 0;
    if(me->is_busy())
        return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
    if(me->query("mp")<10)
        return notify_fail("�A�믫���ΡA�L�k�����`�N�O�Ӷ}��C\n");
    if(obj=present(arg, env))
    {
        if(obj->is_box())
        {
            switch(obj->query_cover_status())
            {
            case COVER_NONE :
                return notify_fail(obj->name()+"�èS���a��i�H���A�}��C\n");
            case COVER_OPENED :
                return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g�O�}�۪��աC\n");
            case COVER_SMASHED :
                return notify_fail(obj->name()+"��"+obj->query("cover_name")+"���w�g�a�F�ٶ}������?!\n");
            }
            switch(obj->query_lock_status())
            {
            case LOCK_NONE :
                return notify_fail(obj->name()+"�èS���a��i�H���A�}��C\n");
            case LOCK_OPENED :
                return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�èS���W��C\n");
            case COVER_SMASHED :
                return notify_fail(obj->name()+"����w�g�a�F�L�k���}�C\n");
            }

            sk=me->query_skill("pick_lock");
            power=random(2+sk/10);
            if(power>9)
                power=9;
            if(power >= obj->query_lock_level())
            {
                if(obj->open_lock())
                {
                    me->add_busy(1);
                    me->receive_damage("ap",5+power);
                    message_vision("�y..�ذ�!!�z$N���\\���N$n���ꥴ�}�F�C\n",me,obj);
                    me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                    return 1;
                }
                else
                    return notify_fail("�y..��!!�z�A���G��"+obj->name()+"���굹���a�F�C\n");
            }
            else
            {
                me->add_busy(1);
                me->receive_damage("ap",5+power);
                message_vision("$N�V�O���Q��$n���ꥴ�}�A���O���ѤF�C\n",me,obj);
                obj->pick_lock_fail(me,arg); //�i�H�����Ѫ��N��
                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                return 1;
            }
        }
        else
            return notify_fail("���ӪF��S����k���A�}��C\n");
    }

    doors = env->query_doors();
    if( mapp(doors) )
    {
        dirs = keys(doors);
        if( member_array(arg, dirs)!=-1 )
            dir = arg;
        else
            for(i=0; i<sizeof(dirs); i++)
                if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
                {
                    dir = dirs[i];
                    break;
                }
        if( !dir )
            return notify_fail("�o�Ӥ�V�S�����C\n");
        //key=env->query_door(dir,"key");
        //if(!key ) return notify_fail("�o�Ӫ��èS���W��!\n");

        if( doors[dir]["status"] == DOOR_SMASHED )
            return notify_fail("�o��" + doors[dir]["name"] + "�w�g�a�F�C\n");
        if( doors[dir]["status"] == DOOR_OPENED  )
            return notify_fail( doors[dir]["name"] + "�w�g�O�}�۪��F�C\n");
        if( !(doors[dir]["status"] == DOOR_LOCKED)  )
            return notify_fail(doors[dir]["name"] + "�èS���W��C\n");
        if( env->query("no_pick") )
            return notify_fail(doors[dir]["name"] + "����O�S�s���A���|�}�C\n");
        i=env->query("pick_level");
        power=1+random(40+me->query_skill("pick_lock"))-i;
        if(power >= 30)
        {
            if(env->unlock_door(dir))
            {
                me->add_busy(1);
                me->receive_damage("ap",5+power/8);
                message_vision("�y..��.��!!.�z"+"$N���\\���N" + doors[dir]["name"] + "���ꥴ�}�F�C\n", me);
                me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                return 1;
            }

        }
        else
        {
            me->add_busy(1);
            me->receive_damage("ap",5+power/8);
            message_vision("$N�V�O���Q��" + doors[dir]["name"] + "���ꥴ�}�A���O���ѤF�C\n",me);
            env->pick_lock_fail(me,dir); //�i�H�����Ѫ��N��
            me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
            return 1;
        }
    }
    else
        return notify_fail("�o�̨S�����C\n");
    return 0;
}
