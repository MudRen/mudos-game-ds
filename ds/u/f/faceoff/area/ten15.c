#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���V");

 set("long",@LONG
�o�̴N�O�[�t���W�����V, �A�|�ؤ@��, �Ū��O��, ��
�O���U���F�_�A�L, ����۷���R, ��b�s�W�����Q�b��뤧�]
�K�������諸��o�̨ӽͱ�, �[�Ӥ[���N�������X�W�F, �o�̪�
�a�դw�g��䥦���s�C�F�ܦh, �ϧA�i�H�ܲM�����[��쩳�U�y
�������@�|�@��.
LONG
    );
 set("exits",([ "southeast":__DIR__"ten14",
    ]));
 set("item_desc",([
        "�F�_�A�L":"�@����o�o���˪L, �O�A���Q�q�o���U�h(jump down)���İ�!.\n"
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                     
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me=this_player();
      if (arg != "down") return 0;
      message_vision("$N�����������V�U���h!!\n"  ,me);
      me->move( "/u/u/uchimaha/area/birdarea/village17");   
      return 1;
      }