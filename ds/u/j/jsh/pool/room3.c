#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
���⪺�n�F�A��b�W���A����b���W���A�A�����ٷ|�y���A
�A�ٷ|�C�U�Y�ӡA�C�C�[��۳o�̪����F�A�u�O�}�G���F�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room6",  
  "south" : __DIR__"room4",
  "north" : __DIR__"room2",
  "east" : __DIR__"room1",]));
        set("no_clean_up", 0);

        setup();
}

