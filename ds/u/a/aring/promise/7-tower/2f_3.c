#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", RED"�C���� "HIR"�i���y�F�}�j"NOR);
  set ("long", @LONG
��A�@��J���a�A�N�Pı�����I���A���y�H�I�A�b�Ǫ����y����
���_���U�N�A�٦��հ����b�Ǥ��_����¶�A�Pı���a���u�����A��
�ۤ��M�`�������C
LONG
);
  set("exits", ([
  "southwest" : __DIR__"2f_2",
  "northeast" : __DIR__"2f_4",
   ]));
   set("objects", ([ /* sizeof() == 1 */

   __DIR__"npc/fire":4, 

]));
  set("no_clean_up", 0);
  
  setup();
 }


int valid_leave(object me, string dir)
{
    if( dir == "southwest" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");
     if( dir == "northeast" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");
    return ::valid_leave(me, dir);
}

