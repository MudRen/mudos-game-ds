#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�����D���j�Ӫ��L���A�ϱo�F�ɸ��b�C��W�O�����ʡA�U��U
���A���X�a��n�X�l�ءA�D�n���۪������������ۡA�b�C�᳡���A
�Y�X�F�@�ڥ۬W�A�P�}�޳��ݬ۳s���A���ӴN�O���}�ު���W�C 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room13",  
  "east" : __DIR__"room9",
])); 
        set("objects", ([ /*sizeof == 1*/
  __DIR__"npc/small-fish":1,
]));
        set("no_clean_up", 0);

        setup();
}

