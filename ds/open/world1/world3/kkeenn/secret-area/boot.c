#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Train Station");
        set("long", @LONG
�|�P���H�s�Q�������A�b���䪺���[�W���@�Ө����Ŧ�q����A����
�ȭ��o�b�c�⨮���A�b���e�観�@���q�r���G��A�b�W�����ۡG
�m       [35m [0;1m�[1mn[1m�[1mR[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mA[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m[[1;36m�[1ma[1m�[1mU[1m�[1m�[1m-[1m>[1m�[1mD[1m�[1m�[1;35m][0m  [0m        �n

( ����: �R���Х�Buy Ticket )
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "out":__DIR__"sec8.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trainman.c" :1,
]));

        setup();
        replace_program(ROOM);

}
