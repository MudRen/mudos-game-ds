#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"����"NOR, ({ "mouse cookie" ,"cookie" }));
        set("long",@LONG
�o�O�@�ӭ����n�Y������A�ϥηs�A�����פΤ��\��³���s�Ӧ����A
�̬O���d�i�f�A�ΨӼy�����������~�A�乫�~�S�O���ʡC
LONG
        );
        set("weight", 10);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
          set("unit", "��");
          set("value", 100);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");

        message_vision("$N�j�f���Y�U$n�A�S�X�U�N�Y�������b�b�C\n" NOR,me, ob);
        switch(query("wish_type") ) {
        case "exp":
            me->add("exp", query("wish_amount"));
            break;
        case "pop":
            me->add("popularity", query("wish_amount"));
            break;
        case "art":
            me->add("war_art", query("wish_amount"));
            break;
        case "money":   // �̮e�����\
            me->add("bank/past", query("wish_amount"));
            break;
        }
        destruct(this_object());
        return 1;
}


