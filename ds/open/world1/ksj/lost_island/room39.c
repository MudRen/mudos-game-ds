#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"CYN"�ªh�a"NOR);
        set("long", @LONG
�o�̬O�@�����R�`�ª��h�a�A�a���W�o�󤣥͡A�u���@�Ӧa�}�A
���b�a���W�Pı�n�n�B�B���A�ܬO�_�S�A�a���n�����ɪ��b�_��A�]
�\�u�O��ı�C
LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"room36",
            "northeast" : __DIR__"room40",
            "west" : __DIR__"room41",
            "southwest" : __DIR__"room38",
            "northwest" : __DIR__"room42",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        set("objects",([
           __DIR__"hole":1,
           ]) );
        setup();
}

int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         case 1:
         case 2:

                message_vision("�A�����}���C�C���J�d�h���D�D�D�C\n",me);
                if(me->query_skill("dodge")< 35 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(5);
                }

                else if(me->query_skill("dodge")< 70 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(3);
                }

                else if(me->query_skill("dodge")>69 && random(10)<3 )
                {
                        tell_object(me,YEL"���A�o�{�ɡA�w�`����d�h�A�@�ɰʼu���o�I�I\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}

