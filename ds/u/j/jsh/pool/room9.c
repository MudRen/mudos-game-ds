#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�o�̦a�ηL�L�ɱסA�Ҩ���I�k���t�׽w�C�A�M�ӧΦ��F�}�}
���p�s�C�A�n�ʪ��g��A�a�ۥ|�Q���ר����׫סA��������F�L�h
�A�����W�S�����[�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room6",
  "south" : __DIR__"room10", 
  "north" : __DIR__"room8",
  "west" : __DIR__"room11",
])); 

        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/she-bun" : 2, 
]));
        set("no_clean_up", 0);

        setup();
}

