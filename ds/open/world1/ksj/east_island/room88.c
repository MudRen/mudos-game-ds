#include <room.h>
inherit ROOM;

void create()
{
  set("short","�˫�");
  set("long",@LONG
�o�̬O�@���ˤl�f�ت��p�ΡA�Τl���̭��S�������\�]�A�Υ~��
�F�X�Ӧ˪K�Ϧ������H�A�a�W�G���F�`�`���}�L�A���X�L���H�z�H��
���@�a�A�ƦܬO�ѤU�@�ڵJ�ª��ˬ[�ťߵۡC
LONG);
  set("exits",([ 
      "east":__DIR__"room85",
     ]));
  set("no_clean_up",0);
  set("light","1");
  set("objects",([
      __DIR__"npc/asahi":1,
     ]) );
  setup();
}            
