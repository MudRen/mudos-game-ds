#include <ansi.h>
inherit ITEM;
void dest_scroll(object me);

void create()
{
        set_name(HIW"�ǰe���b�w�t���w��"NOR,({"transpot scroll","scroll"}) );
        set("long","
�q�p�c���R�Ӫ��ǰe���b�A�O�t���w�𪺪k�v���F��K�U�a
���H���樫��@�ɦU�a�ҬI�k�s�����A�u�nŪ�W�����G��K�i�H
�ǰe�ܥ@�ɦU�a�A���L���Ȥ����A�o�Ө��b�O�ǰe��t���w��
���b(use scroll).
\n"
        );
        set("value", 25000);
        setup();                
}
void init()
{
        add_action("typeuse","use");
}
     int typeuse(string arg)
{
        object me;
        me=this_player();
        if( arg != "���b" && arg != "transpot scroll" && arg != "scroll" )
         return 0;
  if(me->is_ghost()) return notify_fail("�]�k���b�y�����]�k�O���|���A��z�����I�I\n");
   if(me->query_temp("killer"))
          return notify_fail("�A���F�H�A�]�k�v�̳]�U���������A�ݤ������b�I�I\n");
   if(me->query_temp("invader"))
     return notify_fail("�A�����F���a�A�]�k�v�̳]�U���������A�ݤ������b�I�I\n");

  if(me->is_busy() || me->is_fighting())
  {
    write("�A���b���A�S�ŧ@��L�Ʊ��C\n");
    return 1;
  }

        else {
        message_vision( HIG "$N�ݵۨ��b�W����r�A�w�w��D�G�u�����r�d�����Ǳo...�v���b�W����r�@�Ӥ@�Ӫ��Ʀ����ϡA�����F...\n\n" NOR ,me);
        message_vision( RED "�@�ζ¦⪺�����n��F$N�A�L�F�@�|�A$N�P�����@�P�����b�Ů�...\n\n" NOR ,me);
        me->move("/u/b/baal/area/dst/dst1");
        return 1;
             }
        call_out("dest_scroll",me);
        return 1;

}

void dest_scroll(object me)
{
        if(!me) return;
        if(!this_object() ) return;
  message_vision("���b�b$N�⤤�C�C�ܯܡB���¡A�̫�Ʀ��ǡA�����F...\n",me);
  destruct(this_object());
}


