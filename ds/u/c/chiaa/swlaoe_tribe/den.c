//u/c/chiaa/swlaoe_tribe/den.c

#include <ansi.h>//�w�q��X
inherit ROOM;    //�w�q�ж�

void create()
{
   set("short", "�K��");
   set("long",@LONG
        �@�ө��t���K��,�A�p���l�l���`���e�誺�ƪ�,
        ���M�@�ӤH�v���A�����u���ಾ��L���W!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "up"   : __DIR__"salle2",   //�j�U2
]));
            setup();
replace_program(ROOM);
}
