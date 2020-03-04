#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(WHT"TEST"NOR,({ "test" }));
   setup();
}
void init()
{
   add_action("do_query", "query");
}

int do_query(string arg)
{
   mapping data = ([]);
   int val;
   string type,msg;
   object who;

   if(!arg)
      return notify_fail("�A�n�d�߽֪��}�T��ơH\n");
   if(!who = find_player(arg))
      return notify_fail("�u�W�S���o�ӤH\n");
   data = who->query("putjail_time");
   if(sizeof(data) < 1)
      return notify_fail(who->query("name")+"�S������}�T���\n");
   write(who->query("name")+"���}�T�����G\n");
   write("����������������������������������\n");
   foreach(type,val in data )
   {
      if(type == "1")
        msg = "��"HIG"���Ƶn�J"NOR"(Multi-login)   : ";
      else if(type == "2")
        msg = "��"HIG"�����H  "NOR"(Robot)         : ";
      else if(type == "3")
        msg = "��"HIG"�~�e��  "NOR"(Wash Screen)   : ";
      else if(type == "4")
        msg = "��"HIG"�|ż��  "NOR"(Foul language) : ";
      else if(type == "5")
        msg = "��"HIG"���Ѹ���"NOR"(Quest)         : ";
      else msg = "��"HIG"�L���{�D"NOR"(Other)         : ";
      printf("%s "HIR"%i��"NOR"��\n",msg,val);
   }
   write("����������������������������������\n");
   return 1;
}
