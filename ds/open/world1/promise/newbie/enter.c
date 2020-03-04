#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "���s��J�f");
  set("long", @LONG
���Ϭ����s��J�f�A���Ǵ��������@�P�A���L����ͪ��A�E�ݤ�
�U�٦��I���F�z�C���Ϭ��s��m�߰ϡA��J���򪺷s���즹�m�ߧ�
��C
LONG);
  set("exits", ([
  "enter" : __DIR__"room1", 
  "south" : "/open/world1/cominging/area/forest5", ])); 
  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/dragon-guard" : 1,
]));
  set("outdoor","land");
  setup();
}


int valid_leave(object me, string dir)

{
        string gender;
        gender=me->query("gender");
        if ( gender=="�k��" ) gender="�A";
        if ( gender=="�k��" ) gender="�p";
        if ( me->query("age") > 50 ) gender="�z";
        
        if( dir=="enter" )
        {
                if(me->query("level")>15)
                {
                        message_vision(HIY"�u���s���G"HIG" �o�̤��A�X"+gender+""HIG"�X�J�A�гt���}�C\n"NOR, me);;
                        return notify_fail("���̥u������15�H�U�~��i�h�C\n");
                }
        }
        return ::valid_leave(me, dir);
}


