#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("�I���ոɥR", ({ "test receive", "test","cloth","receive" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("west",1);
                set("value",8000);
                set("base_unit", "��");
                set("unit", "��");
        }
        setup();
}

void init()
{
        call_out( "heart_beat" ,1,this_player());
}

void heart_beat(object me)
{
        if( me->is_fighting() )
        {
                message_vision(HIG"$n�o�X�}�}���{���A$N���W���ˤf�������ƦX�F�_�ӡC\n"NOR,me,this_object());
                this_player()->receive_heal("hp",random(5)+1);
        }
        call_out("heart_beat", 5+random(10),me);
        return;
}

