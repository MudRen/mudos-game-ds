#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Combat Shop");
        set("long", @LONG
�o�̴N�O���ӥ@��(Future World)�ƦW�ĤT�W���S��D�㩱�F�I�b��
���W�����йL���A�]���O���@�Ǭ�Ǯa�O�ɤ߫�ҷQ�X�ӯ��_�k�_�A�ҥH
�S�O���W�A�o�a�����L�����A�u���b�̸̯�R����� �C
[ [0;1;36m�[1m�[1m�[1mC[1m�[1m�[1m [0m]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m�[1mR[1m�[1mD[1m�[1m�[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec11.c",
     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/item.c" :1,
]));

        setup();
        replace_program(ROOM);

}
