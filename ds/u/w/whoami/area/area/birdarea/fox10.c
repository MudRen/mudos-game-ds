#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"fox.c";

string *exit = ({
__DIR__"fox1" ,__DIR__"fox2" ,__DIR__"fox3",
__DIR__"fox4"  ,__DIR__"fox5" ,__DIR__"fox6",
__DIR__"fox7"  ,__DIR__"fox8" ,__DIR__"fox9",
__DIR__"fox10",__DIR__"fox11",__DIR__"fox12", 
__DIR__"fox13",__DIR__"fox14",__DIR__"fox15",
__DIR__"fox16",__DIR__"fox17",__DIR__"fox18",
});

string *obj = ({
__DIR__"npc/fox2", __DIR__"npc/fox3",
__DIR__"npc/fox4",__DIR__"npc/fox5",
});

void create()
{
 set("short",HIY"����"NOR);
 set("long",(: print_fox_msg :),);

    set("objects", ([
        obj[random(sizeof(obj))] : random(2)+2,
        obj[random(sizeof(obj))] : random(2),
    ]));
 set("no_clean_up", 0); 
 set("no_map",1);
 set("no_recall",1);
 set("no_horse_member",1);
 setup();
}           
void init()
{
  object me; 
  me=this_player();      
  if(interactive(me)) {
  call_out("open",3);
  }
          message_vision(HIC"�}�}��{���ﭱ�Ө�, ��$N�P��Q�����ΪA..\n"NOR,this_player());
          this_player()->receive_damage("hp",10+random(100));  
          this_player()->receive_damage("ap",10+random(100)); 
          this_player()->receive_damage("mp",10+random(100)); 
}
void open()
{
    set("exits", ([
        "south" : exit[random(sizeof(exit))],
        "north" : exit[random(sizeof(exit))],
        "east"  : exit[random(sizeof(exit))],
        "west"  : exit[random(sizeof(exit))], 
        "southeast" : exit[random(sizeof(exit))],
        "southwest" : exit[random(sizeof(exit))],
        "northeast" : exit[random(sizeof(exit))],
        "northwest" : exit[random(sizeof(exit))],
    ]));
}
int valid_leave(object me, string dir)
{
   me = this_player();

  
     if (present("fox",environment(me)) && 
     ((dir=="north" || dir=="south" || dir=="east" || dir=="west" 
    || dir=="northwest"  || dir=="northeast"  || dir=="southwest" || dir=="southeast")))
       {
        message_vision(HIY"�@�s���W�b$N���e$N�ٷQ�h���H�I\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

