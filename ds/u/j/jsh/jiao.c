inherit ITEM;
#include <ansi.h>
void setup()
{}
void init()
{
        add_action("do_enter", "enter");
}
void create()
{
        set_name(HIB"����"NOR, ({"blue jiao","jiao"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@���Ŧ⪺��l�A�n���O�`�K�M������C\n");
                set("unit", "��");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_drop", 1);
                set("no_put", 1);
        }
        setup();
}
int do_enter(string arg)
{
        object room, me = this_player();
        if( !arg || arg!="jiao" ) return 0;
        message_vision(HIR"$N�@�i����̴N�Q��ı . . . �|�P���H���G���S�ܡA�i��O�ۤv�Ω��F�a�C\n\n"NOR, me ) ; 
        message_vision(HIC"�@���W�n�n�̮� . . . . \n\n"NOR, me ) ;        if( !(room = find_object(__DIR__"jiao")) )
            room = load_object(__DIR__"jiao");
        if( room = find_object(__DIR__"jiao") ) 
        me->move(room);
        message("vision", me->name() + "�A�ݨ�@�ӤH�q�~�����F�i�ӡC\n\n",
                environment(me), ({me}) );
        call_out("reach", 20, me);
        return 1;
}       

void reach(object me)
{
        tell_object(me, "��l��M�y�F�@�U . . . ���F�U�ӡA�M�ᦳ�H��: ��F�A����C\n");
        me->move("/open/world1/tmr/area/street4");
}


