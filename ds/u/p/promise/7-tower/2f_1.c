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
  "east" : __DIR__"2f_2",
   ])); 
   set("objects", ([ /* sizeof() == 1 */

   __DIR__"npc/fire":4, 

]));
  set("no_clean_up", 0);
  
  setup();
 }
 int room_effect(object me)
{
        switch(random(2))
        {
         case 0:
         write(HIR"�b�Ǫ����y�������_���U�N...\n"NOR);
         tell_object(me, HIW"�A�Pı�D�`������..�C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIR"�A�@���`�N�A��D�հ����V�A�Ӽ�.... \n"NOR);
         tell_object(me, HIB "�A����F�@�I�p�N��...�C\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}
int valid_leave(object me, string dir)
{
    if( dir=="east" && !userp(me) )
        return notify_fail("���̥u�����a�~��i�h�C\n");

    if( dir == "east" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("�A�Q����צ�F�h���C\n");

    return ::valid_leave(me, dir);
}

