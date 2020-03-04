#include <ansi.h>
#include <room.h>
inherit ROOM;

string *areas = ({
   "/open/world1/acme/area/",
   "/open/world1/tmr/area/",
   "/open/world1/whoami/birdarea/",
   "/open/world1/wu_sha_town/"
});

string pace()
{
   string dir,*file;
   dir = areas[random(sizeof(areas))];
   file = get_dir(dir);
   return dir + file[random(sizeof(file))];
}

void create()
{
   set("short",HIW+BLK"�c�f�g�h�i"NOR);
   set("long",
WHT"\n�i�i�i�i�i"NOR+RED"�i�i�i�i�i"YEL"�i�i�i�i�i"BLU"�i�i�i�i�i\n"
HIW"�i�i�i�i�i"HIR"�i�i�i�i�i"HIY"�i�i�i�i�i"HIB"�i�i�i�i�i\n"
BLK"�i�i�i�i�i"HIM"�i�i�i�i�i"HIG"�i�i�i�i�i"HIC"�i�i�i�i�i\n\n"NOR);
   set("no_clean_up",0);
   set("light",1);               
   set("exits", ([
       "west" : __DIR__"workroom",]));
   set("valid_startroom", 1);
   setup();
}

void init()
{
   object me = this_player();

   if(geteuid(me) != "www")
   {
       string pace = pace();

       if(!load_object(pace))
       {
          me->move("/u/w/www/workroom");
          return;
       }
       tell_room(pace,me->name()+"���W�䧮�����즹�a�C\n");
       message_vision(HIR"\n\n[$N���W�䧮������ "NOR+pace->query("short")+HIR"]\n\n"NOR,me);
       me->move(pace);
   }
}
