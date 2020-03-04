// Room: /u/l/lestia/area/map_7_4.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�F�۱�-�j�����D");
        set("long", @LONG

�A���b�@���e�����j�D���W�A�D�W�ө����H���M�@�⪺����F�۱Ъ���
�ǥզ��A�A�A���D�A�w�g�����F�۱Ъ����ߤj���F�A�j�����f��ǦU���@
���J���F�s�M���K�W�A�������ۨ��u�æb�L�d�n�i�J�j�����H�A��ǦU
�q���F�۱Ю{�~�i�ϥΪ��Z�D���C

LONG
        );
        set("no_clean_up", 0);
        set("world", "undefine");
   set("objects", ([ 
__DIR__"npc/guard1":2,
]));
 set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_5",
  "north" : __DIR__"map_6_4",
  "west" : __DIR__"map_7_3",
  "south" : __DIR__"map_8_4",
]));
        set("current_light", 1);

        setup();
}
int valid_leave(object me, string dir)
{
       object obj;
me = this_player();
 if( dir=="west")      //&& !wizardp(me))
        {
 if( me->query("class1") != "�F�۱�" ) return notify_fail("�Ю{��A��: �A�S���ѴL���P�N����i�J�C\n");
// }
}
                if( me->query_temp("killer") )
                {
                        message_vision(HIW"\n�Ю{��$N���D: �ڭ��F�۱Ф����w���H����C\n"NOR,me);
                        return notify_fail("�A�������q�r�ɶ��L�F����~��h�����ѴL�C\n");
                }
/*
                if( me->query_temp("can_go") )
               {
                        message_vision(HIW"\n�Ю{�J�Ӫ��ˬd$N����A��$N�L�h�F�C"NOR,me);
               }
               if( me->query_temp("can_join_advmaster") )
               {
                        message_vision(HIW"\n�Ю{�J�Ӫ��ˬd$N����A��$N�L�h�F�C"NOR,me);
          me->delete_temp("can_join_advmaster");
}
*/
         return ::valid_leave(me, dir);
}


