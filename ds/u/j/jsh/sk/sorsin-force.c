//��������n��C���٭�,�Q�Q�٬O���n�n�F,�o�ۺ�j���F
#include <ansi.h>
#define SKILL_NAME "���P���q"
inherit SKILL;
inherit SSERVER;

int exert(object me, object target,string arg)
{
        string msg;
        int damage,sk,c;
        object weapon,wp;
        if(!me) return 0;
    //    if(me->is_fighting())
    //          return notify_fail(SKILL_NAME+"�O�@�ؾ԰��ޯ�I[�{�b�\\�঳ ��l�C(exert sorsin-force apsword)]\n"); 
        if( arg == "apsword" )
        {
                if( me->query_temp("apsword") )
                     return notify_fail(""+SKILL_NAME+"�@���u��ϥX�@���l�C�I\n");  
                wp = new("/u/j/jangshow/sword");
                wp->move(me); 
                {
                message_vision(HIC"$N�B�_�ߪk�A���|�j�ޮ�����x���A�������E���@��"HIW"��l�C"HIC"�C\n"NOR, me);
                me->start_busy(3);
                me->receive_damage("ap", 100+random(me->query_skill("sorsin-force")/2)); 
                //���I��100,sorsin�U��,���U�h
                me->set_temp("apsword",1); 
                call_out("de_apsword",300,me); // 5����  
                }
                return 1;
          }
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�n��֨ϥX"+SKILL_NAME+"?\n");        
        if((int)me->query("mp") < 20 || (int)me->query("ap") < 50)
                return notify_fail("�A�ثe�����骬�p�L�k�ϥγo��@�P���Z�\\�T\n");
        if(!weapon=me->query_temp("weapon")) return notify_fail("�A�⤤�S���Z���C\n");
        if(weapon->query("skill_type")!="sword") 
                return notify_fail("�ϥ�"+SKILL_NAME+"�����n���C�C\n");
        if(me->query_skill("sword")<100) 
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ�C�k��¦�C\n"); 
        if(me->query_skill("dodge")<100)
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ�{����¦�C\n");
        if(me->query_skill("sorgi_sword")<100)
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ���e�C�k�C\n");
        if(me->query_skill("sevenstar-sword")<100)
                return notify_fail("�ϥ�"+SKILL_NAME+"���D������ꪺ���P�C�q�C\n");
        if(me->query_skill("moon_force")<100)
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ�ݤ�ߪk�C\n");
        if(me->query_skill("force")<100)
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ���\\�ߪk�C\n"); 
        if(me->query_dex() <60)  
                return notify_fail("�ϥ�"+SKILL_NAME+"���n������ꪺ�ӱ��޳N [60]�C\n");
        if( me->query_temp("nan") )
                                return notify_fail("�A�u�ɶ�������ϥ�"+SKILL_NAME+"�I\n");  
        sk=me->query_skill("sorsin-force");
        c=target->query_armor();
        message_vision("\n"HIW"$N�H"HIC"�l"HIW"�Ʈ�A�H��m"HIC"�C"HIW"�A��󲴫e�A���_������ߩ�"HIC"��"HIW"�C�E�E�E\n"NOR,me,target);
        me->receive_damage("mp",100);
        me->receive_damage("ap", 300);
        me->add_busy(3);
        if( random(me->query_dex()*4) < random(target->query_dex()+target->query_skill("dodge")))
        {
        message_vision("\n"HIW""+target->name()+"���o��H�I���F$N���ۦ��C\n"NOR,me,target);        
                return 1;
        }
        else
        {
                damage = me->query_damage()*3+sk*10+me->query_dex()*2-c/3;
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                message_vision(HIG"\n\t�C���@�_�I\n"
                    HIB"\t\t�y"HIC"�ݤ뤧���E�۷��e��"HIB"�z\n"
                    HIW"\t\t�@�ѼC�𱽿��b"+target->name()+"���P��I�|���Ů�����@�T�I\n"
                    HIC"\t\t�ѯe�P�}"HIW"�ܼC�ӥX�I�ʹD�C��E�E�Ѱ}�ɤJ�E�E\n"
                    HIR"\t\t�A��s�z�E�E"+target->name()+"�i���E�E\n"NOR,me,target); 
                target->kill_me(environment(this_player()));
                target->receive_damage("hp", damage,me);
                target->add_busy(3);
                COMBAT_D->report_status(target);
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack();
                if(wizardp(target) && target->query("env/debug")) tell_object(target,"["+me->name()+"����: "+damage+"�I���ˮ`]\n");
                me->set_temp("nan",1);
                call_out("stop_delay",60,me); // �@����
        }
        

        return 1;
} 
void de_apsword(object me)
{ 
    //    object wpp,me;  
    //    me=this_player();
        object wpp;
        if( !me) return;
        if( objectp(wpp = present("ap sword", me)) )
        { 
          message_vision(HIW"\n$N���W����l�C�����]���I\n"NOR,wpp); 
                        destruct(wpp); 
          me->delete_temp("apsword"); 
        }
        return;
}
void stop_delay(object me)
{
        if( !me ) return;
        me->delete_temp("nan");
}
int improve_limite(object ob)
{
        return 100;
}

