inherit ROOM;
#include <ansi.h>
void create()
{
      set("short", HIG"���թ�"NOR);
      set("long", HIW"\n\t�@�Ӵ��թж�...�u���@�ӤH���C\n\n"
                     "\n\t�M�@�j�諸����...�ݨӤ��`��z\n\n"                                                
      NOR);
             
    set("no_clean_up",0);        
    set("light",1);               
    set("exits", ([
         ]));         set("light",1);
        set("valid_startroom", 1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/test" : 1,
            ]));
        setup();
        replace_program(ROOM);
}





