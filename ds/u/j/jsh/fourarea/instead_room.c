#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "�񤧩�");
        set("long", @LONG
test
LONG
        );

        set("item_desc",([
        "����":"�@���j�Ѫ�����A�W�����л\�����������g�A�ݨӦ~�N�[���C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "home" : "/u/m/moonhide/workroom",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_instead","instead");
}

int do_instead(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="tear to mirror") return notify_fail("�A�n�Ӥ���?\n");
        if(!objectp(tear=present("ice of tear",me) ) )
                return notify_fail("�A�n���������l ? \n");
        message_vision(HIC"$N�N�⤤���B���\��\�V����A�@�}�ť��g�X�A���V����C\n",me);
     message_vision(HIY"�ť����ߨ�ѻڡA�򦨤@�b�뫬�A�t�U�M��$N� . .�I�I\n" NOR,me);
        me->start_busy(5);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"�A���b�뤧�����e�C\n");
        me->move(__DIR__"����.c");
     tell_room(environment(me),me->query("name")+"���M���b�A�����e�C\n",me);
        return;
}

