#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIG"�S�B�Ǹ�"NOR);
  set("long",@LONG
�~�����ι���o�{�����r�𦳫ܤj������A����
�ӶO����A�b�`���q�M���r�𶡶}�F�@�����F���A�D��
�W�r�H�o�{���r�𪺱��I�a�R�W�A�L�{�b�w���ʸU�I�ΡC
LONG
  );
  set("exits",([
  "back":"/d/wiz/hall1",
  "east":"/u/m/morral/world3/hans2",]));
  set("light",1);
  setup();
}
