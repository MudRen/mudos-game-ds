#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ħ���"NOR);

 set("long",@LONG
�����j�W���ѱ��ħ���, �ܻ��o�����M�u��R�������
���ħ�, �����M�O���i�h�o���n�a��, ���ҥH�n�ζR���O�]��
�ѱ��̪�]�F���u....
LONG
    );
 set("exits",([ "north":__DIR__"pill8",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
