#include <room.h>
#include <ansi.h>
//�q����_�i�Jarea, ����ϥά۹���|.

inherit ROOM;

void create()
{
set("short",HIB"�R����"NOR);
 set("long", @LONG
�o�O�@���K�ǡA�]�O�i�J�R�����������J�f�A�ݩ�Х@�Ův�s�άO��
�L����i�J�������~�|�C���F�A�i�Ӫ��a��A�A�ݤ�������L���X�f�C

LONG
);
set("valid_startroom", 1);
set("light",1);

set("exits",([
   "area":__DIR__"al0",
   "out":"/u/g/genius/fightroom",]));
set("objects",([
     __DIR__"obj/eagle" : 1,
     "/u/g/genius/obj/cream" : 1,
     "/u/g/genius/obj/navel" : 1,
     "/u/g/genius/obj/coffee" : 1,
      ]));
setup();
}
