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
  "east" : __DIR__"room11",
  "west" : __DIR__"room13",
  "south" : __DIR__"room7",
  "north" : __DIR__"room17",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("objects",([
             __DIR__"npc/eq/stone2":1,
             __DIR__"npc/black-dog":1,
           ]));
        setup();
}
