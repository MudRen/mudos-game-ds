#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"����"NOR);

 set("long",@LONG, 
�o�̬O�ѱ��̤l���a�H�ҩ~���a��, �O�H���ѱ��̤l��
�O���Ѥ�, �����M�y���H���O���a�ݪ�, �ӥB�ѱ��èS���̤l
���i���B���W�w, �]�����a�����̤l�ä��b�ּ�, �ҥH���Y�@
�ӧ̤l���a��, �i�O�|�ް_������......
LONG
    );
 set("exits",([ "south":__DIR__"bird10",
    ]));
set("objects", ([__DIR__"npc/woman" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
