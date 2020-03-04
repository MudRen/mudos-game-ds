#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","������");
        set("long", "�A�����b�����ϤW�A�o�O�@�D��������A�_���L�񪺰}�աC\n");
        set("item_desc", ([ /* sizeof() == 1 */
        "������" : HIY"\n          ��"HIM"  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��          "HIY"��"NOR"=�Ҧb��m\n\n"HIM
                   "          ��  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��\n\n"NOR,
        "may" : HIY"\n          ��"HIM"  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��          "HIY"��"NOR"=�Ҧb��m\n\n"HIM
                   "          ��  ��  ��  ��  ��\n\n"
                   "          ��  ��  ��  ��  ��\n\n"NOR,
        ]));
        set("outdoors","land");
        setup();
}
void init()
{ 
  object me;
  me=this_player();      
  add_action("do_move","move");
  add_action("do_may","may");
  if(me->environment() ) return 0;
  me->start_busy(1);
  call_out("add_may",1,me);
}
int do_move(string arg)
{
          object me;
          me=this_player();
          if( me->over_encumbranced() )
                return notify_fail("�A���t���L���M�ʼu���o�C\n");
          if( me->is_busy() )
                return notify_fail("�A���ʧ@�٨S�������M���ಾ�ʡC\n");
          if( me->query("wound/foot") > 10 )
                return notify_fail("�A���}�˶չL���A�L�k���ϤF�C\n");
          if( arg!="s" && arg!="e" && arg!="se" && arg!="off")
          {
            notify_fail("�S���o�Ӥ�V�@�C\n");
            return 0;
          }
          else {
            if(arg == "off")
            {
              message_vision(HIB"\n$N�]�L�k�}�o�D����}�A���U�@�D�A���X�F�}�աC\n\n"NOR,me);
              me->move(__DIR__"start");
              me->delete_temp("MAY");
            }
            if(arg == "e")
            {
              message_vision("$N��۱���B��A�w�w�����F��L�h�C\n",me);
              me->move(__DIR__"may12");
            }
            if(arg == "s")
            {
              message_vision("$N��۱���B��A�w�w�����n��L�h�C\n",me);
              me->move(__DIR__"may16");
            }
            if(arg == "se")
            {
              message_vision("$N��۱���B��A�w�w�����F�n��L�h�C\n",me);
              me->move(__DIR__"may17");
            }
            return 1;
          }
}
void do_may(string arg)
{
       int may;
       object me;
       me=this_player();
       if( arg = "")
       may=me->query_temp("MAY/total");
       notify_fail("�A�ثe����Ƭ��G"+ may +"�C\n");
}
void add_may()
{
       int i;
       object me;
       me=this_player();
       i=me->query_temp("MAY/total");
       me->set_temp("MAY/total",i+4);
       me->start_busy(1);
       call_out("move",1,me);
}
void move()
{
        object me;
        me=this_player();
        if(me->query_temp("MAY/total")>20)
        {
         message_vision(HIR"\n$N�]�����B��A�@�Ӥ��V�A�q�����ϺL�F�U�ӡC\n\n"NOR,me);
         me->delete_temp("MAY");
         me->start_busy(1);
         me->move(__DIR__"start");
        }
        else {
         if(me->query_temp("MAY/total")==20)
         {
          message_vision(HIC"\n$N���\\���}�ѤF�o�D�����ϡC\n\n"NOR,me);
          me->delete_temp("MAY");
          me->start_busy(1);
          me->move(__DIR__"good");
         }
         else {
          message_vision("$Níí�����b�o�����ϤW�C\n",me);
          me->start_busy(1);
         }
        }
}