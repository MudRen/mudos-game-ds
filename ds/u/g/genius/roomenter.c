#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"�p��s��"NOR);
set("long", @LONG
�o�̾������۴X�x�q��(computer)�A���d�W�\���F�U���U�˪���
�y(book)�C���@�i��(bed)�ݰ_�ӫD�`���ξA�A���H���Q�n���W�h����
�Y�C�`��Ө��A���M�F��ܦh�A���O���������C
LONG
);

      set("item_desc", ([
      "computer":"�o�O�@�xGENIUS III 333 GHZ���q��\n",
      "book":"�z....�n�h�Ѱ�....\n",
      "bed":"�A�ݨ�@�i�O�H�y�f������\n",
      ]));

      set("exits", ([
      "out": "/u/g/genius/workroom.c",
      "down": "/u/g/genius/fightroom.c",
      "east": "/u/g/genius/colorroom.c",
      "west": "/u/g/genius/handfeet.c",
      ]));

      set("objects",([
      "/u/g/genius/npc/moneyman" : 1,
      "/u/g/genius/npc/fightm" : 1,
      ]));
      setup();

      set("light",1);
}
