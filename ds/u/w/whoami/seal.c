#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ʦL��",({"sealed seal","seal"}) );
        set("long",@LONG
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�i");
                set("value",500);
        }
        setup();
}

void init()
{
        add_action("do_charm","charm");
}

int do_charm(string str)
{
        object me,ob,ob1;

        me=this_player();

        if( !str ) return notify_fail("charm <�ؼ�>\n");
        if( !objectp(ob = present(str, environment(me))) )
           return notify_fail("�o�̨S���o�˪F��C\n");
        if(!ob->is_character() || ob->is_corpse()) 
           return notify_fail("�A�ݲM���@�I�A���ä��O�����C\n"); 

        tell_object(me,"�ʹʡB"+ob->query("name")+"�Q�ʩۤF�I\n");
        ob1=new(__DIR__"noexert");
        ob1->move(ob);
        destruct(this_object());
        return 1;
}

