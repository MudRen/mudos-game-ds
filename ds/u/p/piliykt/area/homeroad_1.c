#include <ansi.h>
inherit ROOM;
void create()
{

set("short",HIG"�K�P�ȴ�"NOR);
set("long", @LONG
�o�O����������ȴ�, �b�o�̦��\�h���ӫ�, ���f���W�豾�F�Ӫ���
�۵P�W�g�ۡy�K�P�ȴ̡z, �A�u���쩱�p�G���۩۩I�ȤH, �o���٦��c��
���Ϋ~�M����.
LONG
);
set("light",1);
set("exits", ([                
        
        "west"  : __DIR__"road_8.c",
        "up"    : __DIR__"up_1.c",
   ]));

 setup();
}


