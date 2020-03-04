#include <ansi.h>
#include <room.h>
#include <localtime.h>

inherit ROOM;
void create()
{
   set("short",HIG"������"NOR);
   set("no_clean_up",0);        
   set("light",1);               
   set("exits", ([
       "east" : __DIR__"room"]));
//   set("objects", ([
//                __DIR__"npc/man" : 1]));
   set("valid_startroom", 1);
   setup();
   load_object(__DIR__"board/www_b");
}

void init()
{
   mixed *local;
   int WDAY;
   object me = this_player();
   string time,day;
   local = localtime(time());
   WDAY = local[LT_WDAY];

   // ===============�]�w�ɶ�===============
   if(WDAY == 1) day="�@";
      else if(WDAY == 2) day="�G";
      else if(WDAY == 3) day="�T";
      else if(WDAY == 4) day="�|";
      else if(WDAY == 5) day="��";
      else if(WDAY == 6) day="��";
      else if(WDAY == 0) day="��";
   time = sprintf("\n\n\t�i"HIW"%d�~%d��%d�� �P��%s"BLK" %d:"HIW+BLK"%d"NOR"�j\n\n",
          local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY],
          day,local[LT_HOUR],local[LT_MIN]);
   set("long",time);
}
