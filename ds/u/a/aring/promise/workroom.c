#include <room.h>
#include <ansi.h>
inherit ROOM;
void create() 
{ 
                set("short", HIG"�Фl�M�B"NOR);
                set("long", HIC"
�E�X�� ���X �O�E�X��X���O?�j�O�E�X�E�X��X�� ���X �O�E�X��X���O�X�O�E�X�� 
�E�X��X�O���X�D�O�E�X��X�O�X�D�O�E�X��X  �O�O�E�X��X�O���X�D�O�E�X��X�E

           �@�@��   �@�@�@�@��@��
             ���@�@�@�@�@�@�@ ���@�@��@�@���@�
         �@���@��  ___��_  ����@���@�@�@��@��
         ���@�@  _/\\     \\�@ ���@��@��
�@�@�@          /\\ _\\\\____\\�@��@��
         �@�@   ||''||''''|
           ~~~~~```````````~~~~~   �� home��  
"NOR

);

  set("exits", ([ /* sizeof() == 2 */
  "js" : "/u/j/jangshow/workroom",
  "west" : "/u/p/promise/jailroom", 
  "enter" : "/u/p/promise/testroom",
  "down" : "/d/wiz/hall1",
])); 
        set("objects", ([ /* sizeof() == 1 */

//  __DIR__"npc/eq-man":1, 

]));
                     set("light",1);   
                setup();
                replace_program(ROOM); 
     call_other("/obj/board/promise_b", "???");
}


