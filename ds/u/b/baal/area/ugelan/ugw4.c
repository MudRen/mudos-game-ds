#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", RED"�վB��������u�ƶ��n��"NOR);
        set("long", @LONG
�o�O�@�Ӱj�Y�A���ۤW�h���ӱ�A���䦳�Ӧu�å𮧪�
����Ȥl�C
LONG
        );
        set("exits", ([ 
                        "west": __DIR__"ugw2",
                                                "up": __DIR__"ugw5",
            ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

