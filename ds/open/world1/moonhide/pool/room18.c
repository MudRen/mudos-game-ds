#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�o�̤��ɥX�{�n�X�����۴����A���̦��G�b�}�E�|�@�ˡA��
�@�Ӥp���A�C�C�ӼL�̡A�@���_�ۮ�w�A�n���b�Q�פ���A����
�@�ɯu�O����C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room15",
  "south" : __DIR__"room19",])); 
        set("objects",([/* sizeof() == 1*/
 __DIR__"npc/she-bun":4,
]));        set("no_clean_up", 0);

        setup();
}

