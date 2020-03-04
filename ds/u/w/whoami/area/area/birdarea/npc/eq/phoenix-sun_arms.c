#include <armor.h>
#include <ansi2.h> 
inherit WRISTS; 
string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
        set_name(HIR"���"HIY"����"NOR"�u��",({ "phoenix-sun arms","arms" }) );
        set("long","�@��ĭ�æ�����ĤO�q�������E���M���ണ�ѧ��n�����ơA���O\n"
                   "�����k�O�i���O�L�H��ΡE\n");
        set_weight(4000);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("volume",3);
           set("material","steel");
           set("unit", "��" );
           set("value",700); 
         }
        set("armor_prop/int",2);
        set("armor_prop/wit",1);
        set("armor_prop/armor", 3); 
        set("armor_prop/shield", 25);
        set("times",3);  
        setup();  
        call_out("receive_by_arms", 5);
}

void receive_by_arms()
{

        object me = environment(this_object());
        int x, i;

        if( !this_object() || !me ) return;
        if( interactive(me)
         && me->query_temp("armor/wrists") == this_object()
         && me->is_fighting()
         && this_object()->query("times") > 0 )
        {
                x = me->query("max_hp"); 
                if( me->query("hp") < (x/20) )
                {
                message_vision(HIW"���M���A�@�Y������¶��"HIR"�P�K�����"HIW"�q$N"HIW"����«�ӥX�I�I\n"NOR
                               HIR"�e�Ψe�ۨ����O�q�ϧU�F�x�{���`��t��$n�K�K�K\n"NOR, this_object(), me);                tell_object(me,CYN"(�A���W�Ҧ����ˤf���b������¡�F�E)\n"NOR);
                        for(i=0;i<sizeof(wounds);i++)
                        me->receive_curing(wounds[i], 100);
                        me->receive_heal("hp", x); 
                        me->receive_heal("mp", me->query("max_mp"));
                        me->receive_heal("ap", me->query("max_ap"));
                        this_object()->add("times",-1);
                }  
        } else if ( this_object()->query("times") < 1 ) 
        {
          message_vision
          (HIY"���M���A�@�Y������¶��"HIR"�P�K�����"HIY"�q$N"HIY"����«�ӥX�A���۫K�����b���誺�ѪšI�I\n"NOR,this_object(),me);
          destruct(this_object());
        }
        call_out("receive_by_arms", 2);
}

