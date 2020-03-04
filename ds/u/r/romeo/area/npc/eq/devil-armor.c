#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;

void create()
{
        set_name(HIB "�]�P�ۼv��" NOR,({ "devil-armor","armor" }) );
        set("long",
"�o�O�@���z�����ԥҡA�ڻ��O���l�ӥH�e�X�h���ԮɩҬ諸�ԥҡA\n"
"ť�����@�دS�O���\�ΡA���O�@�����O���K�A�èS���h�֤H���D�A\n"
"�b�ԥҪ��|�P�٦��@�������շϡA�����D������ΡC\n"
);
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",1600);
        set("replica_ob",__DIR__"devil-armor2");
        set("armor_prop/armor",40);
        set("armor_prop/dex", -2);
        }
        setup();
}

void init()
{
        add_action("do_suck","suck");
}

int do_suck(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();

        if(!arg || arg!="�]�P�ۼv��") return 0;
        if( !ob->query("equipped") ) return 0;
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S���Ű���L�ơC\n");
        if( me->query("hp") < 500 )
        {
        message_vision("$N�������l�J�]�P�ۼv�ҥ|�P���շϡC\n",me);
        tell_object(me,HIY"�Aı�o�q��κZ�C\n" NOR);
        me->receive_heal("hp",45);
        }
        else
        {
        message_vision("$N�������l�J�]�P�ۼv�ҥ|�P���շϡC\n",me);
        tell_object(me,"�A�l�J����ı�o�S���򤣦P�C\n");
        }
        return 1;
}

