#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�o�̤��ɥX�{�n�X�����k�J���A���̦��G�b�}�E�|�@�ˡA��
�@�Ӥp���A�C�C�ӼL�̡A�@���_�ۮ�w�A�n���b�Q�פ���A����
�@�ɯu�O����C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room17",
  "north" : __DIR__"room19",])); 
        set("objects",([ /* sizeoff() == 1 */
__DIR__"npc/bu-la-fish":4,
]));        set("no_clean_up", 0);

        setup();
}

