#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�˪L");

 set("long",@LONG
�A�s�U�����F�X�f���e���M�u, �uı���M��n, �믫�ʭ�, 
���G�ĪG����ѱ��t�u�t! �A�|�Y�@��, �u�����\�h�ʪ����b
���B�ͬ�, �|�B���M���Z, �o�̹�P�P�Ҭۮt�L�X! 
LONG
    );
set("exits",([ "southeast":__DIR__"tree2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
set("objects", ([__DIR__"npc/deer" : 4
    ]));

 setup();
 replace_program(ROOM);
}
