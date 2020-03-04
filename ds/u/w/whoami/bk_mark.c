#include <weapon.h>
#include <ansi2.h>
inherit ITEM; 
inherit SSERVER;
object ob;
void create()
{ 
        set_name("�s�L��U", ({ "soldier's note","note" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��"); 
                set("long", "�o�O�@�ڦ���̥��ƪ��Ȱw�A�P�ɤ]�O�ѱ��бв��̪��H���E��\n"
                            "�O���D�䤤���K���A�o�u���ֳ������ѱ��̤l�̡E\n");
//                set("no_drop", 1);
//                set("no_give", 1);
//                set("no_sac", 1);
                }
        setup();

}

void init()
{ 
           add_action("do_berserk","berserk");

}

int do_berserk(string str)
{
        object ob1,me,weapon,env,target;
        string st1,wp;
        int mydex,tdex,myint,tint,mylv,tlv,mysk,tdodge,mybar,bk,bk1,damage;

        me=this_player();
        weapon = me->query_temp("weapon");
        mysk=me->query_skill("berserk");
        myint=me->query("int");
        mydex=me->query("dex");
        mylv=me->query("level");
        mybar=me->query_Merits("bar"); 
        damage = me->query_temp("apply/damage");
        env = environment(me); 
        wp = weapon->query("skill_type"); 
        if( me->query_skill_mapped(wp) )
            return notify_fail("�A���������Ҧ����b�I�i���ޯ�~��ϥκƨg�����E\n");
        if( ob )
                if( environment(me) ) target = present(ob, environment(me));
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ƨg�����u���԰��������ϥΡC\n");

        if( env->query("no_fight") || env->query("no_cast") )
           return notify_fail("�o�̤���@�ԡT\n");
        if( me->is_busy() )
           return notify_fail("�A�{�b���b���A�L�k�ϥκƨg�����I\n"); 
        if(!weapon) 
        return notify_fail("�S�˳ƪZ���O����ϥκƨg�������E\n");
        if(weapon->query("skill_type")!="sword" && weapon->query("skill_type")!="blade" 
        && weapon->query("skill_type")!="axe" && weapon->query("skill_type")!="staff"
        && weapon->query("skill_type")!="hammer" && weapon->query("skill_type")!="fork") 
           return notify_fail("�A��W���Z���ä��A�X�ϥκƨg�����I\n");
        if( me->query("hp") < 300 || me->query("ap") < 300 || me->query("mp") < 300
           || me->query("wound/left_arm") > 10 || me->query("wound/right_arm") >10 )
           return notify_fail("�A�{�b���骬�p���εL�k�ϥκƨg�����E\n"); 
        if( me->query_temp("waiting_bk") )
           return notify_fail("�A�n���@�U�~��A�ϥκƨg�����E\n");

        if (!str || str=="") 
           return notify_fail ("berserk <�ؼ�>\n");
        if(sscanf( str,"%s",st1)!=1 )        
           return notify_fail("berserk <�ؼ�>\n");
        if (!ob=present(st1,environment(this_player())))
           return notify_fail("�䤣�� "+st1+" �o�ӥͪ�.\n");
        if(!ob->is_character() || ob->is_corpse()) 
           return notify_fail("�A�ݲM���@�I�A���ä��O�����C\n"); 
        if(!me->is_fighting(ob) && ob->query_temp("no_kill") < 1) me->kill_ob(ob);
        if(!ob->is_fighting(me) && ob->query_temp("no_kill") < 1) ob->kill_ob(me);

        message_vision(HIR"\n$N�@�n��q�A�j�ۡG�u��������I�v\n\n"NOR,me);
        me->set_temp("waiting_bk",1);
        if ( damage < mysk * (myint/20) ) {
        me->add_temp("apply/damage", mysk * (myint/20));
        me->add_temp("bk_damage", mysk * (myint/20));
        call_out("no_apply",1);

        }
        bk1=mysk/20+mydex/30-mybar/5;

         for (bk=0;bk<bk1;bk++)
         {
         COMBAT_D->do_attack(me,ob,me->query_temp("weapon"),4);
         COMBAT_D->report_statue(ob);
         if( weapon->query_temp("durable") > 10 && random(mysk/2) > myint)
         {
         weapon->add_temp("durable", -(mybar/3));         }
         weapon->attack();         }
        call_out("can_bk",7-mysk/20); 
        return 1;
}

void no_apply()
{
       object me;
       int bk;
       me=this_player();
       bk=me->query_temp("bk_damage");
       me->add_temp("apply/damage", -bk);  
       me->add_temp("bk_damage", -bk);
       return 0;
} 
void can_bk()
{
       object me;
       int bk;
       me=this_player();
       me->delete_temp("waiting_bk");
       return;

}

