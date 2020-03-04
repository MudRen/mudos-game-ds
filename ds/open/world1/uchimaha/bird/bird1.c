#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�Ө�@�B�k�����U, �A���Y���ѤW��, �p�����F
���d���W, �A��b�L�k�β����X�o�Ӯk���쩳���h��, 
���p�A�ۻ{���ۤv���\����, �A�N�W�h�ݬݧa, �b�o��
�䦳�@�ӥ���(rock), �W�����G��ۤ@�Ǧr....���M�A
ť��k�����W���H�b���S, ��O�A�M�w�W�h�ݬ�....

LONG
    );
 set("item_desc",([
        "rock":"�A�³o�����ݤF��, �o�{�W�����|�Ӧ�����j�r,\n
          "HIR"��  �@  �k  ��"NOR"\n
     �A���T�Q���Ѭݬݼg�o�Ӧr���D�H.\n",
     ]));
 set("exits",(["south":__DIR__"en45",
     ]));
 set("no_clean_up", 0);
 set("outdoors","land");
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
        if (arg != "���@�k��") return 0;
        
        message_vision("�u��$N��B���åΡA�C�C�a���W�F�k���C\n" ,me);
        me->move(__DIR__"bird2.c");
        tell_room(environment(me),me->query("name")+"��ݼN�N�a���F�W�ӡCn",me);
        return 1;
}          
