#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�W��"NOR);
 set("long",@LONG
�A�@�D�W�W���~�o�{, ��ӬW���٦��@�ӯ���, �i�O�b�o��
�A�o�n�s�ۨ��l, �۷����ΪA, �O�A�Q���}�o��!
LONG
    );
 set("exits",([ "down":__DIR__"pill13",
    ]));
 set("item_desc",([
        "����":"�A�o�{�o�O�@����������, �ӥB͢�����V���@������, �A�i�H�⥦��(take)�U��.\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();               
}
void init()
{
        add_action("do_take","take");
}
int k=1;
int do_take(string arg)
{
      object me,p;
      me=this_player();
      if (arg != "����") return 0;
      message_vision("$N�}�l�Ҽ{�n���n���U����\n"  ,me);
if(k != 0){
           message_vision(HIY"$N�רs�٬O�ⶵ�害�F�U��!\n"NOR ,me);
           k = 0;
        p=new(__DIR__"npc/eq/sky_neck.c");
        p->move(this_player());
        } else
        {
                message_vision("$N�Q�F�@�Q, �٬O���n�n�F....\n",me);
        }                               
        return 1;
}