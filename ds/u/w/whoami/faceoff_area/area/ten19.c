#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�w��");

 set("long",@LONG
�o�̬O�s�뤤�g�ꮳ�Ӧ��÷m�쪺�]�����a��, ���M�~��
�u�Ƭ۷��Y�K, ���O�̭��ˬO�S������u��, �A�ݤF�@��, �u
���̭����@�ӼХܵ� ����[ ���[�l, �ݨӳo�̬O�g�ꪺ����
��.
LONG
    );
 set("exits",([ "out":__DIR__"ten18",
    ]));
 set("item_desc",([
        "����[" : "�A�]�\\�i�H�q�̭��j�X�@�Ǩ���!\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

void init()
{
        add_action("do_search","search");
}
int k=1;
int do_search(string arg)
{
      object me,p;
      me=this_player();
      if (arg != "����[") return 0;
      message_vision("$N�J�Ӫ��j�F�j�@����[....\n"  ,me);
if(k != 0){
           message_vision(HIY"$N�j�X�@��֥�!\n"NOR ,me);
           k = 0;
        p=new(__DIR__"npc/eq/fur_armor.c");
        p->move(this_player());
        } else
        {
                message_vision("���O����]�S��....\n",me);
        }                               
        return 1;
}