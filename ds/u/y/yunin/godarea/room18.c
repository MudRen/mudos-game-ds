#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"���Y���Y"NOR);
        set("long", @LONG
�C�C�����b�ۭӼe�諸���Y�W�A�߸̥u���@�ӺðݡA�o�ӬO����
�A�̭����\�]�A��{����|�̤j���t�N�A���M����A��������o�a��
�I�Ⱦ��A�Q�۷Q�ۡA�N������ı����F���Y�F!!
LONG
 );       
        
  set("exits", ([ /* sizeof() == 2 */
  "northeast"  : __DIR__"room15",
  "down" : __DIR__"room19",
  
]));  
        set("no_clean_up", 0);
        setup();
}     


