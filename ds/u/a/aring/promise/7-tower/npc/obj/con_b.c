#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��褧��",({"con of book","book"}) );
        set_weight(80);
        set("long",@long
�W�[�g�窺���y�A�Х�(read book)�ӼW�[�O�q�C
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
        add_action("do_read","read");
}

int do_read(string arg)
{
        object me=this_player();
        if(arg!="book") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S�ž\\Ū���y�C\n");
        message_vision(HIG "$N�M�ߪ��\\Ū��褧�ѡA�W�[�F�������C\n" NOR,me);
               me->add("con",1);
        destruct(this_object());
return 1;
}
