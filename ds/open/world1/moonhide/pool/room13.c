#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�o�̪��g��A�b����a�ϳ̱`���A���̪ΨU���¤g�P�߶t�g�A
�a���ɴ��X�@�@����A�]����}���A�������E�����w�A���۬}��
���Ϊ��A��¶�b��ǡA�Φ����������[�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room16",  
  "south" : __DIR__"room14", 
  "east" : __DIR__"room11",
  "north" : __DIR__"room12", 
])); 
     set("objects",([ /*sizeof == 1 */
__DIR__"npc/bu-la-fish":2,
]));        set("no_clean_up", 0);

        setup();
}

