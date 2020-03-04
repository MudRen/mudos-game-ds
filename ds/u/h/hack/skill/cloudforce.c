/* �V���󤺥\�G�����ߪk(cloudforce) �� Linjack ��� Cominging �� Moon_force �� 7/24 */
//QC: Luky (�o���ɮצ��I���L����..�i�঳�ҿ�|)
#include <ansi.h>
inherit SKILL;
void delay(object me);
int exert(object me,object target, string arg)
{
        int heal,reheal,sk,lv,shield,ap,downsh;
        if( arg=="off" )
        {
                if( me->query_skill_mapped("force")!="cloudforce" )
                        return notify_fail("�A�èS���b�m�߾����ߪk�C\n");
                me->delete_temp("is_busy/cloudforce");
                message_vision(HIC"\n$N�𾮤��F�A���h�����G�ߤ���A����׽m�����ߪk�C\n"NOR,me);
                me->map_skill("force");
                return 1;
        }
        if( arg=="refresh" )
        {
                if( me->is_ghost() )
                        return notify_fail("\n�A�{�b�i�O���r�I�����B�����ڡH\n");
                if( me->is_fighting() )
                        return notify_fail("\n�u�q�اA���i��A�������î𪺩Ǫ��C\n");
                if( me->is_busy() )
                        return notify_fail("\n�����A�������䪺�ƦA���a�C\n");
                if( me->query_skill_mapped("force")=="cloudforce" )
                        return notify_fail("\n�A���b�׷� (�Ψϥ�) �����ߪk������C\n");        
                if( me->query("mp") < 50 )
                        return notify_fail("\n�ѥS�A�A�w�g�S���������믫�O�F�a�C\n");
                if( me->query("ap") >= me->query("max_ap") )
                        return notify_fail("\n�ѥS�A�A�ө_�ǤF�a�A���O�����F����B����������H\n");
                if( me->query_skill("cloudforce") < 10 )
                        return notify_fail("\n�A�������ߪk�ک������A�L�k�N�믫�O�ର���O��C\n");
                heal= (int)me->query("max_ap");
                sk = (int)me->query_skill("cloudforce");
                lv = (int)me->query("level");
                if ( sk > 40 ) sk = 40 + ((sk-40)/2);
                reheal = (heal / 15) + (sk/2) + random(5) + (lv/2);
                me->receive_heal("ap",(reheal*3/4));
                me->receive_damage("mp",25 + random(6));
                me->start_busy(3);
                message_vision(HIY"\n$N���侮�E�@�ѲH�H����A�M��Q$N���X�鵹�l���F�C\n"NOR,me);
                me->improve_skill("cloudforce",1+random(me->query("level"))+me->query_int()/4 );
                me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                return 1;
        }
        if( arg=="shield" )
        {
                if( me->query_temp("skill/cloudshield") > 0 )
                {
                        if( me->is_ghost() )
                                return notify_fail("\n�A�{�b�i�O���r�I���ϥΡy�G��������z���@���H\n");
                        if( me->is_fighting() )
                                return notify_fail("\n�԰����A�S���خɶ��B�𪺰աC\n");
                        if( me->is_busy() )
                                return notify_fail("\n�����A�������䪺�ƦA���a�C\n");
                        if( me->query_skill_mapped("force")=="cloudforce" )
                                return notify_fail("\n�A���b�׷� (�Ψϥ�) �����ߪk������C\n"); 
                        if( me->query_temp("skill/cloudshield") > 1 )
                                return notify_fail("\n�A�H���A�h�j�ڡA�Q�n�B��ĤT���y������z�H\n");       
                        if( me->query("ap") < 550 )
                                return notify_fail("\n�A�����O�����H�ϥβĤG�����y������z�C\n");
                        if( me->query_skill("cloudforce") < 80 )
                                return notify_fail("\n�A�������ߪk�ڰ��٤����H�ϥβĤG���y������z�C\n");
                        if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3) &&
                            me->is_busy() )
                                return notify_fail("\n���O�����A���@�U�|���ڡH�C\n");
                        sk = (int)me->query_skill("cloudforce");
                        ap = (int)me->query("ap");
                        if ( sk > 80 ) sk = 80 + ((sk-80)*2);
                        if ( ap > 1000 ) ap = 1000 + ((ap-1000)/8);
                        shield = (sk/10) + (ap/80);
                        if ( shield > 30 ) shield = 30 + ((shield-30)/3);
                        me->add_temp("apply/armor",shield);
                        me->add_temp("apply/shield",shield/2);
                        me->receive_damage("ap",400+(shield*4));
                        me->start_busy(4);
                        me->add_temp("skill/cloudshield", 1);
                        me->add_temp("skill/shieldarmor",shield);
                        message_vision(HIC"\n$N�|�P���E�F�@�ѥb�z��������A�O�Q���`�p���@����l�C\n"NOR,me);
                me->improve_skill("cloudforce",1+random(me->query("level"))+me->query_int()/4 );
                me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                        return 1;
                }
                if( me->is_ghost() )
                        return notify_fail("\n�A�{�b�i�O���r�I���ϥΡy������z���@���H\n");
                if( me->is_fighting() )
                        return notify_fail("\n�԰����A�S���خɶ��B�𪺰աC\n");
                if( me->is_busy() )
                        return notify_fail("\n�����A�������䪺�ƦA���a�C\n");
                if( me->query_skill_mapped("force")=="cloudforce" )
                        return notify_fail("\n�A���b�׷� (�Ψϥ�) �����ߪk������C\n");        
                if( me->query("ap") < 50 )
                        return notify_fail("\n�A�����O�����H�ϥΡy������z��C\n");
                if( me->query_skill("cloudforce") < 25 )
                        return notify_fail("\n�A�������ߪk�ڰ��٤����H�ϥΡy������z�C\n");
                if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3) && 
                    me->is_busy() )
                        return notify_fail("\n���O�����A���@�U�|���ڡH\n");
                sk = (int)me->query_skill("cloudforce");
                ap = (int)me->query("ap");
                if ( sk > 60 ) sk = 60 + ((sk-60)/2);
                if ( ap > 500 ) ap = 500 + ((ap-500)/10);
                shield = (sk/12) + (ap/90);
                if ( shield > 13 ) shield = 13 + ((shield-13)/2);
                me->add_temp("apply/armor",shield);
                me->add_temp("apply/shield",shield/2);
                me->receive_damage("ap",30+random(11));
                me->start_busy(3);
                me->add_temp("skill/cloudshield", 1);
                me->add_temp("skill/shieldarmor",shield);
                message_vision(HIC"\n$N���W�o�X�F�@�D���l��¶��$N���|�P�C\n"NOR,me);
                me->improve_skill("cloudforce",1+random(me->query("level"))+me->query_int()/4 );
                me->improve_skill("force",1+random(5+me->query("level"))+me->query_int()/4 );
                return 1;
        }
        if( arg=="shield_off" )
        {
		if( !me->query_temp("skill/cloudshield") )
			return notify_fail("\n�A�èS���ϥΡy������z�@���C\n");
                downsh=(int)me->query_temp("skill/shieldarmor");
		message_vision(HIB"\n$N���Ǫ���C�C���������F�C\n"NOR,me);
		me->delete_temp("skill/cloudshield");
                me->delete_temp("skill/shieldarmor");
                me->delete_temp("skill/shieldtime");
		me->start_busy(2);
		me->add_temp("apply/armor",-(downsh));
                me->add_temp("apply/shield",-(downsh/2));
		return 1;
	}
        if( me->is_fighting() )
                return notify_fail("\n�u�q�اA���i��A���Ƚm�\\�m��î𪺩Ǫ��C\n");
        if( me->query_temp("skill/cloudshield") )
                return notify_fail("\n�A�S����k�@�������y������z�@���׽m�����ߪk�C\n");
        if( me->query_skill_mapped("force")=="cloudforce" )
                return notify_fail("\n�A���b�׷� (�Ψϥ�) �����ߪk������C\n");
        if( me->query("hp") < 30 || me->query("ap") < 40 || me->query("mp") < 20 )
                return notify_fail("\n�A�u�R�����A�o�ب��骬�p���m�\\�ڡC\n");
        if(!me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3))
          return notify_fail("\n�A�m�\\���ʧ@�٨S�����C\n");
        
        return notify_fail("\n�{�b�������o��Idle skill, �h��Ѯv�ǧa�C\n"); // �o��Idle skill. Luky
        
        message_vision(HIB"\n$N�L�_���}�A�R����a�A������¶����A�}�l�׽m�����ߪk�C\n"NOR,me);
        me->map_skill("force","cloudforce");
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2+random(2));
        me->receive_damage("mp", 1+random(2));
        me->set_temp("is_busy/cloudforce","�A���b�׽m�����ߪk�A�L�k���ʡC");
        me->start_busy(4);
        return 1;
}
void delay(object me)
{
        int sk_level,lv,i,shdown;
        lv = me->query("level");
        i = me->query_int();
        if( !me ) return;
        if( me->query_temp("skill/cloudshield") )
        {
                shdown = (int)me->query_temp("skill/shieldarmor");
                if( me->query("ap") < 20 )
                {
                        message_vision(CYN"\n$N�����骬�p�Ӯt, �@����l�C�C�����F�C\n"NOR,me);
                        me->delete_temp("skill/cloudshield");
                        me->delete_temp("skill/shieldarmor");
                        me->delete_temp("skill/shieldtime");
                        me->add_temp("apply/armor",-(shdown));
                        me->add_temp("apply/shield",-(shdown/2));
                }
                if( me->query_temp("skill/shieldtime") > 100 )
                {
                        message_vision(HIB"\n$N�r�M�@�I��A�@����l�w�g�����F�C\n"NOR,me);
                        me->delete_temp("skill/cloudshield");
                        me->delete_temp("skill/shieldarmor");
                        me->delete_temp("skill/shieldtime");
                        me->add_temp("apply/armor",-(shdown));
                        me->add_temp("apply/shield",-(shdown/2));
                }
                me->add_temp("skill/shieldtime", 1);
                me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3);
        }
        if( me->query_skill_mapped("force")!="cloudforce" ) return;
        if( me->query("ap") < 20 || me->query("hp") < 30 || me->query("mp") < 40 )
        {
                message_vision(CYN"\n$N�`�l�F�@�f��A�L�O�����_�ӡA�L�k�A�N�����ߪk�m�U�h�F�C\n"NOR,me);
                me->delete_temp("is_busy/cloudforce");
                me->map_skill("force");
                return;
        }
	me->receive_damage("ap",7);
        me->receive_damage("hp",3+random(2));
        me->receive_damage("mp",2+random(2));
        me->improve_skill("force",random((1+random(lv)+random(i))/8) + (lv/15) + (i/10));
        me->improve_skill("cloudforce",random((1+random(lv)+random(i))/9) + (lv/10) + (i/9));
 	me->skill_active( "cloudforce",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b;
        b=me->query_skill("cloudforce");
        if( b == 81 && !me->query("skill/cloudforce") )
        {
                tell_object(me, HIY"\n�A�������ߪk�į}�j���F�I\n"NOR);
                me->add("addition/con", 1);
                tell_object(me, HIC"�A�����W�ɤF�I\n"NOR);
                me->set("skill/cloudforce", 1);
        }
        me->save();
}
int improve_limite(object ob)
{
        int a,b;
        b=ob->query_skill("force");
        a=((ob->query("level") + ob->query_int())*2)-9;
        if( ob->query("adv_class")==2 ) a=95;
        else if(a > 80) a=80;
        else if(a >= b) a=b;
        return a; 
}
