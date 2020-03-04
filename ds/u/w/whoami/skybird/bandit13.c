#include <ansi.h>
#include <room.h>
inherit ROOM; 

string *show_msg = ({
HIC+BLK"�Ať��@�ǷL�p���n���q�A�W�誺����ǤF�L�ӡK�K\n"NOR,
WHT"�j�ۤ@�����A�A��bť���X�Ӧo�̦b���Ǥ���K�K\n"NOR,
HIC"��M���A�ӤW�Ǩӡy�I�z���@�n�A�����n�������������F�E\n"NOR, 
HIG"�ݨӳo�O�ӥi�H�X�h�ݬݱ��Ϊ��ɾ��F�E\n"NOR,
});
void create()
{
 set("short","��D��");
 set("long",@LONG


LONG);
 set("no_clean_up",0);
 set("light",1);
 setup();

} 

void init()
{
   object me=this_player(),ob=this_object();
   ::init();
   if ( !me->query_temp("block") ) return;
   me->set_temp("msg",1); 
   if ( !me->query_temp("msg") ) return;   call_out("delete_block",40);
}

void delete_block()
{
   object me=this_player(),ob=this_object();
   int i = me->query_temp("msg");
   string msg; 

   if( i > 4 ){
      me->delete_temp("msg"); 
      me->delete_temp("block");
      ob->add("exits",(["westup":__DIR__"bandit11"]));
      call_out("rb",300);
      return;
   } else {
      msg = show_msg[i-1];
      tell_object(me,msg);
      me->add_temp("msg",1);
      call_out("delete_block",6-i);
   }
  return;    
}
 
void rb()
{
   object me=this_player(),ob=this_object();
   ob->delete("exits","westup");
   return;    
}

int valid_leave(object me, string dir)
{
  if( !me->query("class") && me->query_temp("block") && dir == "westup" )
  {
        return notify_fail("�Ať��F���֤H���͸��n�A�̦n�٬O�����A�W�h�a�E");
  }
  else if( !me->query_temp("block") && dir == "westup" )
  {
    message_vision("$N�����N�N�a���W���}�E\n",me);
    return ::valid_leave(me, dir);
  }
  return ::valid_leave(me, dir);
}

