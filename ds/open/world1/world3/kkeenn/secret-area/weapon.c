#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Weapon Shop");
        set("long", @LONG

�|�P���M�@�ӤH���S���A�u���@�x�j�����Ū������H�b�V�O�a�V�A��
�P�ۤv���ӫ~�C
[[0;1;35m�[1m�[1m�[1mf[1m�[1m�[0m] :              [0;1;5;31m [0;1;31mL[1mi[1ms[1mt[0m,
[[0;1;35m�[1mR[1m�[1mF[1m�[1m�[0m]  :              [0;1;31m [1mB[1mu[1my[0m,
P.S
[0;1;32m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mF[1m�[1m�[1m,[1m [1m�[1m�[1m�[1m�[1me[1ma[1ms[1mt[1m,[1m [1mn[1mo[1mr[1mt[1mh[1m,[1m [1me[1ma[1ms[1mt[1m�[1mh[1m�[1m�[1m�[1mf[1m�[1m�[1m,[1m�[1m�[1m�[1m�[1m�[1mX[1m�[1m@[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
    "east":__DIR__"sec2.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/weapon.c"   :1,
]));

        setup();
        replace_program(ROOM);

}


