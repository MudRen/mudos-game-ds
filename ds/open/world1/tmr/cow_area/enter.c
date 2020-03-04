#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",  "�L���ѸO - " HIM"�ǰe���}" NOR);
  set("long", @LONG
�A�����b�L���ѸO���]�k�}���A�A���e�X�{�F�Q��
�X�f�A�A������ܨ䤤�@�ӥX�f�A�~�����}�o�̡C
LONG
);
  set("no_horse_member",1);

  set("exits", ([
  "field1" : __DIR__"field1/room12.c",
  "field2" : __DIR__"field2/room12.c",
  "field3" : __DIR__"field3/room12.c",
  "field4" : __DIR__"field4/room12.c",
  "field5" : __DIR__"field5/room12.c",
  "field6" : __DIR__"field6/room12.c",
  "field7" : __DIR__"field7/room12.c",
  "field8" : __DIR__"field8/room12.c",
]));
  set("no_clean_up", 0);

  setup();
}

void show(object me, int field)
{
string msg = sprintf(
  HIM"\n\t�Z�L�ǥX�F�@�h��H������:%s(%s)"HIM"�_�I���J"HBK"��%s�y�շt�������"HIM"�F�I�I\n\n"+NOR
, me->name(), me->query("id"), CHINESE_D->chinese_number(field) );
      message("world:world1:vision", msg ,users());
}

int valid_leave(object me, string dir)
{
switch( dir ) {
case "field1": show(me, 1); break;
case "field2": show(me, 2); break;
case "field3": show(me, 3); break;
case "field4": show(me, 4); break;
case "field5": show(me, 5); break;
case "field6": show(me, 6); break;
case "field7": show(me, 7); break;
case "field8": show(me, 8); break;
} 
        return ::valid_leave(me, dir);
}
