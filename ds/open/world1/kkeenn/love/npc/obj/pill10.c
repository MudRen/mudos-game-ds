#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"�\\�L�����Y"NOR, ({ "pill" }));
        set("long",
"�o�O��F���s�q���x�ХD�ҷҤ����ġA���ۼW�j�\\�O���_���ĪG�A���O\nť���s�Ыq�{�ҶD�A���Ī��Ƨ@�Τ]�ܥi�ȡA�@��в����q�ӻ����E(swallow pill)"
        );
        set_weight(1500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        { 
                set("value",8000);
                set("unit", "��");
        }
        setup();
}
void init()
{
add_action("do_eat", "swallow");
}
int do_eat(string arg)
{
        object me ,obj;
        me = this_player();
        obj = this_object();
        if( !arg )
        return notify_fail("�A�n�Yԣ �S\n");
     if(obj->query("no_eat"))  return 0;
        if (arg != obj->query("id")) return notify_fail("�A�n�Yԣ �S\n");
        me->add_temp("apply/str",5);
        me->add_temp("apply/con",5);
        me->add_temp("apply/int",5);
        me->add_temp("apply/dex",5);
       message_vision(HIR"$N�@�f��N$n���L�ڸ̡A$N�z�q�@�n�A�����g�߬�_�I\n"NOR,me,obj); 
        call_out("poison",180,me,obj);
        obj->set("no_eat",1);
        if( !obj->query("no_eat") ) return 1;
        else { obj->set_temp("invis",1);
               obj->set("no_sell",1);
               obj->set("no_give",1);
               obj->set("no_drop",1);
               obj->set("no_get",1);
               obj->set("no_sac",1);
               }
        return 1;
}
void poison(object me,object obj)
{
if(!me) return; 
message_vision(HIW"$N�ҪA��"YEL"�\\�L�����Y"HIW"���ĮĺC�C�h�h�F�A$N���y���M�ܦ��C�⪺�H\n"NOR,me);
 me->apply_condition("poison", me->query_condition("poison")+ (me->query_skill("combat")+random(me->query("con"))) );
 me->add_temp("apply/str",-5);   
 me->add_temp("apply/con",-5);   
  me->add_temp("apply/int",-5);   
  me->add_temp("apply/dex",-5);   
    destruct(obj);
return;
}


