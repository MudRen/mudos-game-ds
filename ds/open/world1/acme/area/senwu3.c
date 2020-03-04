// Room: /open/world1/acme/area/senwu3.c
inherit ROOM;

void create()
{
        set("short", "�U�F�x");
        set("long", @LONG
�b�o�س����ͳJ���a��A�����H�[�F�o�Ӥj�F�x�A�b�F�x�|��A
�U���ۡu���v�B�u���v�B�u�šv�B�u��v�|�⪺�ܺX�A�b�F�x���ߡA
�|�����x�A�q���x�W�ǨӰ}�}�����A���O�����]���ɵM�A�o�O�B���J
��P�K�ɴ��X���]��C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"senwu2",
]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}
void init()
{
         add_action("do_climb","climb");
}
int do_climb(string arg)
{
          object me;
          me=this_player();
          if(arg != "���x") return notify_fail("�A�n������H\n");
        if( me->is_busy() ) return notify_fail("�A�����ۡA�S�k�l���o�ʧ@�C\n");
            message_vision("$N��}�åΪ����W���x�C\n",me);
            me->move(__DIR__"senwu4");
          tell_room(environment(me),me->query("name")+"���F�W�ӡC\n",me );
     return 1;
}
