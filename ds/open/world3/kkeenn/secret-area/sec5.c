#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U��������");
        set("long", @LONG
�ѪŪ��ն��Q�j�O���ϳ��j���Ʀ� Secret City���i�ܪ�....

�F��: �~�����u�@�a�I[ [0;1;35m�[1mq[1m�[1m|[1m�[1m�[1m�[1m�[0m ]      �ȫȪ��𶢦a�I[ [0;1;35m�[1mQ[1m�[1mG[1m�[1mH[1m�[1m�[1m�[1m�[1m [0m] 
���: ���æu�@�̷̳R[[0;1m [1;35m�[1m�[1m�[1m�[1m�[1m�[1m [0m]        �y���Ȧ�̤��B[ [0;1;35m�[1ma[1m�[1mU[1m�[1m�[1m�[1m�[0m ]
�n��: �ӤH�f�������a[ [0;1;35m�[1m�[1m�[1m~[1m�[1m�[1m�[1my[1m�[1mB[0m ]    �j�a�����u�u��[ [0;1;35m�[1mx[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m ]
�_��: �ȤH���̷R�a�I[ [0;1;35m�[1mS[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m ]  �ߤ@�d�u���ѤH[ [0;1;35m�[1m�[1m�[1mD[1m�[1m�[1m�[1ma[0m ]
�W��: �����~���p���a[ [0;1;35m�[1mq[1m�[1mi[1m�[1ml[1m�[1m�[0m ] 
�U��: �ĵ��ѤH�𮧩�[ [0;1;35m�[1mW[1m�[1m�[1mK[1mT[1mV[0m ] 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec4.c",
     "north":__DIR__"sec10.c",
     "east":__DIR__"sec6.c",
     "up":__DIR__"mail.c",
     "west":__DIR__"sec8.c",
     "down":__DIR__"sec13.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
