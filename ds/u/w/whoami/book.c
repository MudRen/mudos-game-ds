#include <ansi.h>

inherit ITEM;

int do_learn(string arg);

void create()
{
        set_name(HIC"�ڤۦʬ����"NOR,({"encyclopaedia of DS","encyclopaedia"}) );
        set_weight(800);
        set("long",@long
�@�������ۦU���U�˧ޯ઺���y�A�A�i�H�n�n��s�@�f�E
(learn <skills name> )
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",0);
        }
        setup();
}
void init()
{
        add_action("do_learn","learn");
}

int do_learn(string arg)
{
        object me=this_player();
        if(!me->query_skill(arg)) 
                return notify_fail("�o�˧ޯ�A�٨S�ǹL��E\n");
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S�ž\\Ū���y�C\n");
        if(me->query_skill(arg) > 85)
                return notify_fail("�A���u"+arg+"�v�w�g��F�@�w���ԡA���ΦA�\\Ū�o���ѤF�C\n");

        message_vision(HIC "$N�ӲӾ\\Ū�F"+this_object()->query("name")+"���t�m��k�A���G��"+arg+"�S�h���m�@�ǤF�C\n" NOR,me);
        me->add_skill(arg);
        destruct(this_object());
return 1;
}
