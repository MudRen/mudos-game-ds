#include <ansi.h>
inherit ITEM;
int do_load(string arg);
void create()
{
        set_name("�ޥ�����-�ꭷ�N�ޥ�",({"summon_wind ic","ic"}) );
        set_weight(80);
        set("long",@long
�o�O�@�������A�W�Y�O���ۡu�ꭷ�N�v���Ϊk�C(load ic)
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
        add_action("do_load","load");
}

int do_load(string arg)
{
        object me=this_player();
        if(arg!="ic") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S�Ÿ��J�����C\n");
        if( query("do_load") )
                return notify_fail("�o�����w�g�Q�ϥΤF�A�A�L�k�A��Ū���C\n");
        if(me->query_spell("summon_wind") > 60)
                return notify_fail("�A���u�ꭷ�N�v�w�g���m�h�F�A�����w�g��A�S�ΤF�C\n");
        message_vision(HIC "$N���J�F�����W���ޥ��A���G�⮩��@�اޥ��C\n" NOR,me);
        me->add_spell("summon_wind");
        set("do_load",1);
return 1;
}

