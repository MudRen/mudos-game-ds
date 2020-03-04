#include <room.h>
#include <ansi.h>
inherit ROOM;

int doorOpen=0;
int buttonAppear=0;

void create()
{
set("short",HIR"�A��s�y��"NOR);
set("long", @LONG
�o�̦��۶äC�K�V���ͪ��A��²�檺�]���������A���H����������
��C�o�̦��@�i������i��(sign)�C
LONG
);
set("no_recall",1);
set("light",0);
set("no_map",1);

set("item_desc", ([
"sign":"�W���g��:\n\n"HIR"!!!  ��  �E �L �E �j  !!!\n\n\n"NOR,
"wall":"�@���q���媺��C\n"NOR,
]));

set("exits", ([
"up": "/u/g/genius/roomenter.c",
      "cold": "/open/world1/tmr/bagi/ghat9.c",
      "dab": "/open/world1/tmr/area/wa8",
      "dra": "/open/world1/wilfred/sand/room90",
]));


      set("objects",([
      "/u/g/genius/area/npc/beetleguard" : 1,
      "/open/world1/acme/area/npc/woodman" : 3,
      ]));
      setup();
}

void init()
{
        add_action("do_touch","touch");
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me;
        int tempI;
        me=this_player();
        tempI=random(9);
        if( me->is_busy() ) {return 0;}
        if(!arg || arg!="wall") return 0;
        if(tempI<=3)
        {
        write("�A�J�Ӭ�s�o����A�o�{�@�Ӿ��s(button)�C�i�H������(touch)�C\n");
        set("item_desc/button", "�o�O�@�ӤK���Ϊ����s\n") ;
        buttonAppear=1;
        }
        else
        {
        message_vision("$N�b����W��F�S��A����]�S�o�{\n",me);
        me->start_busy(2);
        }
        return 1 ;
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if( me->is_busy() ) {return 0;} 
        if(!arg || arg!="button" ||buttonAppear=0) return 0;
        message_vision("$N���U�F���s�C\n",me);
        if(!doorOpen)
        {
        message_vision("������������M���J�a���A$N�����e�X�{�F�@�ӥX�f�I\n",me);
        set ("exits/enter","/u/g/genius/area/firstroom",);
        doorOpen=1;
        }
        else
        {
        message_vision("������ʤf�ɤW�@���۾��A�N$N���e���X�f����F�C\n",me);
        delete ("exits/enter");
        doorOpen=0;
        }
        return 1;        
}

