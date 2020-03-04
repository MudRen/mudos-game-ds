#include <ansi.h>
inherit ITEM;

void create()
{   set_name("������",({ "control" }));
    set("no_drop",1);
    set("can_give",1);
    set("unit","��");
    set("value",0);
    setup();
}

int query_autoload() { return 1;}

void init()
{
   add_action("do_gome", "gome");
   add_action("do_dhome", "gohome");
   add_action("do_control", "ct");
   add_action("do_where", "mary");
}

int do_gome()
{
   object me,dog;
   dog = find_living("_NPC_MARY_");
   me = this_player();

   if(!dog) return notify_fail(dog->query("name")+"���s�b��ϰ줤�C\n");

   message_vision("$N�b$n����p�n�a���F�ǸܡC\n",dog,me);
   tell_room(environment(dog), "�಴��"+dog->query("name")+"�����D�]���h�F...\n");
   dog->move(environment(me));
   return 1;
}

int do_dhome()
{
   object room,dog;
   dog = find_living("_NPC_MARY_");
   room = find_object("/obj/board/fedex_b");

   if(environment(room) != environment(dog))
   {
      message_vision("$N�N�N��l, �^��ۤv���u�@�ǡC\n",dog);
//      ob->set_name(HIY"���o��"NOR ,({ "butter dog","dog" }));
      dog->move(environment(room));
      message_vision("$N�^��u�@�ǤF�C\n",dog);
   }
   else { write(dog->query("name")+"�w�g�b�u�@�ǤF�C\n"); }
   return 1;
}

int do_control(string arg)
{
   string cmd;
   object ob,me,dog;
   me = this_player();
   dog = find_living("_NPC_MARY_");

   if(!arg || sscanf(arg, "%s",cmd) != 1 )
      return notify_fail("���O�榡�Rct <���O>\n");
   if(!dog) 
      return notify_fail("�䤣��"+dog->query("name")+"�L�k����R�O�C\n");
   if(!(ob = present(dog, environment(dog))))
      return 1;
   dog->force_me(cmd);
  return 1;
}

int do_where()
{
  int i,idle;
  string status1,status2,status3,status4,status5,status6,status7;
  object room,dog,*who;

  dog = find_living("_NPC_MARY_");

  if(!dog) return notify_fail("�䤣��ؼСC\n");

  room = environment(dog);
  who = all_inventory(environment(dog));

  if(!who) return 1;
  write(dog->query("name")+"�ثe���b"+room->query("short")+" - ("+file_name(room)+")\n");
  write("�@�@"+room->query("long")+"\n");
  for(i=0;i<sizeof(who);i++)
  {
     if(who[i] == dog) continue;
     if(environment(who[i]))
     {
//        idle = query_idle(who[i]);   //����ɬq���~�R*query_idle() of non-interactive object.
        write("  ");
        if(who[i]->query("title")) write(who[i]->query("title")+" "); 
        if(who[i]->query("nickname")) write("�u"+who[i]->query("nickname")+"�v");
        write(who[i]->query("name")+"("+who[i]->query("id")+")");
//        if(query_idle(who[i])) status1 = HIY"(�o�b��)"NOR;
//          else status1 = "";
        if(who[i]->query_temp("invis")) status2 = HIB"(����)"NOR;
           else status2 = "";
        if(who[i]->query_temp("hide")) status3 = WHT"(����)"NOR;
           else status3 = "";
        if((in_edit(who[i]))) status4 = sprintf(HIY"([�s��]: %s)"NOR,in_edit(who[i]));
           else status4 = "";
        if(in_input(who[i])) status5 = HIC"<��J>"NOR;
           else status5 = "";
        if(who[i]->query_temp("killer")) status6 = HIR"[���H��]"NOR;
           else status6 = "";
        if(who[i]->is_inactive()) status7 = HIW"[���m]"NOR; 
           else status7 = "";
        write(sprintf("%s%s%s%s%s%s\n",status2,status3,status4,status5,status6,status7));
     }
  }
  return 1;
}
