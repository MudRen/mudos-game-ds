#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�n���D"NOR);

 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@�����n���D, �A�Pı�쨫�D���t�@�ݦ�
�G�ǨӤ@�}���˪��V���n, �A�{���]�\�ۤv���ӥh�ݤ@�ݨ��V
���n���Ѩ�....
LONG
    );
 set("exits",([ "north":__DIR__"pill2",
            "south":__DIR__"walk4",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);   
}        
           
