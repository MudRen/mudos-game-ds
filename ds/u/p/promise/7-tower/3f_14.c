#include <ansi.h>
inherit ROOM;

string *exitss = ({
__DIR__"3f_1",__DIR__"3f_2",__DIR__"3f_3",__DIR__"3f_4",__DIR__"3f_5",
__DIR__"3f_6",__DIR__"3f_7",__DIR__"3f_8",__DIR__"3f_9",__DIR__"3f_10",
__DIR__"3f_11",__DIR__"3f_12",__DIR__"3f_13",});

void create()
{
        set("short", HIY"�F�s�g��"NOR);
        set("long", 
"�o�O�@�B���L���}�ΡA���Y�@�ǳ�ժ��\\�]�A�b�Ǧ��ǳ\\�����A
�ݨC�L�����W�����\\�h���ǹСA�����D�n���n�����������b�C
"); 
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"statue" : 1,
        ]));
       set("light",1);
       set("exits", ([ 
                "south" : exitss[random(sizeof(exitss))],
]));
        setup();
}

