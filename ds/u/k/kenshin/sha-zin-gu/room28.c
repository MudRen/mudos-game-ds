// Room: /u/k/kenshin/sha-zin-gu/room28.c
 
#include <ansi.h> 
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "�D�ש�");
        set("long", @LONG
�o�̴N�O����M���D�שФF�A�̭����\�]�۷�����A�t�~�٦�
����_�C�a���b��W�A�������~�A�A�ٵoı��|���@�ب��D�ǩǪ��A
�n�����O�ݩ󦹩ж������D�A�|�O���ǹL�Ӫ��O?
LONG
        );
        set("light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room27",
]));   
  set("item_desc", ([ /* sizeof() == 1 */
"���e" : "�����Z�Q����ϡA���e���Z�Q���k���n���W�F�i�h�A�ΤO�@�ݡA���Y���G���Ӷ}���A�O�n��(press)�U�h�ܡH\n"
]));        set("no_clean_up", 0);
        set("current_light", 4);
        setup();
        replace_program(ROOM);
} 
 
void init()
{
      add_action("do_press","press");
}

int do_press(string arg)
{
       object me;
       me=this_player();
        if( !arg || arg != "�}��")
       return 0;
       else {
message_vision(HIW"$N���U�}����A���ɦa�O�}�F�j�šA$N��ӤH���U���I\n"NOR,me);
       me->move(__DIR__"room30");  
//message_vision(HIC"�uť��@�}�G�s�n�A$N���W�����U�ӡC\n"NOR,me); 
        } 
          return 1;
}

