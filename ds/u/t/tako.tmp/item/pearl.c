#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"�[��"HIW"��"NOR, ({ "liu lieh","lieh" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@���H�Ŧ⪺�p������,���S���@�ػ����X���z���P
     �A�b�]�ߪ��ɫJ�|���X�å��C\n");
                set("unit", "��");
                set("value",100);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}


