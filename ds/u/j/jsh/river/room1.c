#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���۪�");
        set("long", @LONG
none
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"room2",
  //"out"   : __DIR__"empty_room", 
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard":2,
]));
        set("outdoors","land");

        setup();
} 
/*****************************
int init()
{
    add_action("do_out","o");
} 
int do_out(string arg)
{
    object me=this_player();
    message_vision(HIG"\n�y�ڡI�I�I�z"+HIW"�uť��"+me->name(1)+"�j�n�����q�I�I\n"NOR,users(),me);
    me->move(__DIR__"empty_room");  
    call_out("shown",3,me);
    return 1;
}

void shown()
{
    object me=this_player();
    message_vision(HIW"\n�y�I�I�I�I�z���@�n�A�������L�b�¤Ѽӥ~�I\n"NOR,users(),me); 
    me->move("/open/world1/tmr/area/street4");
    me->die();  
    tell_object(me,"�A�����a�L�b�Ŧa�W�C\n");
    tell_room(environment(me),me->query("name")+"�~�۩��M�L�b�A���e�C\n",me);
    return;
} 
****************************/
