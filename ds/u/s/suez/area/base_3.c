#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"�j���~"NOR);
	set("long", @LONG
�j���~�A�o�̪��ѳ��}�F�Ӭ}�A�}�}�D���Ѭ}���ǥX�A�\�h�K�P����
�l�m�Z�֤F�N�E���b����ѡA�o���\�F�\�h�����M���A�����O�ͪ�����Y
�A���O���ˬO�i�H���A�ܭӵh�֡C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "south" : __DIR__"base_5",
               ]));
         set("item_desc",([
        "�ѳ�":"�ݵۨ��Ӭ}�A�A���T�h�äU�B�ɳo�̷|���|�T��....\n",
        "����":"���M�סA�t���A���....�����ơA�ҥH����Y�A�ͦY�|�Ԩ{�l�C\n",
         ]));

       set("objects", ([ 
          __DIR__"npc/obj/pot" : 1,
           __DIR__"npc/apprentice2" : 1,
        ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();

}