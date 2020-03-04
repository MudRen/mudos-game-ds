/* �e���� �G �ݤ�ߪk(moon_force) �� Cominging �� 1999/5/29 ��ҳ� */

#include <ansi.h>
inherit SKILL;
void delay(object me);

int exert(object me,object target, string arg)
{
        int heal,reheal,sk,lv,times;
        
        if( arg=="off" )
        {
                if( me->query_skill_mapped("force")!="moon_force" )
                        return notify_fail("�A�èS���b�B�\\�C\n");
                me->delete_temp("is_busy/moon_force");
                message_vision(HIY"$N���_���Ⲵ�C�C�C�}�A�����S�y�^�g�ߤ��F�C\n"NOR,me);
                me->map_skill("force");
                return 1;
        }
        if( arg=="recover" )
        {
        	if( me->query("ap") < 20 )
                	return notify_fail("�A�ثe�����p���ΡA�L�k�ϥδݤ�ߪk�C\n");
                if( me->query_skill("moon_force") < 10 )
                        return notify_fail("�A���ݤ�ߪk��¦�����I\n");
                heal= (int)me->query("max_hp");
        	if( me->query("hp") >= heal )
                	return notify_fail("�A�ثe���ͩR���p�w�g�O�����F�C\n");
		if(heal>4000) heal = 4000 + ((heal-4000)/8);
                sk = (int)me->query_skill("moon_force");
                lv = (int)me->query("level");
                if ( sk > 50 ) sk = 50 + ((sk-50)/2);
                reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);
                me->receive_heal("hp",reheal);
                me->receive_damage("ap",27 + reheal/7 + random(4));
                me->start_busy(2);
                message_vision(HIR"$N�@�ɶ��R�U�ߨӡA�B���I�F���W�U�ˤf�Ǫ��j�ޡC\n"NOR,me);
                return 1;
        }
	if( arg=="addtimes" )
	{
		if( me->is_busy() )
			return notify_fail("�A���b���C\n");
		if( me->is_ghost() )
			return notify_fail("�A�O����C\n");
		if( me->query("ap") < 80 )
			return notify_fail("�A�����O�����A�L�k�N���O�e���u�W�C\n");
		if( me->query("dex") < 15 || me->query_skill("fogseven") < 50 )
			return notify_fail("�A�������٤����ӱ��C\n");
		if( me->query_skill("moon_force") < 40 )
			return notify_fail("�A���ݤ�ߪk�٤������m�C\n");
		times = me->query("max_ap")/150;
		if(times>10) times=10;
		if(times<1) times=1;
		if( me->query_temp("sorgitimes") >= 3+times )
			return notify_fail("�A�����u�w�g�L�k�A�Ө���j�����O�F�C\n");
		message_vision(HIW"$N���u�L�LŸ�ʡA��M���@�ѥ\\�O�Q���E�b���u���W�C\n"NOR,me);
		if(!me->query_temp("sorgitimes")) me->set_temp("sorgitimes",me->query_skill("moon_force")/22);
		else if((3+times)-me->query_temp("sorgitimes") < me->query_skill("moon_force")/22)
			me->add_temp("sorgitimes",(3+times)-me->query_temp("sorgitimes"));
		else me->add_temp("sorgitimes",me->query_skill("moon_force")/22);
		if((times-3)<1) times=1;
		if((times-3)>5) times=5;
		me->receive_damage("ap",(30*(me->query_skill("moon_force")/22))-random(me->query_skill("moon_force")/2));
		me->start_busy(1+random(2));
		return 1;
	}
        if( me->is_ghost() )
                return notify_fail("�A�@����W�ӡA���G�]���|�Ϧ��b����ҵL�A�]�ӥ��ѤF�I\n");
        if( me->is_busy() )
                return notify_fail("�A�{�b���b���O���ơA����A�i�H�@�ߦh�ΡH\n");
        if( me->is_fighting() )
                return notify_fail("�A�{�b�����ۥ��[, �S�Žm�\\�C\n");
        if( me->query_skill_mapped("force")=="moon_force" )
                return notify_fail("�A�{�b�٦b�׷Ҵݤ�ߪk���C\n");
        if( me->query("hp") < 20 || me->query("ap") < 20 )
                return notify_fail("�A�ثe�����p���ΡA�L�k�׷Ҥߪk�C\n");
        
        if(!me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3))
          return notify_fail("�A�����B�\\���ʧ@�٨S�����C\n");


        message_vision(HIC"$N�H�a�L�}���U�A��B���e�A�E�Ȥ��Ӿi���C\n"NOR,me);
        me->map_skill("force","moon_force");

        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2);
        me->set_temp("is_busy/moon_force","�A���b���i�����A�Ȯɤ��ಾ�ʡC");
        me->start_busy(2);
	//me->start_call_out( (: call_other, __FILE__, "delay", me :), 2);
        return 1;
}

void delay(object me)
{
        int sk_level,lv,i;
        
        sk_level = me->query_skill("moon_force");
        lv = me->query("level");
        i = me->query_int();

        if( !me ) return;

        if( me->query_skill_mapped("force")!="moon_force" )return;

        if( me->query("ap") < 13 || me->query("hp") < 13 )
        {
                message_vision(HIR"$N�߯��p�@�D�����L�A£�M����F�B�\\�C\n"NOR,me);
                me->delete_temp("is_busy/moon_force");
                me->map_skill("force");
                return;
        }
	else
        if ( sk_level < 50 )
        {
                me->receive_damage("ap",8);
                me->receive_damage("hp",5);
        }
        else
        if ( sk_level > 49 )
        {
                me->receive_damage("ap",12);
                me->receive_damage("hp",7);
        }
        me->improve_skill("force",1+random(2)+random(1+lv/3));
        me->improve_skill("moon_force",1+random(3)+random(1+lv/3));
 	//me->start_call_out( (: call_other, __FILE__, "delay", me  :), 3);
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

void skill_improved(object me)
{
        int b,c;
        b = me->query_skill("moon_force",1);
	c = me->query("skill/moon_force");//luky
	
        if( b % 20==19 && b > c)
        {
                tell_object(me, HIR "�A���ӱ��M���ѩ�⮩�ݤ�ߪk���D�A�]�ӤW�ɤF�C\n" NOR);
                me->add("addition/dex", 1);
                me->add("addition/con", 1);
                me->set("skill/moon_force",b);
        }
        me->save();
}
int improve_limite(object ob)
{
        int a;
        a=(ob->query("level")*3)+(ob->query_int()/2);
        if(a > 90 && ob->query("level")<26 ) a=90;
        else if(a>100) a =100;
        return a; 
}
