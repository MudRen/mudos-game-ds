#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��F");

 set("long",@LONG
�A�{�b���Ѥѥj�쪺��K�W, �A��F�@��|�P, ���M����
�i����Q�U�j�s�����_�ٮp,�i�����쪺���ׯu�O�ūe����ӥB
�A�}�U����F�j�����Q�H���ꪺ�e��,�A�A�V��ݤF�@�ݵo�{�A
�}�U���\�h�����L, �åB���q�V�A�F�䪺��}����, ���ۧA�S�o
�{�a�W���\�h���Ϊ�����, �ݨӤ��ΰߤ@�������ҥu�����Ӿ�
�}�F.......
LONG
    );
 set("exits",([ "down":__DIR__"tree9",
                  "west":__DIR__"tree_2F1",
    ]));


 set("no_clean_up", 0);
set("objects", ([__DIR__"npc/crow" : 4
    ]));

 setup();

}

void init()
{
        add_action("do_search","search");
       add_action("do_enter","enter");
}
int k=1;


int do_search(string arg)
{



      object me;
      object p;
        me=this_player();
 
       if (arg != "��}") return 0;

        message_vision("$N����b��}���N�F�@�N.....\n"  ,me);

    if(k != 0){
   	   message_vision("$N�q��}���N�X�@���p���ΡI�I\n" ,me);
	   k = 0;



       p=new(__DIR__"obj/green_worm.c");

	p->move(this_player());


	} else
	{
        message_vision("$N�N�F�@�N�A�o�N��N����\\����]�N���X�ӧ�.....:P\n",me);
 	}				
        return 1;
}

int do_enter(string arg)
{        object me;
        me=this_player();
       if (arg != "��}") return 0;

        message_vision("$N���G�ƤF, �ϺɤF�Y�����O��Q�n���i�@�ӥu���L��x�j����}......\n"  ,me);

}

