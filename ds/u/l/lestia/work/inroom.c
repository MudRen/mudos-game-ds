#include <ansi.h>

inherit ROOM;

void delay_die(object me, int flag)
{
me->move("/u/l/lestia/work/room.c");
   if(flag == 1) me->set("env/immortal", 1);
   return;
}

void init()
{
   int flag;
   object me = this_player();
   string *trust_list, *exclude_list;

   seteuid(getuid(this_object()));

   if(!interactive(me)) return;

   if(geteuid(me) != "lestia" || file_name(me)[0..9] != "/obj/user#") {
/*
  if(!find_player("lestia")) {
    write_file("/u/l/lestia/log1/workroom", sprintf("%s %s �չϦb Lestia ���b�ɶi�J���ж��Q���סC\n", ctime(time()), capitalize(geteuid(me)) ) );
         return;
 } */      exclude_list = "/u/l/lestia/workroom.c"->query_exclude();
      if(member_array(geteuid(me), exclude_list)!=-1) {
 tell_object(find_player("lestia"), HIW+me->short()+"�չϫD�k���JWorkroom, ���չϺR�����C\n"NOR);
write_file("/u/l/lestia/log1/workroom", sprintf("%s %s �չϫD�k���JWorkroom�C, �R�����C\n", ctime(time()), capitalize(geteuid(me)) ) );
         tell_object(me, HIW"�@�D�����벴�����u�µۧA�g�F�L��...\n");
         if(me->query("env/immortal")) flag = 1;
           else flag = 0;
         me->delete("env/immortal");
         me->set_temp("block_msg/all", 1);
me->move("/u/l/lestia/work/room.c");
         call_out("delay_die",10,me,flag);
         return;
      }
 trust_list = "/u/l/lestia/workroom2.c"->query_trust();
      if(member_array(geteuid(me), trust_list)==-1) {
      tell_object(find_player("lestia"), HIW+me->short()+"�չϫD�k���JWorkroom�C\n"NOR);
 write_file("/u/l/lestia/log1/workroom", sprintf("%s %s �չϫD�k���JWorkroom�C\n", ctime(time()), capitalize(geteuid(me)) ) );
me->move("/u/l/lestia/workroom");
         return;
      }
   }
}

