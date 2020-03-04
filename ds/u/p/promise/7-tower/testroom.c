#include <ansi.h>
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance"

inherit ROOM;

int doll_check(object me);

void create()
{
        set("short", "MOB���հϰ�X�f");
        set("long", @long
�o�̬O���եX�h���X�f�ݤJ�f�A�Z�O�n�i�J�ΥX�h�A���o�q���X
�i�X�C�n���}�Х�"out"�A�n�������մ����������ܡA�Щ������p��
�U�������C
long);
        set("light", 1);
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_cast", 1);
        set("objects", ([
                __DIR__"doller" : 1,
        ]));
   set("exits", ([ /* sizeof() == 2 */
  "out" : "/open/world1/tmr/area/hotel",  "east" : "/u/p/promise/testroom1",
])); 
        setup();
}

void init()
{
        object me = this_player();

        if( !me ) return;

        add_action("doll_check", "out");

                return;

        doll_check(me);
}

int doll_check(object me)
{
        object doll;
        me = this_player();
        message_vision(HIW"�����p���U���b�ˬd$N���W���S�����եΪ���������.....\n"NOR, me);
        if( objectp(doll = present("test doll", me) ) )
        {
                message_vision(HIW"�����p���U��"+me->query("name")+"���W��"NOR+doll->query("name")+HIW"�����F�C\n"NOR, me);
                destruct(doll);
        } 
        else
        } 
                message_vision(HIR+me->query("name")+"���W�S����F��A��M���Q�����p���U��X�h�F�C\n"NOR, me);
                me->move("/open/world1/tmr/area/hotel");
        } 
        return 1;
}

