#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�{�b�Ө�F�_�A�L���`�B, �o����S������F��, �u����
�Ǫ����O, �M���W���X�ڤp��, �٦��@�Ӭݰ_�ӫ��ª��i�ܪO�e
��, �K�O�H�̱`�`�g�����h�A�a�a.
LONG
    );
 set("item_desc",([
     "�i�ܪO":"�A�³o�i�ܪO�W�ݤF�ݡA�o�{�W���g�۳q�L�h�A�a�a����k:\n
          "HIC"move ����V��"NOR"\n
�A���T�P�¥߳o�ӧi�ܪO���H�A���A�ѨM�F�@�ӧx�Z�C\n",
     ]));
 set("exits",(["west":__DIR__"en20",
               "east":__DIR__"en22",
             ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}           

int valid_leave(object me, string dir)
{
  ::valid_leave();
  if( dir=="east" && !userp(me))
  return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}

