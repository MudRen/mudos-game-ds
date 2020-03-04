#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�򩳲`�B");
        set("long", @LONG
�o�O�¤Ѵ�̲`�B���a��A�|�P�@�����¡A�A���G�Pı��|�g�򪺤�
�y�D�`�ֳt�A�Ӧb�A���e�A���G���G�I�����b�����ۧA�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "up" : __DIR__"wa7.c",
        ]));

          set("objects",([
        __DIR__"npc/dragon":1,
        ]) );
        set("world", "past");
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

int room_effect(object me)
{
        if(!userp(me)) return 1;
        if(random(100) < 60) return 1;
        message_vision("�|�g�����y���M��t�a��F�_��.......�C\n",me);
        if(me->query_skill("dodge") < 50 || random(10) < 3 )
        {
                tell_object(me,HIC"�A�Q���y��o���Y��V�A�@�ɻ{���M��V...\n" NOR ); 
                me->add_busy(1);
        }
        return 1;
}

