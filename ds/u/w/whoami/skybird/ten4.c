#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���g�p��");
 set("long",@LONG
�o�O�@���q���F�誺���g�p���M�˪L���R�����ať�����λ�
���s�M�ϤH���T��i�_�ӡM�@��谪�j�����ϩ��W���������d
����m���j�s�M�p�G�A�S����L���ơM�̦n�٬O�������}�H�K�D
�J����.
LONG
    );
 set("exits",([ "westdown":__DIR__"ten3",
                "northeast":__DIR__"ten5",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}

