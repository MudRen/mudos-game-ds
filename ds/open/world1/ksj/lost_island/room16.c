#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIG"�~��"NOR);
        set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���W���R�ۤC�m�����M�_�������ΡA�����i�H�ݨ�
�øV���~�b��줤�b�]�V���A�񲴱�h���L�H�ϡA�k�M�O�ʪ����@�~
�緽�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room15",
  "west" : __DIR__"room17",
  "south" : __DIR__"room11",
  "north" : __DIR__"room23",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("objects",([
           __DIR__"npc/color-bee":3,
         ]) );
        setup();
}
