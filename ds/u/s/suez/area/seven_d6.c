
inherit ROOM;

void create()
{
 set("short","草叢");
        set("long",
"讓人分不清方向的雜草叢。\n"
        );
        
        set("outdoors","land");
        
        setup();


 }
void init()
{
        add_action("do_search", "search");
}
int do_search(object me,string arg)
{ 
   if (arg != "雜草叢" && arg !="雜草")     return 0;
   else{
  message_vision( "$N突然發現不遠處好像有些什麼東西，便朝那個方向走去。\n\n"  ,me);
  me->move(__DIR__"seven_d7");
  return 1;
  }
}