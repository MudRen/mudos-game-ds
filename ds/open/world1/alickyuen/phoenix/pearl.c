#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIY"���]���]��"NOR, ({ "star pearl", "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@���Ѷ��⪺�p�]�l�A�W�����@�ӡy���z���ϮסA�b�ߤW���ɫJ�|�o�X�{���C\n");
                set("unit", "��");
                set("value",100);
                set("check", 0);
                set("no_sac", 1);
        }
                set("phoenix", 1);
        setup();
}

void init()
{
        object me;
        me = environment(this_object());
        if( !me ) return;
        if( !userp(me) ) {
                add_action("do_get", "get");
                return;
        }
        if(!query_light()) start_light(1);

}
int do_get(string arg)
{
        if( arg!="pearl") return 0;
        if( this_player()->query_temp("quest/phoenix") )  return 0;
        write("���د��_�O�q�O�A�����_�o�ӪF��C\n");
        return 1;
}

void gone(object obj)
{
        if( !obj ) obj = this_object();
        if( environment(obj) )
                if( userp(environment(obj)) ) return;
        message_vision("$N�b�@�����ܦ����u�F ....\n\n", obj);
        destruct(obj);
        return;
}

