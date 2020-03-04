// Room: /u/a/acme/area/backyard.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "��|");
        set("long", @LONG
�o�̬O�p�Ϋ�誺�|�l�A�|�l�̾i�F�h���n�l�A�|�l����O���p�ˡA
��������b���~�ۦ窫�A�������ӯ�o�h�ɪ��j���A�j���|�P�]�w�G���F
���áC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hunter",
]));
    set("objects",([
       __DIR__"npc/woman2" : 2,
       __DIR__"npc/duck" : 4,
   ]) );
    set("item_desc", ([ /* sizeof() == 1 */
          "east" : (: look_door,     "east" :),
]));
    set("item_desc", ([ /* sizeof() == 1 */
     "�j��" : "�o�ӥj���ᬰ�}�¡A���U�@�ݫo���O�ܲ`�A�Y�A���i��A�i�յ�"+HIW+"���U���C\n"NOR,
    ]));
        set("no_clean_up", 0);
    set("outdoors","land");
        setup();
create_door("east", "���", "west", DOOR_CLOSED);
}
void init()
{
        add_action("do_jumpdown","jumpdown");
        add_action("do_jump","jump");
}
int do_jumpdown(string arg)
{
        object me;
        me=this_player();
          if(arg != "�j��" && arg != "well")
        {
            notify_fail("����H\n");
            return 0;
        }
        else {
        message_vision("$N�j�s�@�n�A���j���̸��U�h�I�I\n",me);
        me->move(__DIR__"oldwell");
        return 1;
             }
}
int do_jump(string arg)
{
        object me;
        me=this_player();
          if(arg != "down �j��" && arg != "down well")
        {
            notify_fail("����H\n");
            return 0;
        }
        else {
        message_vision("$N�j�s�@�n�A���j���̸��U�h�I�I\n",me);
        me->move(__DIR__"oldwell");
        return 1;
             }
}
