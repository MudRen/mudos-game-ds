#include <ansi.h>
#include <weapon.h>  
inherit FORK; 
inherit F_UNIQUE;void create()
{
        set_name(HIB"�V�P��"HIR"��"NOR, ({ "chaos spear" , "spear" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "��");
                set("long", HIR"���]�ҫ������١A�y�U�L��A���F�ʷ|�l���P�򪺯�q�A�U���ޥ٤��̡C\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"evil-fist");
        }
        init_fork(65);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();

        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"$N�⤤"+this_object()->query("name")+HIW"�o�X�@�D�����A�����g�V$n�ÿE�g�X����A�l���P���q�C\n"NOR,me,victim);
//        message_vision(HIW"�@�}�t����"+ob->name(1)+"�g�X�A�l���P�򪺯�q�C\n"NOR ,me);
        tell_object(me,HIG "(�Aı�o�믫�n�F�@�I�F�I�I)\n" NOR);
        me->receive_heal("hp",30+random(10));  
        victim->receive_damage("hp",30+random(10)) ;
        return;
}


