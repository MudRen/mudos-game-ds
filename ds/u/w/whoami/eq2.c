#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIY "����@�P��" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
�o�O�@���y���D�`�I�����䪺�@��A�o���@��W¸���@�T�u�����P�v
�����u�ϡA¸�u����A����o�T���Hø�s���ϵo����ɵ��ɬ��B�g���[��
���ҬɡA�u�i�׬O���ܤѤu�]�����L�C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",2500);
        }
        setup();
        call_out("eq_check",1);
}

void eq_check()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return; 
  if( me->query_temp("armor/hands")==this_object() 
   && me->query_temp("combine_eq") == 0){
      me->add_temp("combine_eq",1);
    }
}

