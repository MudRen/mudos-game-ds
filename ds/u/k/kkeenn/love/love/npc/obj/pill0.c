#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(MAG"�ܩʤ�"NOR, ({ "pill" }));
        set("long",
        "�ǻ����E�ѱۤk��d�b�H�����m�@�_���A�n�O�Z�H�Y��A�n���|�_�Y���ܤơC\n(�Х�use pill)\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        { 
                set("value",10000);
                set("unit", "��");
        }
        setup();
}
void init()
{
add_action("do_eat", "use");
}
int do_eat(string arg)
{
        object me ,obj;        me = this_player();
        obj = this_object();
        if( !arg )
        return notify_fail("�A�n�Yԣ �S\n");
        if (arg != obj->query("id")) return notify_fail("�A�n�Yԣ �S\n");
        if (me->query("class1") == "������" ) return notify_fail(HIW"�������O�G�Z�ڪ��U�A�@�ߤ���Y�����C\n"NOR);
        if (me->query("class1") == "�ⶳ�x" ) return notify_fail(HIW"�����V�Τd���ǭ���A���G��������A�p�G�z�Y�U�����A���Ǫ��v�{�t���N�������C\n"NOR);
	if( me->query("marry_id") ) return notify_fail("���F�B�ܩ�?�n�ߩd��l��??\n");
        if (me->query("gender") == "�k��")
        {
        me->set("gender","�k��");
        }
       else
        {
        me->set("gender","�k��");
        }           message_vision(HIW"$N�@�f�]�U�F$n�A$N������W�n���_�F�Y���ܤ�...\n"NOR,me,obj);
	me->unconcious();
        destruct(obj);
        return 1;
       }

