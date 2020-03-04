/*****************************************************/
/* Sorsin_Force V2.0             DATE:2006.11.25     */
/* EDITOR:tmr                                        */
/*****************************************************/

/*****************************************************/
/* Sorsin_Force V1.3             DATE:2006.3.25      */
/* EDITOR:Whoami                                     */
/* ..........���]�S�擄���.....�ҥHcomment�N�K�F..*/
/*****************************************************/

/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */
/* �@�q�ɶ���,��ppl������,�A�ݭn���n�}�s�C           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "���P���q"
inherit SKILL;
inherit SSERVER;


string *sor_str= ({
                      "$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v\n"NOR,
                      "$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v\n"NOR,
                      "$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i\n",
                      "$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v\n"NOR,
                      "$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n�ϥX�@��"HIC"�u"HIW"�N"HIC"�v\n"NOR,
                  });


int exert(object me, object target,string arg)
{
    string msg="";
    int damage,sk,c,te,i,x,delay_time,busy_time;
     object weapon;
    me=this_player();
    
       if(userp(me) && !wizardp(me)) return notify_fail("�ޯ�վ㤤�A�Ȯ������C\n");
    if(!me) return 0;
    if(!me->is_fighting()) return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�!\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"?\n");
    if( me->query_temp("nan") )
        return notify_fail("�A�u�ɶ�������ϥ�"+SKILL_NAME+"�I\n");
    if((int)me->query("mp") < 50 || (int)me->query("ap") < 100)
        return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
    if(!weapon=me->query_temp("weapon")) return notify_fail("�ϥί��P���q�ݭn�ϥΪZ���C\n");
    if(weapon->query("skill_type")!="sword")
        return notify_fail("�ϥ�"+SKILL_NAME+"�����n���C�C\n");
    if(me->query_skill("sword")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�C�k��¦�C\n");
    if(me->query_skill("dodge")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�{����¦�C\n");
    if(me->query_skill("sorgi_sword")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ�����C�k�C\n");
    if(me->query_skill("star-sword")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�����Ϲꪺ���P�C�q�C\n");
    if(me->query_skill("moon_force")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���p���ݤ�ߪk�C\n");
    if(me->query_skill("force")<100)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn���p�����\\�C\n");
    if(me->query_dex() <60)
        return notify_fail("�ϥ�"+SKILL_NAME+"�ݭn�������ӱ��C\n");
    if(me->query_Merits("tec") <1)
        return notify_fail("�ϥ�"+SKILL_NAME+"�A���(TEC)���൥��s�C\n");
    sk=me->query_skill("sorsin_force");
    te=me->query_Merits("tec");
    c=target->query_armor();
    if(arg == "help" || !arg)
        return notify_fail(HIC"\n"+SKILL_NAME+"�ثe�� one two three final �|���\\��A�Ԩ� help sorsin_force�C\n"NOR);
    if(arg == "one")
    {
        if(me->query_skill("sorsin_force") <1) return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");
        if( random(me->query("dex")*4) < random(target->query_skill("dodge")*2) )
        {
            msg += "\n"HIW""+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR;
            message_vision(msg,me,target);
            me->add_temp("nan",1);
            me->start_busy(1);
            call_out("stop_delay",40/te,me);
            //    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
        } else {
            damage = me->query_damage()-random(c);
            damage = damage * (random(3)+1);
            if( damage < 0 ) damage = 0;
            busy_time = random(me->query_skill("sorsin_force")/30);
            delay_time = 20/(1+me->query_skill("sorsin_force")/20);

            //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
            msg += "\n"HIM""+target->name()+"�ĤO�����I���{�k�סA�w�O���U�F�ƹD�C��I\n"NOR;
            message_vision("\n"HIW"$N�N���O�e�`��⤤���C�A�R�ժ�"HIC"�C��"HIW"�W�իݵo�E�E�E\n"NOR,me,target);
            message_vision(msg,me,target);
            target->receive_damage("hp",damage,me);
            COMBAT_D->report_status(target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");

            target->start_busy(busy_time);
            me->start_busy(delay_time);
            me->add_temp("nan",1);
            call_out("stop_delay",20/te,me);
            me->improve_skill("sorsin_force",4+random(me->query_dex()/7+me->query_Merits("tec")/3+sk/8));
        }
      me->receive_damage("mp",random(sk));
      me->receive_damage("ap",random(sk)+sk);

        return 1;
    }
    if(arg == "two")
    {
        if(me->query_skill("sorsin_force") <66)
            return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");
        if( random(me->query("dex")*5) < random(target->query_skill("dodge")*3) )
        {
            msg += HIW"\n"+target->name()+"���o��H�I����F$N���X�ۡC\n"NOR;
            message_vision(msg,me,target);
            me->add_temp("nan",1);
            me->start_busy(1);
            call_out("stop_delay",40/te,me);
            //    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
        } else {
            damage = me->query_damage()-random(c);
            damage = damage * 4;
            damage = damage + 10*(me->query("Merits/bar") - random(target->query("Merits/bar")));
            damage = damage + me->query_skill("sorsin_force");
            if( damage < 0 ) damage = 0;
            busy_time = random(me->query_skill("sorsin_force")/30);
            delay_time = 15/(me->query_skill("sorsin_force")/20);

            //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
            msg += "\n\t"HIG"�C���@�_�I\n"
                   "\t\t"HIB"�y"HIC"�ݤ뤧���E�۷��e��"HIB"�z\n"
                   "\t\t"HIW"�@�ѼC�𱽿��b"+target->name()+"���P��I�|���Ů�����@�T�I\n"
                   "\t\t"HIC"�ѯe�P�}"HIW"�ܼC�ӥX�I�ʹD�C��E�E�Ѱ}�ɤJ�E�E\n"
                   "\t\t"HIR"�A��s�z�E�E"+target->name()+"�i���E�E\n"NOR;
            message_vision("\n"HIW"$N�N���O�e�`��⤤���C�A�R�ժ�"HIC"�C��"HIW"�W�իݵo�E�E�E\n"NOR,me,target);
            message_vision(msg,me,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            target->receive_damage("hp",damage,me);
            COMBAT_D->report_status(target);
            target->start_busy(busy_time);
            me->start_busy(delay_time);
            me->add_temp("nan",1);
            call_out("stop_delay",40/te,me);
            me->improve_skill("sorsin_force",2+random(me->query_dex()/8+me->query_Merits("tec")/4+sk/8));
        }
      me->receive_damage("mp",random(sk));
      me->receive_damage("ap",random(sk)+sk);

        return 1;
    }

    if(arg == "three")
    {
        if(me->query_skill("sorsin_force") <99) return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");
        if( random(me->query("dex")*6) < random(target->query_skill("dodge")*4) )
        {
            msg += "\n"HIW""+target->name()+"���o��H�I���F$N���ۦ��C\n"NOR;
            message_vision(msg,me,target);
            me->add_temp("nan",1);
            me->start_busy(1);
            call_out("stop_delay",40/te,me);
            //    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
        }  else  {
            busy_time = random(me->query_skill("sorsin_force")/25);
            delay_time = 20/(me->query_skill("sorsin_force")/20)+random(2);
            x = random(me->query_skill("sorsin_force")/20)+te/4;
            if( x > 6 ) x = 6;
            //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
            /*
                msg += "\n\t"HIG"�C���@�_�I"HIR"$N�������Q������л\\�I\n"
                "\t\t"HIB"�y"HIC"�ݤ뤧���E�۷��e��"HIW"�E���E�ѡE��"HIB"�z\n"  
                "\t\t"HIW"�@�ѼC�𱽿��b"+target->name()+"���P��I�|���Ů�����@�T�I\n"
                "\t\t"HIW"���ɥX�F����"HIC"�ѯe�P�}"HIW"�I�d�D�C��I"HIR"���L�j�I\n"
                "\t\t"HIR""+target->name()+"�o�b"HIW"�ե�"HIR"�{������A�w�˦b��y���E�E\n"NOR;  
            */
            msg += "\n\t"HIB"�y"HIC"�ݤ뤧���E�۷��e��"HIW"�E���E�ѡE��"HIB"�z\n"NOR;

            message_vision("\n"HIW"$N�N���O�e�`��⤤���C�A�R�ժ�"HIC"�C��"HIW"�W�իݵo�E�E�E\n"NOR,me,target);
            message_vision(msg,me,target);
            for(i=0;i<x;i++){

                damage = me->query_damage()-random(c);
                damage = damage + (me->query_dex()/2)*random(x);
                if( damage < 0 ) damage = 0;

                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    tell_object(me,HIY"("+damage+")\n"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                    tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            }

            target->start_busy(busy_time);
            me->start_busy(delay_time);
            me->add_temp("nan",1);
            call_out("stop_delay",80/te,me);
            me->receive_damage("ap",x*40,me);
            me->receive_damage("mp",x*15,me);
            me->improve_skill("sorsin_force",10+random(me->query_dex()/2+me->query_Merits("tec")*2+sk/2));
        }
      me->receive_damage("mp",random(sk));
      me->receive_damage("ap",random(sk)+sk);

        return 1;
    }

    if(arg == "final")
    {
        if(me->query_skill("sorsin_force") <100) return notify_fail("\n�A��"+SKILL_NAME+"�٨S�쨺�ҬɡC\n");
        if( random(me->query("dex")*7) < random(target->query_skill("dodge")*5) )
        {
            msg += "\n"HIW""+target->name()+"���o��H�I���F$N���ۦ��C\n"NOR;
            me->start_busy(1);
            message_vision(msg,me,target);
            me->add_temp("nan",1);
            call_out("stop_delay",40/te,me);
            //    me->improve_skill("sorsin_force",5+me->query("int")*2/3);
        } else {
            damage = me->query_damage()*5-random(c);
            damage = damage + me->query_dex()*random(10);
            damage = damage - (target->query_skill("force"))*(target->query("Merits/bio")/4);
            if( damage < 0 ) damage = 0;
            busy_time = random(me->query_skill("sorsin_force")/20);
            delay_time = 15/(me->query_skill("sorsin_force")/20)+random(3);
            x = me->query_skill("sorsin_force")/5+te/4;
            if( x > 25 ) x = 25;
            //damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
            message_vision("\n\t"HIW"$N�@�ѧ@��I�N"HIB"���l"HIW"�@���ɤJ�C���A�ϥX�e���s�ޡy"HIC"���P�Ѿ�"HIW"�z\n\n"NOR,me,target);
            for(i=0;i<x;i++)
            {
                msg=sor_str[random(sizeof(sor_str))];
                message_vision(msg,me,target);
            }
            target->receive_damage("hp",damage,me);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")\n"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")\n"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")\n");
            COMBAT_D->report_status(target);
            target->start_busy(busy_time);
            me->start_busy(delay_time);
            me->receive_damage("ap",x*10,me);
            me->add_temp("nan",1);
            call_out("stop_delay",100/te,me);
        }
      me->receive_damage("mp",random(sk));
      me->receive_damage("ap",random(sk)+sk);

         return 1;
    }
}

void stop_delay(object me)
{
    if(!me) return;
    me->delete_temp("nan");
}
int improve_limite(object ob)
{
    return 100;
}

