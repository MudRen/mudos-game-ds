#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS���ήɪź޲z�B�q�D"NOR);
        set ("long", @LONG
�o�̥|�P�@�����I�A��������ť��������@�T�C
�e��N�O�Q�r���f�F�A����o�A�w�g�O���B�����B�A�]
���A�֬ݨ�u�áA���ӧA�|ť�����ު��}�B�n�C
LONG);  
        set("exits", ([
        "north" : __DIR__"time2",
        "south" :__DIR__"time4",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
