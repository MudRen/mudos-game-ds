#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Equip Shop");
        set("long", @LONG
�o�̴N�O���ӥ@��(Future World)�ƦW�e���W�����㩱�F�I�����v��
���� -�o�a�����ҥH�༵�U�h�A�w�M���������Z���B�A��Ӫ��I���]���o
�̬O���v�j���A�ҥH��~�Q�C�ެ��T�~������A�o���٫O���@�ǩO�I�H
[ [0;1;36m�[1m�[1m�[1mC[1m�[1m�[0m ]:         [0;1;31mL[1mi[1ms[1mt[0m,
[ [0;1;36m�[1mR[1m�[1m�[1m�[1m�[0m ]:          [0;1;31mB[1mu[1my[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec9.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/equip.c"   :1,
]));

        setup();
        replace_program(ROOM);

}
