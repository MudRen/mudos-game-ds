#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�s�����_���a�U���A�X�e�F�J�����}�ޡA�æb�o�̫I�k�X�j�j
�p�p�A���P���a�ޡA�����٤��ɸ��U�H�ۡA�ݦ��n�Y��@�ˡA�g�~
�֤�A�b�a�W�令�F�@�y�y�p�۰�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room8",  
  "south" : __DIR__"room6",
  "east" : __DIR__"room2", 
])); 
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/la-ah" : 1, 
 __DIR__"npc/she-bun":1, 
]));
        set("no_clean_up", 0);

        setup();
}

