#include <ansi.h>
inherit __DIR__"desert";

string *exitss = ({
__DIR__"3f_1", __DIR__"3f_2", __DIR__"3f_3", __DIR__"3f_4", __DIR__"3f_5", __DIR__"3f_6",
__DIR__"3f_7", __DIR__"3f_8", __DIR__"3f_9",__DIR__"3f_10", __DIR__"3f_11",__DIR__"3f_12", __DIR__"3f_13",});

void create()
{
        set("short", RED"�C���� "YEL"�i�g�����}�j"NOR);
        set("long", (: ROOM_LONG :),);
        set("objects", ([
        __DIR__"npc/rock2" : random(2)+1,
]));
        set("exits", ([ 
        "west" : exitss[random(sizeof(exitss))],
        "east" : exitss[random(sizeof(exitss))],
        "north" : exitss[random(sizeof(exitss))],
        "south" : exitss[random(sizeof(exitss))],
]));
        setup();
}
 int room_effect(object me)
{
        switch(random(2))
        {


         case 0:
         write(HIY"�u�u�F�ЫIŧ�A�Ө�....\n"NOR);
         tell_object(me, HIW"�A��C�F��..�C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIY"�ż��������l���F�A����O... \n"NOR);
         tell_object(me, HIB "�A���G���ǲ��...�C\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;

        }
}


