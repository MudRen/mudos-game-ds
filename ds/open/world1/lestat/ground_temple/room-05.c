#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�c��R�Ѫ��ж����A�ﺡ�F�H���M���]�����e�A�H�δ������a��
���١A�b���e�襤���A���@�ӷt���⪺�c�l�]box)�A�c�l�����x�۬�
���A�i��䤤�õۤ��򯫯����_���b�̭��C
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "�c�l"  : "�@�Ӭ��⪺�_�c�A�W�����@����A�A�i�H�յۼ��}���]break�^�C\n",
        "box" :  "�@�Ӭ��⪺�_�c�A�W�����@����A�A�i�H�յۥ����}���]break�^�C\n",
        ]) );
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-06",
                  "west" : __DIR__"room-04",
                  "south" : __DIR__"room-03",
        ]));
        set("light",0);
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

void init()
{
add_action("do_pick","break");
}

int do_pick(string str)
{
if(str=="box" || "str" == "�c�l")
 {
  if(this_player()->query("class1") == "thief")   // check¾�~���p�� 
  {
  write("�̵ۧA�����s�骺�ӾU��ı�A�Aı�o�o�c�l�O�����A���i�H�}�I\n"); 
  return 1;
  }
  else 
  {
  write("�A�w�O���Z�O���}�c�l�A�c�l���Q�X�@�D���K�N�˧A��A�S�A����W�C\n");
  this_player()->set_temp("temp/death_type","[[1;31m�Y���N�˭P��[0m]");
  this_player()->receive_damage("hp",30+random(80));
  return 1;
  }
 write("�A�Q������H\n");
 return 0;
 }
}


