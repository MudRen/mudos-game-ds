
inherit ROOM;

void create()
{
 set("short","���O");
        set("long",
"���H�����M��V�������O�C\n"
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
   if (arg != "�����O" && arg !="����")     return 0;
   else{
  message_vision( "$N��M�o�{�����B�n�����Ǥ���F��A�K�¨��Ӥ�V���h�C\n\n"  ,me);
  me->move(__DIR__"seven_d7");
  return 1;
  }
}